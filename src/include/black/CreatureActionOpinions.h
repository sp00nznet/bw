#pragma once
// CreatureActionOpinions — opinion values for each creature action
// Struct layout from bw1-decomp (CreatureAction.h)
//
// Size: 0x520 bytes (plain data, no Base inheritance)
// NUM_CREATURE_ACTIONS = 0x148 (328)

#include "types.h"

struct CreatureActionOpinions {
    uint32_t entries[0x148];  // 0x00 — one entry per creature action
};
static_assert(sizeof(CreatureActionOpinions) == 0x520, "CreatureActionOpinions size mismatch");
