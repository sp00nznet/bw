#pragma once
// GCitadelInfo — info for citadel containers
// Struct layout from bw1-decomp (CitadelInfo.h)
//
// Size: 0x148 bytes (extends GContainerInfo)

#include "GContainerInfo.h"

struct GCitadelInfo : public GContainerInfo {
};
static_assert(sizeof(GCitadelInfo) == 0x148, "GCitadelInfo size mismatch");
