#pragma once
// GMobileInfo — info for mobile objects
// Struct layout from bw1-decomp
//
// Size: 0x104 bytes (extends GObjectInfo at 0x100)

#include "ObjectInfo.h"

struct GMobileInfo : public GObjectInfo {
    uint32_t field_0x100;  // 0x100
};
static_assert(sizeof(GMobileInfo) == 0x104, "GMobileInfo size mismatch");
