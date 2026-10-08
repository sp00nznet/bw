// CreatureBrain — see black/CreatureBrain.h.
#include <black/CreatureBrain.h>

#include <black/Creature.h>
#include <black/CreatureBeliefAttributes.h>
#include <black/CreatureActionValidity.h>
#include <black/CreatureOpinion.h>
#include <black/FishFarm.h>
#include <black/InfoDat.h>
#include <black/Map.h>
#include <black/Object.h>
#include <black/Player.h>
#include <black/Villager.h>
#include <black/types.h>

#include <algorithm>
#include <cmath>
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
// A fresh mind's desires are those of the creature's stage (a new one's is 0),
// as v1.0 sets them for a new player creature (sub_5EDB70 -> sub_4ACB00(0)).

bool CreatureBrain::Init(Creature* creature, const CreatureMind* saved, uint32_t species) {
    static const CreatureMind kFresh;
    const CreatureMind& m = saved ? *saved : kFresh;
    creature_ = creature;
    species_ = species;
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
    // has a player's hand to point at. Without one its handler fails every
    // turn (sub_4977F0), so it is ruled out here instead.
    // PointAtCamera (168) likewise always has the game's camera in v1.0.
    host_.action_possible = [this](uint32_t action) {
        return (action != 169 || (facts.has_player && player_hand)) && (action != 168 || camera.has_value());
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
        bool kinds[_CREATURE_BELIEF_KIND_COUNT] = {};
        for (const MindEpisode& e : m.learning[d][1].episodes) {
            Episode ep{BeliefKindOfType(e.belief_type), {}};
            for (size_t i = 0; i < e.attributes.size() && i < kMaxBeliefAttributes; ++i)
                ep.e.features[i] = static_cast<uint8_t>(e.attributes[i]);
            ep.e.weight = e.weight;
            episodes_[d].push_back(ep);
            kinds[ep.kind] = true;
        }
        for (int k = 0; k < _CREATURE_BELIEF_KIND_COUNT; ++k)
            if (kinds[k]) Reinduce(d, static_cast<CREATURE_BELIEF_KIND>(k));
    }
    if (!saved) SetDevelopmentStage(static_cast<uint32_t>(std::max(creature->field_0x1268, 0)));
    return true;
}

// A development stage's desires (DETAIL_CREATURE_DEVELOPMENT, one 132-byte
// record per stage, 0 "Initial Phase" .. 13 "Fully Mature Phase"): ten it
// switches on (+76) and four it switches off (+116); 42 is an empty slot.
// sub_4BEEA0 sets the flag (CreatureDesires +8).
void CreatureBrain::ApplyStage(uint32_t stage) {
    const auto* r = static_cast<const uint8_t*>(infodat::Element(infodat::DETAIL_CREATURE_DEVELOPMENT, stage));
    if (!r) return;
    auto at = [&](int i) { int32_t v; std::memcpy(&v, r + 4 * i, 4); return v; };
    for (int i = 19; i < 29; ++i) if (at(i) >= 0 && at(i) < static_cast<int32_t>(kNumCreatureDesires)) desires.active[at(i)] = true;
    for (int i = 29; i < 33; ++i) if (at(i) >= 0 && at(i) < static_cast<int32_t>(kNumCreatureDesires)) desires.active[at(i)] = false;
}

// sub_4ACB00: every desire off, then each stage up to this one in turn; the
// countdowns cleared (sub_4BE470) and the agenda reset (sub_4B6D60).
// ponytail: the leash reset at stage 5 (creature +4532) and +404/+4716 are
// not modelled.
void CreatureBrain::SetDevelopmentStage(uint32_t stage) {
    if (stage >= infodat::Count(infodat::DETAIL_CREATURE_DEVELOPMENT)) return;
    creature_->field_0x1268 = static_cast<int>(stage);
    std::fill(std::begin(desires.countdown), std::end(desires.countdown), 0u);
    std::fill(std::begin(desires.active), std::end(desires.active), false);
    for (uint32_t s = 0; s <= stage; ++s) ApplyStage(s);
    EndAction();
}

// SET_CREATURE_DEV_STAGE (sub_68EBD0): only that stage's switches, on top of
// what the creature has.
void CreatureBrain::EnterDevelopmentStage(uint32_t stage) {
    if (stage >= infodat::Count(infodat::DETAIL_CREATURE_DEVELOPMENT)) return;
    creature_->field_0x1268 = static_cast<int>(stage);
    std::fill(std::begin(desires.countdown), std::end(desires.countdown), 0u);
    ApplyStage(stage);
}

