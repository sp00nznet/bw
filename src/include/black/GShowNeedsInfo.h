#pragma once
// GShowNeedsInfo — info for show-needs visual objects
// Struct layout from bw1-decomp
//
// Size: 0x114 bytes (extends GObjectInfo at 0x100)

#include "ObjectInfo.h"

struct GShowNeedsInfo : public GObjectInfo {
    uint8_t field_0x100[0x14];  // 0x100
};
static_assert(sizeof(GShowNeedsInfo) == 0x114, "GShowNeedsInfo size mismatch");
