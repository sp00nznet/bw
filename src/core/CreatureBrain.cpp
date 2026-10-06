// CreatureBrain — see black/CreatureBrain.h.
#include <black/CreatureBrain.h>

#include <black/Creature.h>
#include <black/CreatureBeliefAttributes.h>
#include <black/CreatureActionValidity.h>
#include <black/CreatureOpinion.h>
#include <black/FishFarm.h>
#include <black/Object.h>
#include <black/Villager.h>
#include <black/types.h>

#include <algorithm>

namespace creature {

CREATURE_BELIEF_KIND BeliefKindOfType(uint32_t type) {
    switch (type) {  // sub_4B8FF0
    case 0:  return CREATURE_BELIEF_TOWN;
    case 1:  return CREATURE_BELIEF_FOREST;
    case 2:  return CREATURE_BELIEF_CITADEL;
    case 3:  return CREATURE_BELIEF_ABODE;
    case 6:  return CREATURE_BELIEF_VILLAGER;
    case 8:  return CREATURE_BELIEF_CREATURE;
    case 20: return CREATURE_BELIEF_CONTEXT;
    case 22: return CREATURE_BELIEF_FLOCK;
    default: return CREATURE_BELIEF_BASE;  // CreatureBeliefSmall
    }
}

namespace {

// ponytail: a creature walks a metre a turn (10 m/s at 10 Hz is BW's tick); the
// species' real speed lives in its info record and is not mapped yet.
constexpr int kWalkSpeed = static_cast<int>(kMapUnitsPerMetre);

bool IsEating(uint32_t action) { return action == 11 || action == 12; }  // EatAlive, EatAfterExamining

}  // namespace

bool IsFishing(uint32_t action) { return action == 29 || action == 155 || action == 259 || action == 300; }

namespace {

}  // namespace

bool CreatureBrain::Init(Creature* creature, const CreatureMind& m, uint32_t species) {
    creature_ = creature;
    if (!tables_.Load(species)) return false;
    BindKnownActions(&host_, m);
    BindObjectPredicates(&host_, creature, [this](uint32_t id) -> GameThingWithPos* {
        return id < objects_.size() ? objects_[id] : nullptr;
    });
    // Action validity (action +16): creature methods, translated one by one.
    // An untranslated one answers no, so the creature never does what the
    // binary might have ruled out.
    for (uint32_t s : m.known_spells) if (s < 42) facts.knows_spell[s] = true;
    host_.action_valid = [this](uint32_t action, const ActionPlan& plan) {
        return ActionValid(action, tables_.actions[action].spell, plan, facts);
    };
    host_.opinion = [this](uint32_t id, uint32_t desire) {
        for (const BeliefView& b : beliefs_) if (b.id == id) return Opinion(desire, b);
        return 0.0f;
    };
    // The opinion trees: each desire's second learned tree, split by the kind
    // of belief each episode was about. ponytail: the binary keeps one tree per
    // desire over the global attribute ids, so episodes of different kinds
    // share it; the shipped minds have one episode, so the split changes nothing.
    for (uint32_t d = 0; d < kNumCreatureDesires; ++d) {
        std::vector<LearningEpisode> by_kind[_CREATURE_BELIEF_KIND_COUNT];
        for (const MindEpisode& e : m.learning[d][1].episodes) {
            LearningEpisode le;
            for (size_t i = 0; i < e.attributes.size() && i < kMaxBeliefAttributes; ++i)
                le.features[i] = static_cast<uint8_t>(e.attributes[i]);
            le.weight = e.weight;
            by_kind[BeliefKindOfType(e.belief_type)].push_back(le);
        }
        for (int k = 0; k < _CREATURE_BELIEF_KIND_COUNT; ++k)
            if (!by_kind[k].empty())
                trees_[d][k].Induce(static_cast<CREATURE_BELIEF_KIND>(k), by_kind[k].data(),
                                    static_cast<uint32_t>(by_kind[k].size()));
    }
    return true;
}

uint32_t CreatureBrain::IdOf(Object* o) {
    auto it = ids_.find(o);
    if (it != ids_.end()) return it->second;
    const uint32_t id = static_cast<uint32_t>(objects_.size());
    objects_.push_back(o);
    ids_[o] = id;
    return id;
}

Object* CreatureBrain::Target() const {
    const ActionPlan* p = agenda.plans.For(agenda.plans.current_desire);
    Object* t = p && p->belief < objects_.size() ? objects_[p->belief] : nullptr;
    // The fishing actions are planned on the creature itself; their handler
    // goes to the fish farm their validity test found (sub_503770, nearest).
    if (t == creature_ && IsFishing(Action())) return NearestFishFarm();
    return t;
}

Object* CreatureBrain::NearestFishFarm() const {
    Object* best = nullptr;
    float best_d = 600.0f;
    for (Object* o : seen_) {
        if (!dynamic_cast<FishFarm*>(o)) continue;
        const float d = MetresOf(1) * creature_->GetDistanceFromObject(o->coords);
        if (d < best_d) { best_d = d; best = o; }
    }
    return best;
}

// sub_4B83C0: the level of the leaf the belief reaches in the desire's tree.
// An empty tree is neutral (0).
float CreatureBrain::Opinion(uint32_t desire, const BeliefView& b) const {
    if (desire >= kNumCreatureDesires || b.id >= objects_.size()) return 0.0f;
    const CREATURE_BELIEF_KIND kind = BeliefKindOfType(b.type);
    const DecisionTreeModel& tree = trees_[desire][kind];
    if (tree.nodes.empty()) return 0.0f;
    uint8_t features[kMaxBeliefAttributes] = {};
    const uint32_t n = DescribeObject(kind, objects_[b.id], creature_, features, kMaxBeliefAttributes);
    return OpinionValue(tree.Classify(features, n));
}

bool CreatureBrain::Tick(const std::vector<Object*>& objects) {
    // Perception: everything within the chooser's reach, plus the creature itself.
    seen_ = objects;
    beliefs_.clear();
    BeliefView self;
    self.id = IdOf(creature_);
    self.type = 8;
    self.self = true;
    beliefs_.push_back(self);
    for (Object* o : objects) {
        if (!o || o == creature_) continue;
        if (Living* l = dynamic_cast<Living*>(o); l && l->IsDead()) continue;
        const float d = MetresOf(1) * creature_->GetDistanceFromObject(o->coords);
        if (d > tables_.max_distance) continue;
        BeliefView b;
        b.id = IdOf(o);
        b.distance = d;
        b.type = o->GetCreatureBeliefType();
        beliefs_.push_back(b);
    }

    // The facts the validity predicates read, as far as the world here has them.
    facts.life = creature_->GetLife();
    facts.has_player = creature_->owner != nullptr;
    facts.home_distance = MetresOf(1) * creature_->GetDistanceFromObject(creature_->field_0x1200);
    facts.stage = static_cast<uint32_t>(creature_->field_0x1268);
    facts.home_built = creature_->field_0x11fc != 0;
    facts.home_progress = creature_->field_0x1210;
    facts.fish_farm_near = NearestFishFarm() != nullptr;
    facts.turn = turn_;
    std::copy(std::begin(mind.desire), std::end(mind.desire), facts.desire);
    std::copy(std::begin(mind.action_count), std::end(mind.action_count), facts.action_count);
    ++turn_;

    PlanChooser chooser(tables_, mind, host_, beliefs_);
    agenda.Tick(chooser, mind, host_);

    // Carry out the current plan: walk to what it is about.
    Object* target = Target();
    const uint32_t action = Action();
    if (!target || !action) return false;
    // mental+118432: the turns spent on each action, which the familiarity
    // bonus (sub_4D0D70) and the recent-action tests (sub_4B6690) read. That it
    // counts turns of the action under way is inferred from those readers.
    ++mind.action_count[action];
    if (target != creature_) {
        if (creature_->goal != target->coords) creature_->SetGoalPos(target->coords);
        if (creature_->speed == 0) creature_->SetSpeed(kWalkSpeed);
        creature_->MoveToGoal();
        if (creature_->move_state != MOVE_TO_STATES_ARRIVED) return false;
    }

    // Arrived: the action is done (ours -- see the header).
    if (IsEating(action)) {
        if (Villager* v = dynamic_cast<Villager*>(target)) v->SetTopState(VILLAGER_STATE_DYING);
    }
    const uint32_t served = agenda.plans.current_desire;
    if (served < kNumCreatureDesires) mind.desire[served] = std::max(0.0f, mind.desire[served] - 0.5f);
    last_action = action;
    last_target = target;
    ++completed;
    agenda.plans.current_desire = kNumCreatureDesires;  // nothing current: the next plan takes over
    agenda.plans.current_action = 0;
    agenda.current_total = 0.0f;
    creature_->SetSpeed(0);
    return true;
}

}  // namespace creature
