#pragma once
// GFieldInfo — info for field objects
// Struct layout from bw1-decomp (FieldInfo.h)
//
// Size: 0x120 bytes (extends GMultiMapFixedInfo)

#include "GMultiMapFixedInfo.h"

struct GFieldInfo : public GMultiMapFixedInfo {
};
static_assert(sizeof(GFieldInfo) == 0x120, "GFieldInfo size mismatch");
