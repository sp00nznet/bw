#pragma once
// GCitadelHeartInfo — info for citadel heart objects
// Struct layout from bw1-decomp (CitadelHeartInfo.h)
//
// Size: 0x158 bytes (extends GCitadelPartInfo)

#include "GCitadelPartInfo.h"

struct GCitadelHeartInfo : public GCitadelPartInfo {
    uint32_t field_0x134;  // 0x134
    uint32_t field_0x138;  // 0x138
    uint32_t field_0x13c;  // 0x13C
    float    field_0x140;  // 0x140
    float    field_0x144;  // 0x144
    float    field_0x148;  // 0x148
    float    field_0x14c;  // 0x14C
    float    field_0x150;  // 0x150
    float    field_0x154;  // 0x154
};
static_assert(sizeof(GCitadelHeartInfo) == 0x158, "GCitadelHeartInfo size mismatch");
