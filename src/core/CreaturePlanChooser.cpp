// CreaturePlanChooser — see black/CreaturePlanChooser.h.
#include <black/CreaturePlanChooser.h>
#include <black/CreatureDispatch.gen.h>
#include <black/GameThingWithPos.h>
#include <black/InfoDat.h>

#include <algorithm>
#include <cstring>

namespace creature {

namespace {

template <class T> T At(const void* e, int off) {
    T v;
    std::memcpy(&v, static_cast<const char*>(e) + off, sizeof v);
    return v;
}

bool Has(const std::vector<uint32_t>* v, uint32_t x) {
    return v && std::find(v->begin(), v->end(), x) != v->end();
}

}  // namespace

bool ChooserTables::Load(uint32_t species) {
    using namespace infodat;
    if (Count(DETAIL_CREATURE_DESIRE_ACTION_TABLE) < kNumCreatureDesires || Count(DETAIL_CREATURE_ACTION) < 328 ||
        Count(DETAIL_CREATURE_COMPASSION_FOR_TOWN_ACTION_TABLE) < 17 || Count(DETAIL_CREATURE_DESIRE_TABLE) < kNumCreatureDesires ||
        species >= Count(DETAIL_CREATURE_INFO))
        return false;
    for (uint32_t d = 0; d < kNumCreatureDesires; ++d) {
        std::memcpy(candidates[d], static_cast<const char*>(Element(DETAIL_CREATURE_DESIRE_ACTION_TABLE, d)) + 16, sizeof candidates[d]);
        const void* e = Element(DETAIL_CREATURE_DESIRE_TABLE, d);
        needs_target[d] = At<uint32_t>(e, 0x30) != 0;
        falloff[d] = At<float>(e, 0x68);
    }
    for (uint32_t i = 0; i < 17; ++i)
        std::memcpy(town_candidates[i], static_cast<const char*>(Element(DETAIL_CREATURE_COMPASSION_FOR_TOWN_ACTION_TABLE, i)) + 16,
                    sizeof town_candidates[i]);
    for (uint32_t a = 0; a < 328; ++a) {
        const void* e = Element(DETAIL_CREATURE_ACTION, a);
        actions[a] = {At<uint32_t>(e, 164) != 0, At<uint32_t>(e, 168), {At<uint32_t>(e, 172), At<uint32_t>(e, 176)},
                      At<uint32_t>(e, 180), At<uint32_t>(e, 184) != 0};
    }
    const void* info = Element(DETAIL_CREATURE_INFO, species);
    count_cap = At<uint32_t>(info, 680);
    max_distance = At<float>(info, 708);
    own_score = At<float>(info, 712);
    return true;
}

const BeliefView* PlanChooser::Find(uint32_t id) const {
    for (const BeliefView& b : beliefs_) if (b.id == id) return &b;
    return nullptr;
}

// sub_4D1870. Desire 1 (compassion) about a town reads the town's own table,
// indexed by what the town most needs. ponytail: the binary's two shortcuts
// are not modelled -- action 101 straight away for a big town's first
// candidate, and the rotation through town needs (mental+134428).
uint32_t PlanChooser::Candidate(const ActionPlan& plan, uint32_t k) const {
    if (k >= 30) return 0;
    if (plan.desire != 1) return plan.desire < kNumCreatureDesires ? t_.candidates[plan.desire][k] : 0;
    if (!plan.target || !h_.town_need) return 0;
    const int need = h_.town_need(plan.target);
    return need >= 0 && need <= 16 ? t_.town_candidates[need][k] : 0;
}

// sub_4D1BE0
bool PlanChooser::ActionPossible(uint32_t action, const ActionPlan& plan) const {
    if ((kActionDispatch[action] & kActHasValidity) && h_.action_valid && !h_.action_valid(action, plan)) return false;
    const ChooserTables::Action& a = t_.actions[action];
    for (uint32_t ab : a.ability)
        if (ab != 6 && !(h_.has && h_.has(0, ab))) return false;
    if (a.spell && !(h_.has && h_.has(1, a.spell))) return false;
    return !(Leashed() && m_.action_disabled[action]);
}

// sub_4AB7F0 + sub_4D0D70, summed by sub_4D1A90. The opinion moves the score
// by at most half a percent around 0.5, and the familiarity bonus by at most
// 0.01: candidates are separated by the belief, not the action.
float PlanChooser::ActionScore(uint32_t action) const {
    const float opinion = Leashed() && m_.action_disabled[action]
                              ? 0.0f
                              : (m_.action_opinion[action] + 1.0f) * 0.5f * 0.005f + 0.5f;
    const uint32_t cap = t_.count_cap ? t_.count_cap : 1;
    double fam = static_cast<double>(std::min(m_.action_count[action], cap)) * 4.0 / cap;
    if (!t_.actions[action].desire) fam *= 0.025;
    fam = std::clamp(fam, 0.0, 0.0099999998);
    return opinion + static_cast<float>(fam);
}

// sub_4D1F70: 1 - falloff x (distance / max, at most 1); the creature's own
// object scores own_score whatever the distance.
float PlanChooser::Falloff(uint32_t desire, const BeliefView& b) const {
    if (b.own) return t_.own_score;
    float c = desire < kNumCreatureDesires ? t_.falloff[desire] : 0.0f;
    if (b.distance <= t_.max_distance) c = c * b.distance / t_.max_distance;
    return 1.0f - c;
}

// sub_4CA6A0
float PlanChooser::BeliefScore(uint32_t belief, uint32_t desire) const {
    const BeliefView* b = Find(belief);
    if (!b) return 0.0f;
    if (Leashed() && b->distance > m_.leash && (desire != 35 || !(h_.leash_exempt && h_.leash_exempt(belief))))
        return 0.0f;
    float special = 1.0f;
    if (desire < kNumCreatureDesires && ((kDesireDispatch[desire] & kDesHasSpecial) || desire == 6) && h_.special)
        special = h_.special(belief, desire);
    return b->opinion * Falloff(desire, *b) * special;
}

// sub_4D1EB0: the object the creature's beliefs rate best for this desire,
// other than the belief acted on. sub_4CA7D0 is a constant 0.1.
uint32_t PlanChooser::BestObject(uint32_t desire, uint32_t action, uint32_t exclude) const {
    float best = 0.0f;
    uint32_t id = 0;
    for (const BeliefView& b : beliefs_) {
        if (b.id == exclude) continue;
        if ((kActionDispatch[action] & kActHasFit) && h_.action_fit && !h_.action_fit(b.id, action)) continue;
        const float v = std::clamp(0.1f * Falloff(desire, b), 0.0f, 1.0f);
        if (v > best) { best = v; id = b.id; }
    }
    return id;
}

// sub_4D1A90: the plan keeps whichever candidate has the larger
// object x belief x action product; ties go to the later one.
bool PlanChooser::Offer(uint32_t desire, uint32_t action, uint32_t belief, ActionPlan* plan) const {
    const float act = ActionScore(action);
    const float bel = plan->belief ? BeliefScore(belief, desire) : 0.1f;
    uint32_t object = 0;
    if (kActionDispatch[action] & kActNeedsObject) {
        object = BestObject(desire, action, plan->belief);
        if (!object) return false;
    }
    const float obj = 0.1f;
    if (plan->object_score * plan->belief_score * plan->action_score > obj * bel * act) return false;
    plan->object_score = obj;
    plan->object = object;
    plan->action = action;
    plan->belief_score = bel;
    plan->action_score = act;
    return true;
}

// sub_4D1CC0
bool PlanChooser::ChooseAction(ActionPlan* plan, const std::vector<uint32_t>* tried, uint32_t belief, bool for_belief) const {
    bool chose = false;
    for (uint32_t k = 0; k < 30; ++k) {
        const uint32_t a = Candidate(*plan, k);
        if (!a) break;
        if (a >= 328 || Has(tried, a) || !ActionPossible(a, *plan)) continue;
        if (for_belief && !t_.actions[a].uses_belief) continue;
        if (plan->belief) {  // sub_4C4D20
            const BeliefView* b = Find(plan->belief);
            if (t_.actions[a].not_own && b && b->own) continue;
            if ((kActionDispatch[a] & kActHasFit) && h_.action_fit && !h_.action_fit(plan->belief, a)) continue;
        }
        if (Offer(plan->desire, a, belief, plan)) chose = true;
    }
    return chose;
}

// sub_4AC290. `any` lets a desire through without a belief fit; the one
// caller translated here passes false.
void PlanChooser::PickDesire(ActionPlan* plan, const std::vector<uint32_t>& tried, bool any) const {
    for (uint32_t i = 0; i < kNumCreatureDesires; ++i) {
        if (!m_.active[i] || m_.suppressed[i]) continue;
        if ((kDesireDispatch[i] & kDesHasGate) && h_.desire_gate && !h_.desire_gate(i)) continue;
        if (t_.needs_target[i] || (i == 9 && !m_.has_player) || Has(&tried, i)) continue;
        if (!any && !(kDesireDispatch[i] & kDesHasBeliefFit)) continue;
        const float s = m_.desire[i] * 0.1f;
        if (s > plan->desire_score) { plan->desire_score = s; plan->desire = i; }
    }
}

// sub_4AC390. The comparison uses the desire's strength, but what is stored
// is the strength-free score -- as in the binary.
void PlanChooser::PickTargetedDesire(uint32_t belief, ActionPlan* plan, const std::vector<uint32_t>& tried) const {
    const BeliefView* b = Find(belief);
    if (!b) return;
    for (uint32_t i = 0; i < kNumCreatureDesires; ++i) {
        if (!m_.active[i] || m_.suppressed[i] || !t_.needs_target[i]) continue;
        if ((kDesireDispatch[i] & kDesHasGate) && h_.desire_gate && !h_.desire_gate(i)) continue;
        if ((kDesireDispatch[i] & kDesHasTargetedFit) && h_.targeted_fit && !h_.targeted_fit(belief, i)) continue;
        if (Has(&tried, i)) continue;
        const float score = (h_.target_score ? h_.target_score(belief, i) : 1.0f) * Falloff(i, *b);
        if (m_.desire[i] * score > plan->desire_score) {
            plan->desire = i;
            plan->target = belief;
            plan->desire_score = score;
        }
    }
}

// sub_4C4BD0, less the belief's own validity, which the host's list implies.
bool PlanChooser::BeliefFits(uint32_t belief, uint32_t desire) const {
    if (!belief || !Find(belief)) return false;
    return !(kDesireDispatch[desire] & kDesHasBeliefFit) || !h_.belief_fit || h_.belief_fit(belief, desire);
}

// sub_4D13B0
bool PlanChooser::Complete(const ActionPlan& p) const {
    return p.desire < kNumCreatureDesires && (!t_.needs_target[p.desire] || p.target) && p.belief && p.action &&
           (!(kActionDispatch[p.action] & kActNeedsObject) || p.object);
}

// sub_4AC5F0. Each pass picks the strongest untried desire, then looks for an
// action on `at` -- or, if `at` does not suit that desire, on the beliefs
// related to it -- and stops at the first complete plan. A desire that yields
// none is struck off; at most forty passes.
bool PlanChooser::Choose(uint32_t about, uint32_t at, ActionPlan* plan) const {
    std::vector<uint32_t> tried;
    while (tried.size() < kNumCreatureDesires) {
        const uint32_t desire = plan->desire;  // sub_4D1380 clears everything but the desire
        *plan = ActionPlan();
        plan->desire = desire;
        if (about) PickTargetedDesire(about, plan, tried);
        PickDesire(plan, tried, false);
        if (plan->desire < kNumCreatureDesires && (!t_.needs_target[plan->desire] || plan->target)) {  // sub_4D1410
            std::vector<uint32_t> options;
            if (BeliefFits(at, plan->desire) && BeliefScore(at, plan->desire) > 0.0f) options.push_back(at);
            else if (h_.related) options = h_.related(at);
            for (uint32_t b : options) {
                if (b != at && (!BeliefFits(b, plan->desire) || BeliefScore(b, plan->desire) <= 0.0f)) continue;
                plan->belief = b;
                ChooseAction(plan, nullptr, b, true);
                if (Complete(*plan)) return true;
            }
        }
        tried.push_back(plan->desire);
    }
    return false;
}

void BindObjectPredicates(ChooserHost* host, Creature* creature,
                          std::function<GameThingWithPos*(uint32_t belief)> resolve) {
    host->action_fit = [=](uint32_t b, uint32_t a) {
        return a < 328 && CallObjectPredicate(resolve(b), creature, kActionFitSlot[a]);
    };
    host->targeted_fit = [=](uint32_t b, uint32_t d) {
        return d < kNumCreatureDesires && CallObjectPredicate(resolve(b), creature, kDesireTargetedFitSlot[d]);
    };
    host->belief_fit = [=](uint32_t b, uint32_t d) {
        return d < kNumCreatureDesires && CallObjectPredicate(resolve(b), creature, kDesireBeliefFitSlot[d]);
    };
    // Desire +36. Play (sub_4C4AC0): 5 for a football game, 3 for a toy.
    // Curiosity (sub_4C4A90): 5 for something doing something interesting.
    // ponytail: sub_4CA6A0 also cuts curiosity to 0.01 for objects whose type the
    // mind has marked (mental+119840); the mind's per-type flags are not modelled.
    host->special = [=](uint32_t b, uint32_t d) {
        GameThingWithPos* o = resolve(b);
        if (!o) return 1.0f;
        if (d == 3) return o->IsPlayingFootball(creature) ? 5.0f : o->IsToy(nullptr) ? 3.0f : 1.0f;
        if (d == 6) return o->IsDoingSomethingInteresting(creature) ? 5.0f : 1.0f;
        return 1.0f;
    };
}

}  // namespace creature
