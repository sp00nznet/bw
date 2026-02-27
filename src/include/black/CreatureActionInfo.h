#pragma once
// CreatureActionInfo — creature action metadata
// Struct layout from bw1-decomp
//
// Size: 0x10 bytes (inherits GBaseInfo)
// Linked-list info entry for creature action types.

#include "GBaseInfo.h"

struct CreatureActionInfo {
    GBaseInfo super;  // 0x0
};
static_assert(sizeof(CreatureActionInfo) == 0x10, "CreatureActionInfo size mismatch");
