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

// ---------------------------------------------------------------------------
// The per-turn desire system
// ---------------------------------------------------------------------------
#include <black/InfoDat.h>
#include <black/LHRandom.h>
#include <black/Sigmoid.h>

#include <algorithm>
#include <cstring>

namespace creature {

namespace {
float ElemF(infodat::Section s, uint32_t i, int off) {
    const void* e = infodat::Element(s, i);
    float v = 0.0f;
    if (e) std::memcpy(&v, static_cast<const char*>(e) + off, 4);
    return v;
}
uint32_t ElemU(infodat::Section s, uint32_t i, int off) {
    const void* e = infodat::Element(s, i);
    uint32_t v = 0;
    if (e) std::memcpy(&v, static_cast<const char*>(e) + off, 4);
    return v;
}
}  // namespace

// sub_4BE280, sub_4C0220, sub_4C0100
bool DesireSystem::Init(uint32_t species, const CreatureMind* mind) {
    using namespace infodat;
    if (Count(DETAIL_CREATURE_DESIRE_TABLE) < kNumCreatureDesires || Count(DETAIL_CREATURE_DESIRE_SOURCE_TABLE) < 61 ||
        species >= Count(DETAIL_CREATURE_INFO))
        return false;
    *this = DesireSystem();
    min_value = ElemF(DETAIL_CREATURE_INFO, species, 628);
    for (uint32_t t = 0; t < 61; ++t) factor[t] = ElemF(DETAIL_CREATURE_DESIRE_SOURCE_TABLE, t, 24);
    for (uint32_t d = 0; d < kNumCreatureDesires; ++d) {
        active[d] = true;  // ponytail: sub_4BE280 asks sub_463140; the mind's flag decides below
        const float lo = ElemF(DETAIL_CREATURE_DESIRE_TABLE, d, 80), hi = ElemF(DETAIL_CREATURE_DESIRE_TABLE, d, 84);
        decay[d] = lo + lh::RandomFloat(hi - lo);
        max_value[d] = ElemF(DETAIL_CREATURE_DESIRE_TABLE, d, 76);
        cycle[d] = ElemF(DETAIL_CREATURE_DESIRE_INITIAL_CYCLE_TIME, d, 16 + 4 * static_cast<int>(species));  // a float, copied raw
        for (int k = 0; k < 8; ++k) {  // sub_4C0220: up to eight source types, 61 = none
            const uint32_t type = ElemU(DETAIL_CREATURE_DESIRE_TABLE, d, 16 + 4 * k);
            if (type >= 61) continue;
            DesireSourceSlot s;  // sub_4C0100, less its random jitter
            s.type = type;
            s.value = ElemF(DETAIL_CREATURE_INITIAL_DESIRE_SOURCE_VALUE, type, 16 + 4 * static_cast<int>(species));
            s.threshold = ElemF(DETAIL_CREATURE_INITIAL_DESIRE_SOURCE_THRESHOLD, type, 16 + 4 * static_cast<int>(species));
            sources[d].push_back(s);
        }
        if (mind) {  // what the mind file saved for this creature
            const MindDesire& m = mind->desires[d];
            active[d] = m.active;
            value[d] = m.params[0];
            max_value[d] = m.params[1];
            cycle[d] = m.params[2];
            if (!m.sources.empty()) {
                sources[d].clear();
                for (const MindDesireSource& ms : m.sources) {
                    DesireSourceSlot s;
                    s.type = ms.type;
                    s.value = ms.value;
                    s.threshold = ms.strength;
                    sources[d].push_back(s);
                }
            }
        }
    }
    return true;
}

// sub_4BE5B0
void DesireSystem::Tick(const std::function<bool(uint32_t type, float* value)>& compute, uint32_t turn_ms) {
    for (auto& list : sources)  // sub_4C05B0
        for (DesireSourceSlot& s : list) {
            float v;
            if (s.type < 61 && compute && compute(s.type, &v)) s.value = v;
            if (s.type < 61) s.value *= factor[s.type];
        }
    const float per_second = static_cast<float>(turn_ms ? 1000u / turn_ms : 10u);
    total = 0.0f;
    for (uint32_t d = 0; d < kNumCreatureDesires; ++d) {
        if (!active[d]) continue;
        if (countdown[d]) --countdown[d];
        float push = 0.0f;  // sub_4C04E0
        for (DesireSourceSlot& s : sources[d]) {
            const float c = s.value > 0.0f ? Sigmoid(s.threshold, s.value) : 0.0f;  // sub_4D6F10
            s.accumulated += c;
            push += c;
        }
        push = cycle[d] > 0.0f ? push / (per_second * cycle[d]) : 0.0f;
        value[d] = (push <= 0.0f || countdown[d]) ? decay[d] * value[d] : push + value[d];
        if (value[d] < min_value) value[d] = min_value;
        else if (value[d] > max_value[d]) value[d] = max_value[d];
        total += value[d];
    }
}

}  // namespace creature
