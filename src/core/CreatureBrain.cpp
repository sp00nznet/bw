// CreatureBrain — see black/CreatureBrain.h.
#include <black/CreatureBrain.h>

#include <black/Creature.h>
#include <black/CreatureBeliefAttributes.h>
#include <black/CreatureActionValidity.h>
#include <black/CreatureOpinion.h>
#include <black/FishFarm.h>
#include <black/Map.h>
#include <black/Object.h>
#include <black/Villager.h>
#include <black/types.h>

#include <algorithm>
#include <memory>
#include <cstring>

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

}  // namespace

bool IsFishing(uint32_t action) { return action == 29 || action == 155 || action == 259 || action == 300; }

namespace {

}  // namespace

bool CreatureBrain::Init(Creature* creature, const CreatureMind& m, uint32_t species) {
    return Init(creature, &m, species);
}

// A fresh mind (no file): the species' desire tables, a new body, nothing
// learned and nothing known about. v1.0's creature learns its abilities by
// watching (sub_4C3AD0); only a fight (sub_464C10) or a script (sub_68DD20)
// grants them all (sub_4635C0).
bool CreatureBrain::Init(Creature* creature, uint32_t species) { return Init(creature, nullptr, species); }

bool CreatureBrain::Init(Creature* creature, const CreatureMind* saved, uint32_t species) {
    static const CreatureMind kFresh;
    const CreatureMind& m = saved ? *saved : kFresh;
    creature_ = creature;
    if (!tables_.Load(species) || !body_info.Load(species) || !desires.Init(species, saved)) return false;
    body.Init(body_info);
    if (m.has_body) {  // the saved body (sub_4CA040)
        body.turn = m.body.turn;
        body.age = m.body.age;
        body.reserve = m.body.reserve;
        body.reserve_max = m.body.reserve_max;
        body.energy = m.body.energy;
        body.poo = m.body.poo;
        body.exhaustion = m.body.exhaustion;
        body.dehydration = m.body.dehydration;
        body.strength = m.body.strength;
        body.growth = m.body.growth;
    }
    if (saved) creature->field_0x1268 = static_cast<int>(m.stage);
    known_[0] = m.known_abilities;
    known_[1] = m.known_spells;
    host_.has = [this](int kind, uint32_t id) { return Knows(kind, id); };
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
    // PointAtHand (169) has no validity test in v1.0, where a creature always
    // has a player's hand to point at. Without a player its handler fails
    // every turn (sub_4977F0), so it is ruled out here instead.
    // PointAtCamera (168) likewise always has the game's camera in v1.0.
    host_.action_possible = [this](uint32_t action) {
        return (action != 169 || facts.has_player) && (action != 168 || camera.has_value());
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

// sub_4C3F50: whether the mind's list (kind 0 abilities, 1 magic types) has it.
bool CreatureBrain::Knows(int kind, uint32_t id) const {
    const std::vector<uint32_t>& v = known_[kind ? 1 : 0];
    return std::find(v.begin(), v.end(), id) != v.end();
}

// sub_4C3F80: onto the list, once.
void CreatureBrain::Learn(int kind, uint32_t id) {
    if (Knows(kind, id)) return;
    known_[kind ? 1 : 0].push_back(id);
    if (kind && id < 42) facts.knows_spell[id] = true;
}

// sub_68F310's two loops: abilities 0..5, magic types 0..41. sub_4635C0
// (CREATURE_LEARN_EVERYTHING, a fight) is both.
void CreatureBrain::LearnEverything(bool abilities, bool spells) {
    if (abilities) for (uint32_t i = 0; i < 6; ++i) Learn(0, i);
    if (spells) for (uint32_t i = 0; i < 42; ++i) Learn(1, i);
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

// The source value functions this world can answer (the first column of the
// per-source table at 0xBAE7D8, recovered by emulating its initialiser).
bool CreatureBrain::SourceValue(uint32_t type, float* out) const {
    auto clamp01 = [](float v) { return std::clamp(v, 0.0f, 1.0f); };
    switch (type) {
    case 14: *out = 1.0f - body.energy; return true;                   // HUNGER_FROM_ENERGY, sub_4C0840
    case 21: *out = body.poo; return true;                             // TO_POO, sub_4C08A0
    case 22: *out = body.exhaustion; return true;                      // TIREDNESS_FROM_EXHAUSTION, sub_4C08C0
    case 32: *out = body.dehydration; return true;                     // FOR_WATER, sub_4C0900
    case 33: *out = 1.0f - creature_->GetLife(); return true;          // TO_RESTORE_HEALTH, sub_4C0920
    case 40: *out = clamp01(-body.temperature); return true;           // TO_GET_WARMER, sub_4C0B30
    case 41: *out = clamp01(body.temperature); return true;            // TO_GET_COLDER, sub_4C0B70
    case 17: case 24: *out = facts.night ? 1.0f : 0.0f; return true;   // darkness, night (sub_4C08D0)
    case 10: case 16: case 25:                                         // ...FROM_SADNESS, sub_4C0930
        for (const auto& list : desires.sources)
            for (const DesireSourceSlot& s : list)
                if (s.type == 48) { *out = s.value; return true; }
        *out = 0.0f;
        return true;
    default: return false;  // event-driven, or inputs not modelled here
    }
}

// The routine at 0x460020, when an action is done.
void CreatureBrain::ActionDone(uint32_t action, uint32_t served) {
    const ChooserTables::Action& a = tables_.actions[action];
    const uint32_t stage = static_cast<uint32_t>(creature_->field_0x1268);
    body.PayFor(a.cost[0], a.cost[1], a.cost[2], stage);  // sub_4CFEB0
    if (!drive_desires || served >= kNumCreatureDesires) return;
    desires.ActionDone(served, a.desire, a.done_scale, a.done_scales);
    auto hold = [&](uint32_t d, float seconds) {
        if (desires.Countdown(d, seconds)) agenda.plans.plans[d] = ActionPlan(), agenda.plans.plans[d].desire = d;
    };
    switch (served) {  // the jump table at 0x460218
    case 7: hold(7, 60.0f); break;
    case 8:  // sub_4BEAC0: tiredness falls to the weakest desire's level over 1.3
        desires.value[8] = desires.value[desires.Weakest()] / 1.3f;
        desires.Clamp(8);
        break;
    case 9: hold(9, 120.0f); break;
    case 15: creature_->life = std::min(1.0f, creature_->GetLife() + 0.5f); break;  // vslot 364 (GetLife + 0.5)
    case 17: hold(17, 60.0f); break;
    case 19: hold(19, 120.0f); break;
    case 20: hold(20, 120.0f); break;
    default: break;
    }
    for (uint32_t d = 0; d < kNumCreatureDesires; ++d) mind.desire[d] = desires.value[d];
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

    // The body, then the desires it feeds (Creature vslot 392: sub_4CF980,
    // then sub_4BE5B0).
    CreatureBody::Context bc;
    bc.stage = static_cast<uint32_t>(creature_->field_0x1268);
    bc.moving = creature_->speed != 0 && creature_->move_state != MOVE_TO_STATES_ARRIVED;  // stands in for sub_46CB80
    bc.current_action = Action();
    body.Tick(body_info, bc);
    if (drive_desires) {
        desires.Tick([this](uint32_t type, float* v) { return SourceValue(type, v); });
        for (uint32_t d = 0; d < kNumCreatureDesires; ++d) {
            mind.desire[d] = desires.value[d];
            mind.active[d] = desires.active[d];
        }
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

    // Carry out the current plan. A plan that has just become current runs
    // its action's handler (sub_4D15E0 -> sub_4B6CA0), which queues the
    // sub-actions; where that handler is translated, they do the work.
    Object* target = Target();
    const uint32_t action = Action();
    if (action != running_) {
        if (running_) Override(running_);
        running_ = action;
        if (HasSubActions(action) && !StartAction(action)) return false;  // it stopped
    }
    if (!target || !action) return false;
    // mental+118432: the turns spent on each action, which the familiarity
    // bonus (sub_4D0D70) and the recent-action tests (sub_4B6690) read. That it
    // counts turns of the action under way is inferred from those readers.
    ++mind.action_count[action];
    if (HasSubActions(action)) {
        const uint32_t before = completed;
        RunSubActions();
        return completed != before;
    }
    if (target != creature_) {
        if (creature_->goal != target->coords) creature_->SetGoalPos(target->coords);
        if (creature_->speed == 0) creature_->SetSpeed(kWalkSpeed);
        creature_->MoveToGoal();
        if (creature_->move_state != MOVE_TO_STATES_ARRIVED) return false;
    }

    // Arrived. ponytail: an action whose handler is not translated is done
    // on arrival (its sub-actions are not run).
    const uint32_t served = agenda.plans.current_desire;
    ActionDone(action, served);
    last_action = action;
    last_desire = served;
    last_target = target;
    ++completed;
    // The plan is spent: its slot scores nothing until the queue rebuilds it,
    // so the agenda moves on (ours -- the original's actions take time, so a
    // finished plan's slot has long been rebuilt by then).
    if (served < kNumCreatureDesires) agenda.plans.plans[served].total = 0.0f;
    agenda.plans.current_desire = kNumCreatureDesires;  // nothing current: the next plan takes over
    agenda.plans.current_action = 0;
    agenda.current_total = 0.0f;
    creature_->SetSpeed(0);
    return true;
}

namespace {
std::unordered_map<const Creature*, std::unique_ptr<CreatureBrain>>& Brains() {
    static std::unordered_map<const Creature*, std::unique_ptr<CreatureBrain>> b;
    return b;
}
}  // namespace

CreatureBrain* AttachBrain(Creature* c, const CreatureMind* mind, uint32_t species) {
    auto b = std::make_unique<CreatureBrain>();
    if (!c || !b->Init(c, mind, species)) return nullptr;
    return (Brains()[c] = std::move(b)).get();
}

CreatureBrain* AttachBrain(Creature* c, const CreatureMind& mind, uint32_t species) { return AttachBrain(c, &mind, species); }

CreatureBrain* BrainOf(const Creature* c) {
    auto it = Brains().find(c);
    return it == Brains().end() ? nullptr : it->second.get();
}

bool TickBrain(Creature* c) {
    CreatureBrain* b = BrainOf(c);
    if (!b) return false;
    std::vector<Object*> near;
    ObjectsNear(c->coords, 600.0f, near);
    b->Tick(near);
    return true;
}

}  // namespace creature