namespace {
// The prerequisite of each ability (kind 0) and magic type (kind 1), as a
// (kind, id) pair; kind 2 is none (0xB0DCA0, initialised data). Spells 40 and
// 41 have no entry written, so they read (0, 0): ability 0, Build.
struct Prereq { uint8_t kind, id; };
constexpr Prereq kPrereq[2][42] = {
    {{2, 0}, {2, 0}, {2, 0}, {2, 0}, {2, 0}, {2, 0}},
    {{2, 0}, {2, 0}, {1, 1}, {1, 1}, {2, 0}, {1, 4}, {1, 4}, {2, 0}, {1, 7}, {1, 8}, {2, 0}, {1, 10}, {2, 0}, {2, 0},
     {2, 0}, {2, 14}, {2, 0}, {1, 16}, {1, 17}, {2, 0}, {2, 0}, {2, 0}, {2, 0}, {2, 22}, {2, 0}, {2, 0}, {2, 0}, {2, 0},
     {2, 0}, {2, 0}, {2, 0}, {2, 0}, {2, 0}, {2, 0}, {2, 0}, {2, 0}, {2, 0}, {2, 0}, {2, 0}, {2, 0}, {0, 0}, {0, 0}},
};
template <class T> T InfoAt(infodat::Section s, uint32_t i, size_t off) {
    T v{};
    if (const auto* e = static_cast<const char*>(infodat::Element(s, i))) std::memcpy(&v, e + off, sizeof v);
    return v;
}
}  // namespace

// sub_4C3AD0. ponytail: its feedback (sub_4B0770) and the creature's
// interested look (sub_4668F0) are not modelled, nor the frozen-by-spell gate
// (mental+134372; core has no such spell), nor the +2 a spell sighting gets
// when the creature's player's +300 record is in mode 2.
bool CreatureBrain::Observe(int kind, uint32_t id) {
    if (kind < 0 || kind > 1 || id >= (kind ? 42u : 6u)) return false;
    const Prereq p = kPrereq[kind][id];
    if (p.kind != 2 && !Knows(p.kind, p.id)) return false;
    const uint32_t stage = static_cast<uint32_t>(creature_->field_0x1268);
    const uint32_t now = turn_ + 1;  // the game turn (never 0 there)
    if (kind == 0) {  // DETAIL_CREATURE_NORMAL_ACTION_KNOWN_ABOUT_TABLE
        if (stage < InfoAt<uint32_t>(infodat::DETAIL_CREATURE_NORMAL_ACTION_KNOWN_ABOUT_TABLE, id, 96)) return false;
        if (!ability_first_[id]) ability_first_[id] = now;
        // Whole seconds since it was first seen, against +88 read as a float
        // (fcomp). The shipped table holds small integers there (6, 7), so the
        // wait is any whole second: it is learned when seen again a second on.
        const float need = InfoAt<float>(infodat::DETAIL_CREATURE_NORMAL_ACTION_KNOWN_ABOUT_TABLE, id, 88);
        if (++ability_seen_[id] == 0 || static_cast<float>((now - ability_first_[id]) / 10u) < need) return false;
        Learn(0, id);
        return true;
    }
    // DETAIL_CREATURE_MAGIC_ACTION_KNOWN_ABOUT_TABLE
    if (stage < InfoAt<uint32_t>(infodat::DETAIL_CREATURE_MAGIC_ACTION_KNOWN_ABOUT_TABLE, id, 96)) return false;
    if (now - spell_last_[id] > 50 || !spell_last_[id]) ++spell_seen_[id];
    spell_last_[id] = now;
    Learn(1, id);
    // sub_4D82D0: the sightings it takes, +84 x the species' CREATURE_INFO +892.
    const float need = static_cast<float>(InfoAt<uint32_t>(infodat::DETAIL_CREATURE_MAGIC_ACTION_KNOWN_ABOUT_TABLE, id, 84)) *
                       InfoAt<float>(infodat::DETAIL_CREATURE_INFO, species_, 892);
    return need <= static_cast<float>(spell_seen_[id]);
}

