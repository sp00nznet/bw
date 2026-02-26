#pragma once
// GWorshipSiteInfo — info for worship site objects
// Struct layout from bw1-decomp
//
// Size: 0x160 bytes (extends GCitadelPartInfo at 0x134)

#include "GCitadelPartInfo.h"

struct GWorshipSiteInfo : public GCitadelPartInfo {
    float    field_0x134;   // 0x134
    uint32_t field_0x138;   // 0x138
    uint32_t field_0x13c;   // 0x13C
    uint32_t field_0x140;   // 0x140
    float    field_0x144;   // 0x144
    float    field_0x148;   // 0x148
    uint32_t field_0x14c;   // 0x14C
    float    field_0x150;   // 0x150
    float    field_0x154;   // 0x154
    uint32_t field_0x158;   // 0x158
    float    field_0x15c;   // 0x15C
};
static_assert(sizeof(GWorshipSiteInfo) == 0x160, "GWorshipSiteInfo size mismatch");
