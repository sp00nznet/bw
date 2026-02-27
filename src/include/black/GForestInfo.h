#pragma once
// GForestInfo — info for forest containers
// Struct layout from bw1-decomp (ForestInfo.h)
//
// Size: 0x148 bytes (extends GContainerInfo)

#include "GContainerInfo.h"

struct GForestInfo : public GContainerInfo {
};
static_assert(sizeof(GForestInfo) == 0x148, "GForestInfo size mismatch");
