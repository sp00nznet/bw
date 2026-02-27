#pragma once
#include "GBaseInfo.h"
struct GTerrainMaterialInfo { GBaseInfo super; };
static_assert(sizeof(GTerrainMaterialInfo) == 0x10, "GTerrainMaterialInfo size mismatch");
