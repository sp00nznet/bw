#pragma once
// GCreaturePenInfo — info for creature pens
// Struct layout from bw1-decomp (CreaturePenInfo.h)
//
// Size: 0x134 bytes (extends GCitadelPartInfo)

#include "GCitadelPartInfo.h"

struct GCreaturePenInfo : public GCitadelPartInfo {
};
static_assert(sizeof(GCreaturePenInfo) == 0x134, "GCreaturePenInfo size mismatch");
