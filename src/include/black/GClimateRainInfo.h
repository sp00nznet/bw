#pragma once
// GClimateRainInfo — info for climate rain data
// Struct layout from bw1-decomp (ClimateRainInfo.h)
//
// Size: 0x10 bytes (extends GBaseInfo)

#include "GBaseInfo.h"

struct GClimateRainInfo {
    GBaseInfo super;  // 0x0
};
static_assert(sizeof(GClimateRainInfo) == 0x10, "GClimateRainInfo size mismatch");
