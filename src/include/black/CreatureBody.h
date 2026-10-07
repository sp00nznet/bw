#pragma once
// CreatureBody — the creature's physical state, the CreaturePhysical object at
// creature+352, and how it changes each turn. docs/creature-chooser.md.
//
// Translated from runblack_decrypted.exe (v1.0):
//   sub_4CF760  construction: what a new creature starts with (creature info)
//   sub_4CF980  the per-turn tick: energy drains, exhaustion builds while it
//               moves, it dehydrates, its temperature drifts toward the air's
//   sub_4CFEB0  what an action costs: energy, exhaustion and strength
//   sub_4CFDB0  growth while it is still (from stage 3)
//   sub_4CA040  the saved body in a mind file (CreatureMindFile reads it)
//
// The body feeds the desire sources (sub_4C0840 and its neighbours): hunger
// from 1 - energy, tiredness from exhaustion, thirst from dehydration, to poo
// from poo, warmer/colder from temperature.

#include <cstdint>

namespace creature {

// The creature info record fields the body reads (DETAIL_CREATURE_INFO,
// element offsets as the binary uses them).
struct BodyInfo {
    float    strength_start = 0.2f;      // +300 (the original adds +/-0.1 at random)
    float    reserve_start = 0.5f;       // +512 (likewise)
    float    energy_start = 1.0f;        // +516
    float    temperature_pref = 15.0f;   // +524: the air it is comfortable in
    uint32_t age_period = 3600;          // +528: seconds per unit of age
    float    growth_period = 240.0f;     // +532
    float    tired_energy = 0.2f;        // +540: below this, exhaustion builds faster
    float    exhaustion_rate = 4e-5f;     // +544
    float    dehydration_time = 5000.0f; // +548: seconds to go from 0 to 1
    float    strength_decay = 0.99998f;  // +552
    float    hold_strength = 6.0f;       // +556
    float    energy_drain = 0.000116f;   // +560 a turn
    float    reserve_drain = 8e-5f;      // +564 a turn, while energy is below 0.5
    float    spill = 0.06f;              // +568: how much of a meal past full goes to the reserve
    float    digest = 1000.0f;           // +888: food per unit of energy (times growth)
    float    poo_per_meal = 0.8f;        // +896
    bool Load(uint32_t species);         // from info.dat; false if it is not loaded
};

// CreaturePhysical (0x74), the fields this translation uses.
struct CreatureBody {
    uint32_t age = 0;            // +0x08: age units (one per age_period)
    float    strength = 0.0f;    // +0x0C: 0..1, trained by carrying
    float    temperature = 0.0f; // +0x10: -1 cold .. +1 hot
    float    reserve = 0.0f;     // +0x14: drains when energy is low
    float    reserve_max = 0.0f; // +0x18
    float    energy = 1.0f;      // +0x1C
    float    poo = 0.0f;         // +0x2C
    float    exhaustion = 0.0f;  // +0x30
    float    dehydration = 0.0f; // +0x34
    float    growth = 0.0f;      // +0x6C: 0..2 (sub_4D0000); also the 3D object's +144
    uint32_t turn = 0;           // +0x70
    uint32_t meals = 0;          // creature+4540

    // What the tick needs from the rest of the creature and the world.
    struct Context {
        uint32_t stage = 0;          // creature+0x1268
        bool     moving = false;     // sub_46CB80: its 3D object's +18836 is 1
        uint32_t current_action = 0; // mental+3936
        float    air_temperature = 24.7f;  // sub_6FEBF0 at its position
        uint32_t turn_ms = 100;      // dword_C22D78
    };

    void Init(const BodyInfo& info);                   // sub_4CF760, less the random jitter
    void Tick(const BodyInfo& info, const Context& c); // sub_4CF980
    // sub_4CFEB0: doing `action` costs the action record's +16/+20/+24
    // (strength, energy, exhaustion), the last two from stage 1.
    void PayFor(float strength_cost, float energy_cost, float exhaustion_cost, uint32_t stage);
    // sub_4DF5A0, the Eat sub-action's first step: `food` is the eaten object's
    // GetFoodValue(3) (its info +104 -- 250 for a villager, 20 for a fish).
    // Energy rises by food / (min(growth, 0.8) x info+888), up to max(growth, 1);
    // what would pass full partly fills the reserve, and poo builds.
    void Eat(float food, const BodyInfo& info);
};

}  // namespace creature
