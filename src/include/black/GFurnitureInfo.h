#pragma once
// GFurnitureInfo — info for furniture objects
// Struct layout from bw1-decomp (FurnitureInfo.h)
//
// Size: 0x100 bytes (extends GObjectInfo)

#include "GObjectInfo.h"

struct GFurnitureInfo : public GObjectInfo {
};
static_assert(sizeof(GFurnitureInfo) == 0x100, "GFurnitureInfo size mismatch");
