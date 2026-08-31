#pragma once
// CreatureDesire — how a creature's wants rise, fall and pull on each other.
//
// Every tick each of the 40 desires decays toward its resting point, its
// sources decay at their own per-type rate, and then — the part that gives the
// system its character — the desire's change is coupled into every *other*
// desire through a 40x40 dependency matrix. Getting hungry makes a creature
// less playful; that is not scripted anywhere, it is one signed number in that
// matrix.
//
// Translated from runblack_decrypted.exe (v1.0):
//
//   sub_4BE280   init: per-desire setup, initial value randomised between the
//                info record's min and max
//   sub_4C0220   source list rebuild: up to 8 source types per desire, 61 = none
//   sub_4BEB30   the per-tick update translated below
//
// The update also confirmed three table layouts that neither our headers nor
// the vendor's had (all were 0x10, the RTTI wrapper only):
//
//   CreatureInitialDesireInfo   40 x 448 bytes  (112 dwords per desire)
//   CreatureDesireDependency    40 x 176 bytes  (44 dwords -- the coupling row)
//   CreatureSourceBoundsInfo    61 x  28 bytes  (7 dwords per source type)
//
// Those tables are .bss, filled from data at load time, so the *values* are not
// in the executable and the host supplies them (see work/decomp/creature_data.md).
// What is here is the arithmetic, which is the binary's exactly.

#include "CreatureDesireEnums.h"
#include "CreatureMindFile.h"

#include <cstdint>

namespace creature {

// Per-desire tuning, from one CreatureInitialDesireInfo record.
struct DesireTuning {
    // sub_4BEB30's decay factor is (1/rate - 1) * dt + 1, so a rate of 1 leaves
    // the desire untouched and a smaller one inflates it. Zero would divide, so
    // it is treated as "no decay".
    float rate = 1.0f;
    float min_value = 0.0f;      // the clamp either side of every update
    float max_value = 1.0f;
    float bias_gain = 0.0f;      // added to the bias each tick
    float type_target = 0.0f;    // from CreatureDesireForType; bias holds within +/-0.2 of it
    float growth_gain = 0.0f;    // added to growth at a third of its rate
    bool  growth_enabled = false;
    float slow_min = 0.0f;       // the slow accumulator's own clamp
    float slow_max = 1.0f;
};

// Per-source-type bounds, from one CreatureSourceBoundsInfo record.
struct SourceBounds {
    float min_value = 0.0f;
    float max_value = 1.0f;
    float decay = 0.0f;          // subtracted, scaled by dt, each tick
};

// The four per-desire accumulators the update maintains, at the offsets the
// original keeps them in CreatureDesires.
struct DesireState {
    float value = 0.0f;   // +0x1E8 — what the creature actually wants
    float bias = 0.0f;    // +0x468 — drifts toward the species' type target
    float growth = 0.0f;  // +0x508 — clamped to [1, 8]
    float slow = 0.0f;    // +0x288 — creeps at 0.001/tick, randomised at init
};

// One source feeding a desire, with the value the mind file supplied.
struct DesireSource {
    CREATURE_DESIRE_SOURCE type = static_cast<CREATURE_DESIRE_SOURCE>(0);
    float value = 0.0f;
};

// The whole desire system for one creature.
struct DesireModel {
    DesireState  desires[kNumCreatureDesires];
    bool         active[kNumCreatureDesires] = {false};

    // dependency[i][j]: how a change in desire i pulls on desire j. Positive
    // amplifies by the same factor desire i decayed by, negative divides by it,
    // zero leaves it alone. This is CreatureDesireDependency's 44-dword row.
    float dependency[kNumCreatureDesires][kNumCreatureDesires] = {{0.0f}};

    // Sources per desire, in the order the mind file lists them. The original
    // allows up to eight, with source type 61 meaning "no source".
    enum : uint32_t { kMaxSourcesPerDesire = 8, kNoSource = 61 };
    DesireSource sources[kNumCreatureDesires][kMaxSourcesPerDesire];
    uint32_t     source_count[kNumCreatureDesires] = {0};

    // Fill values and sources from a parsed mind file. Tuning still has to come
    // from the info tables; this only supplies what the mind carries.
    void InitFromMind(const CreatureMind& mind);

    // sub_4BEB30, for one desire. `bounds` is indexed by source type.
    void UpdateDesire(uint32_t desire, const DesireTuning& tuning,
                      const SourceBounds* bounds, uint32_t bounds_count,
                      float dt);

    // Every active desire, in order.
    void Update(const DesireTuning* tuning, const SourceBounds* bounds,
                uint32_t bounds_count, float dt);

    // The strongest active desire, or kNumCreatureDesires if none are active.
    // This is what AttributeCreatureDominantDesire reports about a creature and
    // what the agenda picks its next action from.
    uint32_t DominantDesire() const;
};

}  // namespace creature
