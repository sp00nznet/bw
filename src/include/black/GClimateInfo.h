#pragma once
// GClimateInfo — info for climate data
// Struct layout from bw1-decomp (ClimateInfo.h)
//
// Size: 0x10 bytes (extends GBaseInfo)

#include "GBaseInfo.h"

struct GClimateInfo {
    GBaseInfo super;  // 0x0
};
static_assert(sizeof(GClimateInfo) == 0x10, "GClimateInfo size mismatch");