// sub_4BA660, the part that learns: from stage 3, and not while it serves one
// of the desires below, a villager's state (its final state while it waits for
// an animation; GotoStoragePitForFood more than 40 m from its goal counts as
// DecideWhatToDo) names the ability it shows (VILLAGER_STATE_TABLE +240; 6 is
// none).
void CreatureBrain::WatchVillager(const Villager* v) {
    if (!v || creature_->field_0x1268 < 3 || (creature_->field_0x24 & 0x400)) return;
    switch (agenda.plans.current_desire) {
    case 0: case 1: case 2: case 3: case 4: case 5: case 7: case 8: case 11: case 14: case 15: case 16:
    case 19: case 20: case 21: case 22: case 23: case 25: case 26: case 39:
        return;
    default: break;
    }
    uint8_t state = v->action.top_state;
    if (state == VILLAGER_STATE_WAIT_FOR_ANIMATION) state = v->action.final_state;
    if (state == VILLAGER_STATE_GOTO_STORAGE_PIT_FOR_FOOD && MetresOf(1) * const_cast<Villager*>(v)->GetDistanceFromObject(v->goal) > 40.0f)
        state = VILLAGER_STATE_DECIDE_WHAT_TO_DO;
    const uint32_t ability = InfoAt<uint32_t>(infodat::DETAIL_VILLAGER_STATE_TABLE_INFO, state, 240);
    if (ability != 6 && !Knows(0, ability)) Observe(0, ability);
    // ponytail: the look it gives (sub_4AB9B0(6, 0, 79)) is not modelled.
}

void CreatureBrain::Reinduce(uint32_t desire, CREATURE_BELIEF_KIND kind) {
    std::vector<LearningEpisode> of_kind;
    for (const Episode& e : episodes_[desire]) if (e.kind == kind) of_kind.push_back(e.e);
    trees_[desire][kind] = DecisionTreeModel();
    if (!of_kind.empty()) trees_[desire][kind].Induce(kind, of_kind.data(), static_cast<uint32_t>(of_kind.size()));
}

const CreatureBrain::Remembered* CreatureBrain::Recent(uint32_t i) const {
    return i < history_count_ ? &history_[(history_head_ + 5 - 1 - i) % 5] : nullptr;
}

// sub_4D1680, as a plan becomes current (sub_4D15E0): the plan, the desire's
// strongest source (sub_4C0560: the most accumulated, else its first) and
// clones of its beliefs go on the ring.
void CreatureBrain::Remember() {
    const uint32_t d = Desire();
    if (d >= kNumCreatureDesires) return;
    uint32_t source = 61;
    float most = 0.0f;
    for (const DesireSourceSlot& s : desires.sources[d])
        if (most < s.accumulated) most = s.accumulated, source = s.type;
    if (source >= 61 && !desires.sources[d].empty()) source = desires.sources[d].front().type;
    if (source >= 61) return;
    Remembered r;
    r.desire = d;
    r.action = Action();
    r.source = source;
    r.object = Target();
    if (r.object) {
        r.kind = BeliefKindOfType(r.object->GetCreatureBeliefType());
        r.feature_count = DescribeObject(r.kind, r.object, creature_, r.features, kMaxBeliefAttributes);
    }
    history_[history_head_] = r;
    history_head_ = (history_head_ + 1) % 5;
    history_count_ = std::min(history_count_ + 1, 5u);
}

// sub_45F790: the newest record is done, at this turn, and whether a camera
// of its player's had the creature in view: the nearest within 400 whose
// field of view holds it (sub_461720). ponytail: the host gives one camera
// position and no direction, so in view means within 400 m of it.
void CreatureBrain::RememberFinished() {
    if (!history_count_) return;
    Remembered& r = history_[(history_head_ + 4) % 5];
    r.finished = true;
    r.finished_turn = turn_;
    r.seen = camera && MetresOf(1) * creature_->GetDistanceFromObject(*camera) < 400.0f;
}

// sub_4C1FF0: how likely feedback now is about this action. Only actions
// flagged for it (CREATURE_ACTION +256; 318 of 328); one under way always is;
// a finished one only if the player saw it end, fading to nothing over the
// action's window in seconds (+224).
float CreatureBrain::Relevance(const Remembered& r) const {
    if (!InfoAt<uint32_t>(infodat::DETAIL_CREATURE_ACTION, r.action, 256)) return 0.0f;
    if (!r.finished) return 1.0f;
    const float window = InfoAt<float>(infodat::DETAIL_CREATURE_ACTION, r.action, 224);
    const float since = static_cast<float>((turn_ - r.finished_turn) / 10u);  // whole seconds, as v1.0 divides
    return r.seen && since < window ? 1.0f - since / window : 0.0f;
}

