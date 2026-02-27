#pragma once
#include "GBaseInfo.h"
#include "TerrainMapTypeInfo.h"

struct TerrainMapInfo {
    GBaseInfo         super;            // 0x00
    TerrainMapTypeInfo type_info[0xE];  // 0x10
};
static_assert(sizeof(TerrainMapInfo) == 0x128, "TerrainMapInfo size mismatch");
