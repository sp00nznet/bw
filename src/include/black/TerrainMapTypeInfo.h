#pragma once
// TerrainMapTypeInfo — terrain type classification
// Struct layout from bw1-decomp (TerrainMapTypeInfo.h)
//
// Size: 0x14 bytes (extends GBaseInfo)

#include "GBaseInfo.h"

struct TerrainMapTypeInfo {
    GBaseInfo super;       // 0x00
    uint8_t   field_0x10;  // 0x10
    uint8_t   field_0x11;  // 0x11
    uint8_t   field_0x12;  // 0x12
    uint8_t   field_0x13;  // 0x13
};
static_assert(sizeof(TerrainMapTypeInfo) == 0x14, "TerrainMapTypeInfo size mismatch");
