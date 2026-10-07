// CreatureBody — see black/CreatureBody.h.
#include <black/CreatureBody.h>
#include <black/InfoDat.h>
#include <black/Sigmoid.h>

#include <algorithm>
#include <cmath>
#include <cstring>

// sub_6DF550 (black/Sigmoid.h).
float Sigmoid(float threshold, float value) {
    static const uint32_t kTable[41] = {  // flt_B461D4
        0x00000000, 0x317763df, 0x322bcc77, 0x32f084a7, 0x33a71301, 0x34684017, 0x35218b62,
        0x35e0ae34, 0x369c419b, 0x375955de, 0x38172465, 0x38d235bd, 0x39922a17, 0x3a4b32f9,
        0x3b0d1eb3, 0x3bc38892, 0x3c868d9b, 0x3d35d41d, 0x3dea5e18, 0x3e8762a1, 0x3f000000,
        0x3f3c4eb0, 0x3f62b43d, 0x3f74a2be, 0x3f7bcb93, 0x3f7e78ef, 0x3f7f72e1, 0x3f7fcd33,
        0x3f7fedbb, 0x3f7ff96e, 0x3f7ffda3, 0x3f7fff27, 0x3f7fffb2, 0x3f7fffe4, 0x3f7ffff6,
        0x3f7ffffc, 0x3f7fffff, 0x3f800000, 0x3f800000, 0x3f800000, 0x3f800000};
    if (threshold == 1.0f) return 0.0f;
    float v = std::clamp(value, -1.0f, 1.0f);
    float d = std::clamp(v - threshold, -1.0f, 1.0f);
    int i = static_cast<int>((d + 1.0f) * 20.5f);  // _ftol: truncation
    if (i > 40) i = 40;
    float r;
    std::memcpy(&r, &kTable[i], 4);
    return r;
}

namespace creature {

namespace {
float F(const void* e, int off) { float v; std::memcpy(&v, static_cast<const char*>(e) + off, 4); return v; }
uint32_t U(const void* e, int off) { uint32_t v; std::memcpy(&v, static_cast<const char*>(e) + off, 4); return v; }
}  // namespace

bool BodyInfo::Load(uint32_t species) {
    const void* e = infodat::Element(infodat::DETAIL_CREATURE_INFO, species);
    if (!e) return false;
    strength_start = F(e, 300);
    reserve_start = F(e, 512);
    energy_start = F(e, 516);
    temperature_pref = F(e, 524);
    age_period = U(e, 528);
    growth_period = F(e, 532);
    tired_energy = F(e, 540);
    exhaustion_rate = F(e, 544);
    dehydration_time = F(e, 548);
    strength_decay = F(e, 552);
    hold_strength = F(e, 556);
    energy_drain = F(e, 560);
    reserve_drain = F(e, 564);
    spill = F(e, 568);
    rest = F(e, 576);
    digest = F(e, 888);
    poo_per_meal = F(e, 896);
    return true;
}

void CreatureBody::Init(const BodyInfo& info) {
    *this = CreatureBody();
    strength = info.strength_start;
    reserve = reserve_max = info.reserve_start;
    energy = info.energy_start;
}

void CreatureBody::Tick(const BodyInfo& info, const Context& c) {
    const uint32_t per_second = c.turn_ms ? 1000u / c.turn_ms : 10u;
    if (info.age_period && turn % (info.age_period * per_second) == 0) ++age;
    // ponytail: carrying an object (creature+40) trains strength here
    // (sub_4D0270 by the object's weight over its own); not modelled yet.

    if (!c.moving && c.stage >= 3) {  // sub_4CFDB0 -> sub_4D0000: growing while still
        const float span = info.growth_period * 0.016666668f;
        const float young = std::clamp((1.0f - std::min(static_cast<float>(age), span) / span) * 8.0f, 0.0f, 2.0f);
        float g = 1.0f / (info.growth_period * 600.0f) * (std::clamp(energy - exhaustion, 0.0f, 1.0f) * young);
        if (g <= 2.7e-7f) g = 2.7e-7f;
        if (c.current_action == 17 || c.current_action == 78) g *= 3.0f;  // asleep
        growth = std::clamp(growth + g, 0.0f, 2.0f);
    }

    strength = std::clamp(strength * info.strength_decay, 0.0f, 1.0f);

    if (c.stage >= 1) {
        // The 3D object's +144 is taken to mirror growth (+0x6C) -- inferred.
        float k = std::clamp(std::clamp(growth, 0.0f, 2.0f) * 0.5f + 1.0f, 1.0f, 2.0f);
        if (c.current_action == 17 || c.current_action == 59) k += 3.0f;  // asleep, resting
        energy = std::clamp(energy - info.energy_drain / k, 0.0f, 1.0f);
    }
    if (energy < 0.5f) reserve = std::clamp(reserve - info.reserve_drain, 0.0f, 1.0f);

    const float rate = std::max(4.0f - static_cast<float>(age) * 0.15f, 1.0f) * info.exhaustion_rate;
    if (c.moving) {
        exhaustion += rate;
        if (energy < info.tired_energy) exhaustion += rate * 0.3f;
        exhaustion = std::clamp(exhaustion, 0.0f, 1.0f);
    }

    if (c.stage >= 3) {
        const int turns = static_cast<int>(static_cast<double>(per_second) * info.dehydration_time);  // _ftol
        if (turns > 0) dehydration = std::clamp(dehydration + 1.0f / static_cast<float>(turns), 0.0f, 1.0f);
    }

    const float diff = c.air_temperature - info.temperature_pref;
    const float d = Sigmoid(0.6f, std::fabs(diff) * 0.025f);
    temperature = std::clamp(diff <= 0.0f ? temperature - d : temperature + d, -1.0f, 1.0f);

    ++turn;  // ponytail: the original advances +0x70 elsewhere; once a tick here
}

void CreatureBody::PayFor(float strength_cost, float energy_cost, float exhaustion_cost, uint32_t stage) {
    strength = std::clamp(strength + strength_cost, 0.0f, 1.0f);  // sub_4D0270
    if (stage < 1) return;
    const float k = std::clamp(growth + 1.0f, 1.0f, 3.0f);
    energy = std::clamp(energy - energy_cost / k, 0.0f, 1.0f);
    exhaustion = std::min(exhaustion + exhaustion_cost / k, 1.0f);
}

void CreatureBody::Eat(float food, const BodyInfo& info) {
    const float size = growth <= 0.8f ? growth : 0.8f;
    // A growth of 0 divides by zero in the original too; the cap below then holds.
    const float gain = size > 0.0f ? food / (size * info.digest) : 1e30f;
    const float over = gain * info.spill + energy - 1.0f;
    if (over > 0.0f) reserve = std::clamp(reserve + over, 0.0f, 1.0f);
    energy += gain;
    const float cap = std::max(growth, 1.0f);  // sub_4CF970: the 3D object's +144, taken as growth
    if (energy < 0.0f) energy = 0.0f;
    else if (cap < energy) energy = cap;
    poo = std::clamp(poo + std::clamp(gain, 0.0f, 1.0f) * info.poo_per_meal, 0.0f, 1.0f);
    ++meals;
}

}  // namespace creature
