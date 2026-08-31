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

// ---------------------------------------------------------------------------
// Plans -- what a desire actually makes the creature do.
//
// A plan is a desire paired with a CREATURE_ACTION and up to three belief
// targets. Recovered from sub_4B2720 (a site that builds one: desire 24
// TO_OBEY_PLAYER, action 89, one belief target), sub_4D1450 (the plan state's
// init) and sub_4D15E0 (installing one as current). The field offsets match the
// vendor CreaturePlan layout in CreaturePlan.h, which is 0x30 and correct --
// this is the working model beside it, not a replacement.
// ---------------------------------------------------------------------------

struct ActionPlan {
    uint32_t desire = 0;         // +0x08
    uint32_t target[3] = {0, 0, 0};   // +0x0C, +0x10, +0x14 -- belief handles
    uint32_t action = 0;         // +0x18 -- a CREATURE_ACTION, 0..327
    float    params[5] = {0, 0, 0, 0, 0};  // +0x1C .. +0x2C
};

// sub_4D1450 gives every one of the 40 slots its own desire up front, so the
// agenda always has a plan per desire to fill in rather than allocating.
struct PlanState {
    ActionPlan plans[kNumCreatureDesires];

    // The current plan's desire and action. In the original these live at
    // mental+3920 and mental+3936, being the desire and action fields of the
    // plan copied to mental+3912 -- which is why
    // AttributeCreatureDominantDesire reads the *action* and maps it back
    // through CreatureActionInfo rather than reading a desire directly.
    uint32_t current_desire = kNumCreatureDesires;
    uint32_t current_action = 0;

    PlanState() { Init(); }

    // sub_4D1450: reset every slot, each pre-assigned to its own desire.
    void Init();

    // sub_4D15E0: make this plan the creature's current one.
    void SetCurrent(const ActionPlan& plan);

    // The plan slot belonging to a desire, or nullptr if out of range.
    ActionPlan* For(uint32_t desire);
    const ActionPlan* For(uint32_t desire) const;
};

}  // namespace creature
