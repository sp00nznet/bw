#pragma once
// GEffectInfo — info for visual effects
// Struct layout from bw1-decomp (EffectInfo.h)
//
// Size: 0x34 bytes (extends GBaseInfo)

#include "GBaseInfo.h"

struct GEffectInfo {
    GBaseInfo super;       // 0x00
    float     field_0x10;  // 0x10
    float     field_0x14;  // 0x14
    float     field_0x18;  // 0x18
    float     field_0x1c;  // 0x1C
    uint32_t  field_0x20;  // 0x20
    float     field_0x24;  // 0x24
    uint32_t  field_0x28;  // 0x28
    float     field_0x2c;  // 0x2C
    uint32_t  field_0x30;  // 0x30
};
static_assert(sizeof(GEffectInfo) == 0x34, "GEffectInfo size mismatch");
