#pragma once
// CreatureMimicInfo — creature mimic metadata
// Struct layout from bw1-decomp
//
// Size: 0x10 bytes (inherits GBaseInfo)
// Linked-list info entry for creature mimic behavior.

#include "GBaseInfo.h"

struct CreatureMimicInfo {
    GBaseInfo super;  // 0x0
};
static_assert(sizeof(CreatureMimicInfo) == 0x10, "CreatureMimicInfo size mismatch");
