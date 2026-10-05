// CreatureAgenda — the agenda's half of the plan chooser: how each desire's
// plan slot is rebuilt every turn and how one of them becomes the creature's
// current plan. See black/CreaturePlanChooser.h and docs/creature-chooser.md.
#include <black/CreatureDispatch.gen.h>
#include <black/CreaturePlanChooser.h>

#include <algorithm>

namespace creature {

// sub_4D09A0: for a desire that is about something, the belief it scores
// highest (distance falloff x how the creature rates it as a target).
void PlanChooser::PickTarget(ActionPlan* plan) const {
    const uint32_t d = plan->desire;
    if (d >= kNumCreatureDesires || !t_.needs_target[d]) return;
    for (const BeliefView& b : beliefs_) {
        if (h_.target_ok ? !h_.target_ok(b.id, d) : b.self) continue;  // sub_4C4B60
        const float f = Falloff(d, b);
        if ((kDesireDispatch[d] & kDesHasTargetedFit) && h_.targeted_fit && !h_.targeted_fit(b.id, d)) continue;
        const float s = (h_.target_score ? h_.target_score(b.id, d) : 1.0f) * f;
        if (s > plan->desire_score) {
            plan->desire_score = s;
            plan->target = b.id;
        }
    }
}

// sub_4D0E30: the best candidate by its own score alone -- the opinion of the
// action plus familiarity. Ties go to the later candidate.
bool PlanChooser::ScoreActions(ActionPlan* plan, const std::vector<uint32_t>& tried) const {
    bool chose = false;
    for (uint32_t k = 0; k < 30; ++k) {
        const uint32_t a = Candidate(*plan, k);
        if (!a) break;
        if (a >= 328) continue;
        if ((kActionDispatch[a] & kActHasValidity) && h_.action_valid && !h_.action_valid(a, *plan)) continue;
        const ChooserTables::Action& r = t_.actions[a];
        if (r.ability[0] != 6 && !(h_.has && h_.has(0, r.ability[0]))) continue;
        if (r.ability[1] != 6 && !(h_.has && h_.has(0, r.ability[1]))) continue;
        if (r.spell && !(h_.has && h_.has(1, r.spell))) continue;
        if (std::find(tried.begin(), tried.end(), a) != tried.end()) continue;
        const float s = ActionScore(a);
        if (s >= plan->action_score) {
            plan->action = a;
            plan->action_score = s;
            chose = true;
        }
    }
    return chose;
}

// sub_4D1170: something to do the chosen action to. An action that takes no
// belief is done to the creature itself, at 0.1; otherwise the best-scoring
// belief that suits both the desire and the action, scoring above zero.
bool PlanChooser::FindBelief(ActionPlan* plan) const {
    const uint32_t a = plan->action, d = plan->desire;
    if (!t_.actions[a].uses_belief) {
        plan->belief = 0;
        for (const BeliefView& b : beliefs_) if (b.self) plan->belief = b.id;
        plan->belief_score = 0.1f;
        return true;
    }
    float best = 0.0f;
    uint32_t id = 0;
    for (const BeliefView& b : beliefs_) {
        if (!BeliefFits(b.id, d)) continue;
        if (t_.actions[a].not_own && b.own) continue;  // sub_4C4D20
        if ((kActionDispatch[a] & kActHasFit) && h_.action_fit && !h_.action_fit(b.id, a)) continue;
        const float s = BeliefScore(b.id, d);
        if (!b.self && s > best) { best = s; id = b.id; }
    }
    if (!id) return false;
    plan->belief = id;
    plan->belief_score = best;
    return true;
}

// sub_4D1280
bool PlanChooser::FindObject(ActionPlan* plan) const {
    if (!(kActionDispatch[plan->action] & kActNeedsObject)) {
        plan->object = 0;
        plan->object_score = 0.1f;
        return true;
    }
    const uint32_t o = BestObject(plan->desire, plan->action, plan->belief);
    if (!o) return false;
    plan->object = o;
    plan->object_score = 0.1f;  // sub_4CA7D0
    return true;
}

// sub_4D0B40. Most desires choose the action first and then something to do
// it to; a desire with a target (and the few without the +32 flag) has the
// target name the belief, through the target belief's vslot 12.
void PlanChooser::Fill(ActionPlan* plan) const {
    const uint32_t d = plan->desire;
    std::vector<uint32_t> tried;
    auto target_belief = [&](uint32_t action, float* score) {
        return h_.target_belief ? h_.target_belief(plan->target, d, action, score) : plan->target;
    };
    if (kDesireDispatch[d] & kDesActsAlone) {
        if (plan->target) {
            plan->belief = target_belief(0, &plan->belief_score);
            if (plan->belief) { ChooseAction(plan, nullptr, plan->belief, false); return; }  // sub_4D0D00
        } else {
            while (ScoreActions(plan, tried)) {
                if (FindBelief(plan) && FindObject(plan)) return;
                tried.push_back(plan->action);
                plan->action_score = 0.0f;
                if (tried.size() >= 30) return;
            }
        }
    } else {
        const BeliefView* t = Find(plan->target);
        if (t && t->type == 8) {  // about a creature: it is also the thing acted on
            plan->belief = plan->target;
            plan->belief_score = plan->desire_score;
        }
        while (ChooseAction(plan, &tried, plan->target, false)) {  // sub_4D0CE0
            float ignored = 0.0f;
            plan->belief = target_belief(plan->action, &ignored);   // sub_4D0D20
            plan->belief_score = plan->belief ? 0.1f : 0.0f;
            if (plan->belief) return;
            tried.push_back(plan->action);
            if (tried.size() >= 30) return;
        }
    }
    plan->action = 0;
    plan->action_score = 0.0f;
}

// sub_4D1DD0, in the binary's order: desire x target x min(action, 0.01) x
// belief x 10^5 x object, with 0.1 standing in for a missing target or object.
// The clamp means every candidate's action score counts the same.
float PlanChooser::Total(const ActionPlan& p) const {
    if (!Complete(p)) return 0.0f;
    const float tgt = p.target ? p.desire_score : 0.1f;
    const float obj = p.object ? p.object_score : 0.1f;
    const double act = p.action_score >= 0.0099999998f ? 0.0099999998 : p.action_score;
    return static_cast<float>(m_.desire[p.desire] * tgt * act * p.belief_score * 100000.0 * obj);
}

// sub_4D06F0
void Agenda::Refresh(const PlanChooser& c, const ChooserHost& h, uint32_t d) {
    ActionPlan& p = plans.plans[d];
    if ((kDesireDispatch[d] & kDesHasGate) && h.desire_gate && !h.desire_gate(d)) {
        p.total = 0.0f;
        return;
    }
    p = ActionPlan();  // sub_4D1380 clears all but the desire
    p.desire = d;
    c.PickTarget(&p);
    // ponytail: compassion's rotation through a town's needs (mental+134428) is
    // not modelled; Candidate() reads the need the host reports.
    if (!c.needs_target(d) || p.target) c.Fill(&p);  // sub_4D1410
    p.total = c.Total(p);
}

// sub_4D0630
bool Agenda::Tick(const PlanChooser& c, const ChooserMind& m, const ChooserHost& h) {
    for (int i = 0; i < 2 && count; ++i) Refresh(c, h, queue[--count]);  // sub_4D1520 pops
    if (count) return false;

    best = kNumCreatureDesires;  // sub_4D14E0
    float top = 0.0f;
    for (uint32_t d = 0; d < kNumCreatureDesires; ++d)
        if (top < plans.plans[d].total) { top = plans.plans[d].total; best = d; }

    if (best < kNumCreatureDesires) {  // sub_4D05D0
        const ActionPlan& p = plans.plans[best];
        if (p.total - current_total > current_total && c.Complete(p)) {
            plans.SetCurrent(p);  // sub_4D08E0
            current_total = p.total;
            return true;
        }
    }
    count = 0;  // sub_4D1550: desire 0 comes off first
    for (int d = kNumCreatureDesires - 1; d >= 0; --d)
        if (m.active[d] && !m.suppressed[d]) queue[count++] = static_cast<uint32_t>(d);
    return false;
}

}  // namespace creature