// sub_4C0320: a source slot's field (0 value, 1 threshold) by source type.
float* CreatureBrain::SourceSlot(uint32_t type, size_t field) {
    for (auto& list : desires.sources)
        for (DesireSourceSlot& s : list)
            if (s.type == type) return field ? &s.threshold : &s.value;
    return nullptr;
}

// sub_4BEB30: feedback on a desire. Its cycle shortens (praise) or lengthens
// by DESIRE_TABLE +100, and every desire it depends on with it; the source's
// threshold moves by its bounds' step; its maximum by CREATURE_INFO +720
// within 0.2 of the table's; its completions-per-reset by +120/3 when +124 is
// set; its decay by a thousandth.
void CreatureBrain::FeedbackDesire(uint32_t d, uint32_t source, float a) {
    using infodat::DETAIL_CREATURE_DESIRE_TABLE;
    if (!desires.active[d]) return;
    const float lo = InfoAt<float>(infodat::DETAIL_CREATURE_INFO, species_, 636);
    const float hi = InfoAt<float>(infodat::DETAIL_CREATURE_INFO, species_, 640);
    const float f = (1.0f / InfoAt<float>(DETAIL_CREATURE_DESIRE_TABLE, d, 100) - 1.0f) * a + 1.0f;
    desires.cycle[d] = std::clamp(f * desires.cycle[d], lo, hi);
    if (float* t = SourceSlot(source, 1)) {
        using infodat::DETAIL_CREATURE_DESIRE_SOURCE_THRESHOLD_BOUNDS;
        *t = std::clamp(*t - InfoAt<float>(DETAIL_CREATURE_DESIRE_SOURCE_THRESHOLD_BOUNDS, source, 24) * a,
                        InfoAt<float>(DETAIL_CREATURE_DESIRE_SOURCE_THRESHOLD_BOUNDS, source, 16),
                        InfoAt<float>(DETAIL_CREATURE_DESIRE_SOURCE_THRESHOLD_BOUNDS, source, 20));
    }
    const float base = InfoAt<float>(DETAIL_CREATURE_DESIRE_TABLE, d, 0x4C);
    desires.max_value[d] = std::clamp(desires.max_value[d] + InfoAt<float>(infodat::DETAIL_CREATURE_INFO, species_, 720) * a,
                                      std::max(base - 0.2f, 0.0f), std::min(base + 0.2f, 2.0f));
    if (InfoAt<uint32_t>(DETAIL_CREATURE_DESIRE_TABLE, d, 0x7C))
        desires.done_period[d] = std::clamp(desires.done_period[d] + InfoAt<float>(DETAIL_CREATURE_DESIRE_TABLE, d, 0x78) * 0.33333334f * a, 1.0f, 8.0f);
    desires.decay[d] = std::clamp(desires.decay[d] + a * 0.001f, InfoAt<float>(DETAIL_CREATURE_DESIRE_TABLE, d, 0x50),
                                  InfoAt<float>(DETAIL_CREATURE_DESIRE_TABLE, d, 0x54));
    for (uint32_t j = 0; j < kNumCreatureDesires; ++j) {
        const float dep = InfoAt<float>(infodat::DETAIL_CREATURE_DESIRE_DEPENDENCIES, d, 16 + 4 * j);
        if (dep > 0.0f) desires.cycle[j] = std::clamp(desires.cycle[j] * f, lo, hi);
        else if (dep < 0.0f) desires.cycle[j] = std::clamp(desires.cycle[j] / f, lo, hi);
    }
}

// sub_4C2E80: an episode for the desire's kind-2 learning, which is re-induced.
void CreatureBrain::AddEpisode(uint32_t desire, const Remembered& r, float weight) {
    auto& list = episodes_[desire];
    if (list.size() >= 16) list.erase(list.begin());
    Episode ep{r.kind, {}};
    std::copy(r.features, r.features + r.feature_count, ep.e.features);
    ep.e.weight = weight;
    list.push_back(ep);
    Reinduce(desire, r.kind);
}

