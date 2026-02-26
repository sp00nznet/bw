#pragma once
// GCitadelPartInfo — info for citadel part objects
// Struct layout from bw1-decomp
//
// Size: 0x134 bytes (extends GMultiMapFixedInfo at 0x120)

#include "GMultiMapFixedInfo.h"

struct GCitadelPartInfo : public GMultiMapFixedInfo {
    uint32_t field_0x120;   // 0x120
    uint32_t field_0x124;   // 0x124
    float    life;          // 0x128
    uint32_t field_0x12c;   // 0x12C
    float    field_0x130;   // 0x130
};
static_assert(sizeof(GCitadelPartInfo) == 0x134, "GCitadelPartInfo size mismatch");
