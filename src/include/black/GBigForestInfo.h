#pragma once
// GBigForestInfo — info for big forest objects
// Struct layout from bw1-decomp (BigForestInfo.h)
//
// Size: 0x128 bytes (extends GMultiMapFixedInfo)

#include "GMultiMapFixedInfo.h"

struct GBigForestInfo : public GMultiMapFixedInfo {
    uint8_t field_0x120[0x8]; // 0x120
};
static_assert(sizeof(GBigForestInfo) == 0x128, "GBigForestInfo size mismatch");
