#pragma once
// CreaturePlan — creature goal/plan representation
// Struct layout from bw1-decomp (CreaturePlan.h)
//
// Size: 0x30 bytes (inherits 0x8 from Base)
// Also defines CreaturePlanState (0x830) and CreatureTimeToWait (0x8).

#include "Base.h"

// Forward-declare enums
enum CREATURE_DESIRES : uint32_t;
enum CREATURE_ACTION : uint32_t;

struct CreatureBelief;

struct CreaturePlan : public Base {
    CREATURE_DESIRES  creature_desire;  // 0x08
    CreatureBelief*   field_0xc;        // 0x0C
    CreatureBelief*   field_0x10;       // 0x10
    CreatureBelief*   field_0x14;       // 0x14
    CREATURE_ACTION   creature_action;  // 0x18
    float             field_0x1c;       // 0x1C
    float             field_0x20;       // 0x20
    float             field_0x24;       // 0x24
    float             field_0x28;       // 0x28
    float             field_0x2c;       // 0x2C
};
static_assert(sizeof(CreaturePlan) == 0x30, "CreaturePlan size mismatch");

struct CreaturePlanState {
    CreaturePlan     plans[0x28];          // 0x000
    uint32_t         field_0x780;          // 0x780
    uint32_t         field_0x784;          // 0x784
    CREATURE_DESIRES desires[0x28];        // 0x788
    uint32_t         field_0x828;          // 0x828
    int              desire_count;         // 0x82C
};
static_assert(sizeof(CreaturePlanState) == 0x830, "CreaturePlanState size mismatch");

struct CreatureTimeToWait : public Base {
};
static_assert(sizeof(CreatureTimeToWait) == 0x8, "CreatureTimeToWait size mismatch");
