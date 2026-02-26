#pragma once
// GMobileObjectInfo — info for mobile objects (pots, balls, etc.)
// Struct layout from bw1-decomp
//
// Size: 0x114 bytes (extends GMobileInfo at 0x104)

#include "GMobileInfo.h"

struct GMobileObjectInfo : public GMobileInfo {
    uint8_t field_0x104[0x10];  // 0x104
};
static_assert(sizeof(GMobileObjectInfo) == 0x114, "GMobileObjectInfo size mismatch");
