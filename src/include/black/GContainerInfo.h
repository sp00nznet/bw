#pragma once
// GContainerInfo — info for container objects (citadels, flocks, etc.)
// Struct layout from bw1-decomp
//
// Size: 0x148 bytes (extends GBaseInfo at 0x10)

#include "GBaseInfo.h"

struct GContainerInfo : public GBaseInfo {
    uint32_t field_0x10;          // 0x10
    uint8_t  field_0x14[0xFC];    // 0x14
    uint32_t field_0x110;         // 0x110
    uint8_t  field_0x114[0x2C];   // 0x114
    float    field_0x140;         // 0x140
    float    field_0x144;         // 0x144
};
static_assert(sizeof(GContainerInfo) == 0x148, "GContainerInfo size mismatch");
