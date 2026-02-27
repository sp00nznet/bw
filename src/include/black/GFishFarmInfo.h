#pragma once
// GFishFarmInfo — info for fish farm objects
// Struct layout from bw1-decomp (FishFarmInfo.h)
//
// Size: 0x120 bytes (extends GMultiMapFixedInfo)

#include "GMultiMapFixedInfo.h"

struct GFishFarmInfo : public GMultiMapFixedInfo {
};
static_assert(sizeof(GFishFarmInfo) == 0x120, "GFishFarmInfo size mismatch");
