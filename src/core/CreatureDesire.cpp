// CreatureDesire — translated from runblack_decrypted.exe (v1.0), sub_4BEB30.
// See CreatureDesire.h for the table layouts this confirmed.

#include "black/CreatureDesire.h"

namespace creature {

namespace {

inline float Clamp(float v, float lo, float hi) {
    return v < lo ? lo : (v > hi ? hi : v);
}

}  // namespace

void DesireModel::InitFromMind(const CreatureMind& mind) {
    for (uint32_t i = 0; i < kNumCreatureDesires; ++i) {
        const MindDesire& md = mind.desires[i];
        active[i] = md.active;
        source_count[i] = 0;
        for (const MindDesireSource& s : md.sources) {
            if (source_count[i] >= kMaxSourcesPerDesire) break;
            if (static_cast<uint32_t>(s.type) == kNoSource) continue;
            DesireSource& dst = sources[i][source_count[i]++];
            dst.type = s.type;
            dst.value = s.value;
        }
        desires[i] = DesireState();
    }
}

// sub_4BEB30
void DesireModel::UpdateDesire(uint32_t desire, const DesireTuning& t,
                               const SourceBounds* bounds, uint32_t bounds_count,
                               float dt) {
    if (desire >= kNumCreatureDesires || !active[desire]) return;

    // The decay factor, and the one number the coupling loop below reuses --
    // every other desire is multiplied or divided by this same factor, which is
    // why one desire moving drags the rest with it.
    const float factor = t.rate != 0.0f
                             ? (1.0f / t.rate - 1.0f) * dt + 1.0f
                             : 1.0f;

    DesireState& d = desires[desire];
    d.value = Clamp(d.value * factor, t.min_value, t.max_value);

    // Each source decays at its own per-type rate, into its own bounds.
    for (uint32_t s = 0; s < source_count[desire]; ++s) {
        DesireSource& src = sources[desire][s];
        const uint32_t type = static_cast<uint32_t>(src.type);
        if (type >= bounds_count) continue;
        const SourceBounds& b = bounds[type];
        src.value = Clamp(src.value - b.decay * dt, b.min_value, b.max_value);
    }

    // The bias drifts, but is held within a fifth either side of the target the
    // species table gives this desire -- a creature's nature bounds how far its
    // mood can wander from type.
    d.bias += t.bias_gain * dt;
    const float bias_lo = t.type_target - 0.2f < 0.0f ? 0.0f : t.type_target - 0.2f;
    const float bias_hi = t.type_target + 0.2f > 2.0f ? 2.0f : t.type_target + 0.2f;
    d.bias = Clamp(d.bias, bias_lo, bias_hi);

    if (t.growth_enabled) {
        d.growth = Clamp(d.growth + t.growth_gain * (1.0f / 3.0f) * dt, 1.0f, 8.0f);
    }

    // A slow creep, the same hundredth-of-a-unit per second for every desire.
    d.slow = Clamp(d.slow + dt * 0.001f, t.slow_min, t.slow_max);

    // The coupling. Positive dependency amplifies the other desire by the same
    // factor this one decayed by; negative divides by it. Zero, which is most
    // of the matrix, leaves it alone.
    for (uint32_t j = 0; j < kNumCreatureDesires; ++j) {
        const float dep = dependency[desire][j];
        if (dep == 0.0f) continue;
        float v = desires[j].value;
        if (dep > 0.0f) v *= factor;
        else if (factor != 0.0f) v /= factor;
        desires[j].value = Clamp(v, t.min_value, t.max_value);
    }
}

void DesireModel::Update(const DesireTuning* tuning, const SourceBounds* bounds,
                         uint32_t bounds_count, float dt) {
    if (!tuning) return;
    for (uint32_t i = 0; i < kNumCreatureDesires; ++i)
        UpdateDesire(i, tuning[i], bounds, bounds_count, dt);
}

uint32_t DesireModel::DominantDesire() const {
    uint32_t best = kNumCreatureDesires;
    float best_value = 0.0f;
    for (uint32_t i = 0; i < kNumCreatureDesires; ++i) {
        if (!active[i]) continue;
        if (best == kNumCreatureDesires || desires[i].value > best_value) {
            best = i;
            best_value = desires[i].value;
        }
    }
    return best;
}

// ---------------------------------------------------------------------------
// Plans
// ---------------------------------------------------------------------------

// sub_4D1450
void PlanState::Init() {
    for (uint32_t i = 0; i < kNumCreatureDesires; ++i) {
        plans[i] = ActionPlan();
        plans[i].desire = i;   // each slot owns its desire from the start
    }
    current_desire = kNumCreatureDesires;
    current_action = 0;
}

// sub_4D15E0: the plan is copied wholesale into the current-plan slot, and the
// desire and action fall out of it at their own offsets.
void PlanState::SetCurrent(const ActionPlan& plan) {
    current_desire = plan.desire;
    current_action = plan.action;
    if (plan.desire < kNumCreatureDesires) plans[plan.desire] = plan;
}

ActionPlan* PlanState::For(uint32_t desire) {
    return desire < kNumCreatureDesires ? &plans[desire] : nullptr;
}

const ActionPlan* PlanState::For(uint32_t desire) const {
    return desire < kNumCreatureDesires ? &plans[desire] : nullptr;
}

}  // namespace creature
