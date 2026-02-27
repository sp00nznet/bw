#pragma once
// TownCreatureInfo — town-level creature information
// Struct layout from bw1-decomp (TownCreatureInfo.h)
//
// Size: 0x10 bytes (extends GBaseInfo)

#include "GBaseInfo.h"

struct TownCreatureInfo {
    GBaseInfo super;  // 0x0
};
static_assert(sizeof(TownCreatureInfo) == 0x10, "TownCreatureInfo size mismatch");
