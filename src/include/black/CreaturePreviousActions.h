#pragma once
// CreaturePreviousActions — history of creature action values
// Struct layout from bw1-decomp (CreatureAction.h)
//
// Size: 0x528 bytes (inherits 0x8 from Base)
// NUM_CREATURE_ACTIONS = 0x148 (328)

#include "Base.h"

struct CreaturePreviousActions : public Base {
    float field_0x8[0x148];  // 0x08 — one float per creature action
};
static_assert(sizeof(CreaturePreviousActions) == 0x528, "CreaturePreviousActions size mismatch");
