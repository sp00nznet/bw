#pragma once
// GMobileStaticInfo — info for mobile static objects (rocks, etc.)
// Struct layout from bw1-decomp
//
// Size: 0x12C bytes (extends GMultiMapFixedInfo at 0x120)

#include "GMultiMapFixedInfo.h"

struct GMobileStaticInfo : public GMultiMapFixedInfo {
    uint8_t field_0x120[0x0C];  // 0x120
};
static_assert(sizeof(GMobileStaticInfo) == 0x12C, "GMobileStaticInfo size mismatch");
