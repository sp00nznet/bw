#pragma once
// GFlowersInfo — info for flowers feature objects
// Struct layout from bw1-decomp (FlowersInfo.h)
//
// Size: 0x120 bytes (extends GFeatureInfo)

#include "GFeatureInfo.h"

struct GFlowersInfo : public GFeatureInfo {
};
static_assert(sizeof(GFlowersInfo) == 0x120, "GFlowersInfo size mismatch");
