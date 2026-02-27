#pragma once
// CreatureSourceBoundsInfo — creature source bounds metadata
// Struct layout from bw1-decomp
//
// Size: 0x10 bytes (inherits GBaseInfo)
// Linked-list info entry for creature source bounds.

#include "GBaseInfo.h"

struct CreatureSourceBoundsInfo {
    GBaseInfo super;  // 0x0
};
static_assert(sizeof(CreatureSourceBoundsInfo) == 0x10, "CreatureSourceBoundsInfo size mismatch");
