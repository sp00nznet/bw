#pragma once
// GBeliefInfo — info for belief data
// Struct layout from bw1-decomp (BeliefInfo.h)
//
// Size: 0x10 bytes (extends GBaseInfo)

#include "GBaseInfo.h"

struct GBeliefInfo {
    GBaseInfo super;  // 0x0
};
static_assert(sizeof(GBeliefInfo) == 0x10, "GBeliefInfo size mismatch");