// sub_4C2BB0, one kind of lesson from a remembered action:
// 0 the desire itself (sub_4C2F60 -> sub_4BEB30), 1 the plan's target,
// 2 what it was done to, also taught to every desire coupled to this one
// (DESIRE_DEPENDENCIES) at the coupling's strength, 3 the action (sub_4C2FA0:
// its opinion moves 80% of the way to the feedback).
// ponytail: kind 1 is not kept -- nothing here reads those trees (mental+0x2478);
// nor are the "I've learnt to..." lines (sub_4C3030) or the feedback icons.
void CreatureBrain::Teach(const Remembered& r, float a, int kind) {
    if (r.desire >= kNumCreatureDesires) return;
    switch (kind) {
    case 0:
        if (r.source < 61) FeedbackDesire(r.desire, r.source, a);
        break;
    case 2:
        // v1.0 also skips when record +20 == +24, but those are two fresh
        // clones (belief vslot 13), never the same; so only the creature itself.
        if (!r.object || r.object == creature_) return;
        AddEpisode(r.desire, r, a);
        for (uint32_t j = 0; j < kNumCreatureDesires; ++j) {
            const float c = j == r.desire ? 0.0f : InfoAt<float>(infodat::DETAIL_CREATURE_DESIRE_DEPENDENCIES, r.desire, 16 + 4 * j);
            if (c != 0.0f) AddEpisode(j, r, c * a);
        }
        break;
    case 3: {
        float& o = mind.action_opinion[r.action];
        o = std::clamp(o + (a - o) * 0.8f, -1.0f, 1.0f);
        break;
    }
    default: break;
    }
}

// sub_4C2090. ponytail: not modelled -- a puzzled look at feedback of 0.01 or
// less (action 82); positive feedback's special cases (an action flagged
// +240 while it holds something; running away from the player, desire 22);
// the sulk after a slap (mental+8656); the mimicry bookkeeping (+7224); and
// praise making it choose the same plan again.
void CreatureBrain::Feedback(float a) {
    Stop();  // sub_45FA70(creature, "PlayerFeedback")
    if (std::fabs(a) <= 0.01f) return;
    const float least = InfoAt<float>(infodat::DETAIL_CREATURE_INFO, species_, 676);
    a = a >= 0.0f ? std::max(a, least) : std::min(a, -least);
    const Remembered* best = nullptr;  // sub_4C1E00: the most relevant, newest first on ties
    float rel = 0.0f;
    for (uint32_t i = 0; const Remembered* r = Recent(i); ++i)
        if (const float v = Relevance(*r); v > rel) rel = v, best = r;
    if (!best || best->desire > kNumCreatureDesires) return;
    if (a > 0.0f && desires.Countdown(27, 90.0f)) agenda.plans.plans[27] = ActionPlan(), agenda.plans.plans[27].desire = 27;  // sadness
    if (creature_->field_0x1268 >= 2) {
        if (InfoAt<uint32_t>(infodat::DETAIL_CREATURE_DESIRE_TABLE, best->desire, 56))  // sub_4C29C0
            for (int kind = 0; kind < 4; ++kind) Teach(*best, a, kind);
    } else {
        // Too young to learn: praise feeds sources 12, 38 and 2, a slap 9 and 18.
        auto add = [this](uint32_t type, float v) { if (float* s = SourceSlot(type, 0)) *s = std::clamp(*s + v, 0.0f, 1.0f); };
        const float v = std::fabs(a) * 0.5f;
        if (a >= 0.0f) add(12, v), add(38, v), add(2, v);
        else add(9, v), add(18, v);
    }
    // A slap about what it is doing: that desire falls to the weakest's over
    // 1.3 (sub_4BEAC0) and every countdown ends (sub_4BE470).
    const Remembered* newest = Recent(0);
    if (a <= 0.0f && newest && newest->desire < kNumCreatureDesires) {
        desires.value[newest->desire] = desires.value[desires.Weakest()] / 1.3f;
        desires.Clamp(newest->desire);
        std::fill(std::begin(desires.countdown), std::end(desires.countdown), 0u);
        mind.desire[newest->desire] = desires.value[newest->desire];
    }
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

float CreatureBrain::OpinionOf(uint32_t desire, Object* o) {
    if (!o) return 0.0f;
    BeliefView b;
    b.id = IdOf(o);
    b.type = o->GetCreatureBeliefType();
    return Opinion(desire, b);
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
        if (auto* v = dynamic_cast<Villager*>(o)) WatchVillager(v);  // its belief refreshed (sub_4BA660)
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
    facts.player_has_temple = creature_->owner && creature_->owner->citadel;  // player +608
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
        Remember();
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
    RememberFinished();
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
