#pragma once
// DifferentCreatureInfo — info for different creature types
// Struct layout from bw1-decomp (DifferentCreatureInfo.h)
//
// Size: 0x10 bytes (extends GBaseInfo)

#include "GBaseInfo.h"

struct DifferentCreatureInfo {
    GBaseInfo super;  // 0x0
};
static_assert(sizeof(DifferentCreatureInfo) == 0x10, "DifferentCreatureInfo size mismatch");
