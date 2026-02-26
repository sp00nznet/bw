#pragma once
// GTotemStatueInfo — info for totem statue objects
// Struct layout from bw1-decomp
//
// Size: 0x124 bytes (extends GMultiMapFixedInfo at 0x120)

#include "GMultiMapFixedInfo.h"

struct GTotemStatueInfo : public GMultiMapFixedInfo {
    uint32_t field_0x120;  // 0x120
};
static_assert(sizeof(GTotemStatueInfo) == 0x124, "GTotemStatueInfo size mismatch");
