#pragma once
// GFootballPositionInfo — info for football positions
// Struct layout from bw1-decomp (FootballPositionInfo.h)
//
// Size: 0x10 bytes (extends GBaseInfo)
// Also defines GPFootballPositionInfo (0x10)

#include "GBaseInfo.h"

struct GFootballPositionInfo {
    GBaseInfo super;  // 0x0
};
static_assert(sizeof(GFootballPositionInfo) == 0x10, "GFootballPositionInfo size mismatch");

struct GPFootballPositionInfo {
    GBaseInfo super;  // 0x0
};
static_assert(sizeof(GPFootballPositionInfo) == 0x10, "GPFootballPositionInfo size mismatch");
