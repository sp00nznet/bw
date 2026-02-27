#pragma once
// GSpotVisualInfo — info for spot visual effects
// Struct layout from bw1-decomp (SpotVisualInfo.h)
//
// Size: 0x10 bytes (extends GBaseInfo)

#include "GBaseInfo.h"

struct GSpotVisualInfo {
    GBaseInfo super;  // 0x0
};
static_assert(sizeof(GSpotVisualInfo) == 0x10, "GSpotVisualInfo size mismatch");
