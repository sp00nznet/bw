#pragma once
// GMobileWallHugInfo — info for wall-hugging mobile objects
// Struct layout from bw1-decomp (MobileWallHugInfo.h)
//
// Size: 0x120 bytes (extends GMobileInfo at 0x104)

#include "GMobileInfo.h"

struct GMobileWallHugInfo : public GMobileInfo {
    int32_t  speed;          // 0x104
    uint8_t  field_0x108[0xC]; // 0x108-0x113
    float    field_0x114;    // 0x114
    float    field_0x118;    // 0x118
    float    field_0x11c;    // 0x11C
};
static_assert(sizeof(GMobileWallHugInfo) == 0x120, "GMobileWallHugInfo size mismatch");
