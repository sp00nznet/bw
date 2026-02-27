#pragma once
// CreatureInitialSourceInfo — creature initial source metadata
// Struct layout from bw1-decomp
//
// Size: 0x10 bytes (inherits GBaseInfo)
// Linked-list info entry for creature initial source data.

#include "GBaseInfo.h"

struct CreatureInitialSourceInfo {
    GBaseInfo super;  // 0x0
};
static_assert(sizeof(CreatureInitialSourceInfo) == 0x10, "CreatureInitialSourceInfo size mismatch");
