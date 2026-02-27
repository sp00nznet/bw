#pragma once
// GAnimatedStaticInfo — info for animated static objects
// Struct layout from bw1-decomp (AnimatedStaticInfo.h)
//
// Size: 0x120 bytes (extends GFeatureInfo)

#include "GFeatureInfo.h"

struct GAnimatedStaticInfo : public GFeatureInfo {
};
static_assert(sizeof(GAnimatedStaticInfo) == 0x120, "GAnimatedStaticInfo size mismatch");
