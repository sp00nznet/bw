#pragma once
// GTerrainMap — terrain map data manager
// Struct layout from bw1-decomp (TerrainMap.h)
//
// Size: 0x4A130 bytes (Base-derived, holds 0x400 TerrainMapInfo + trailing one)

#include "Base.h"
#include "TerrainMapInfo.h"

struct GTerrainMap : Base {
    TerrainMapInfo list[0x400];     // 0x0008
    TerrainMapInfo map_info;        // 0x4A008
};
static_assert(sizeof(GTerrainMap) == 0x4A130, "GTerrainMap size mismatch");
