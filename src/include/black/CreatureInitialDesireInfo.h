#pragma once
// CreatureInitialDesireInfo — creature initial desire metadata
// Struct layout from bw1-decomp
//
// Size: 0x10 bytes (inherits GBaseInfo)
// Linked-list info entry for creature initial desire values.

#include "GBaseInfo.h"

struct CreatureInitialDesireInfo {
    GBaseInfo super;  // 0x0
};
static_assert(sizeof(CreatureInitialDesireInfo) == 0x10, "CreatureInitialDesireInfo size mismatch");
