#pragma once
// GArrowInfo — info for arrow projectiles
// Struct layout from bw1-decomp (ArrowInfo.h)
//
// Size: 0x114 bytes (extends GMobileObjectInfo)

#include "GMobileObjectInfo.h"

struct GArrowInfo : public GMobileObjectInfo {
};
static_assert(sizeof(GArrowInfo) == 0x114, "GArrowInfo size mismatch");
