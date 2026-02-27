#pragma once
// GPlayerInfo — player configuration/setup info
// Struct layout from bw1-decomp
//
// Size: 0x90 bytes (inherits 0x10 from GBaseInfo)
// Flat C data struct with void* vftable, not C++ virtual inheritance.

#include "GBaseInfo.h"

struct GPlayerInfo {
    GBaseInfo super;         // 0x00
    float     field_0x10;    // 0x10
    float     field_0x14;    // 0x14
    float     field_0x18;    // 0x18
    float     field_0x1c;    // 0x1C
    uint32_t  field_0x20;    // 0x20
    float     field_0x24;    // 0x24
    float     field_0x28;    // 0x28
    float     field_0x2c;    // 0x2C
    float     field_0x30;    // 0x30
    float     field_0x34;    // 0x34
    float     field_0x38;    // 0x38
    float     field_0x3c;    // 0x3C
    float     field_0x40;    // 0x40
    uint32_t  field_0x44;    // 0x44
    float     field_0x48;    // 0x48
    float     field_0x4c;    // 0x4C
    uint8_t   field_0x50[0x40]; // 0x50-0x8F
};
static_assert(sizeof(GPlayerInfo) == 0x90, "GPlayerInfo size mismatch");
