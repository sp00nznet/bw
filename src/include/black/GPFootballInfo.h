#pragma once
// GPFootballInfo — info for football (PFootball) objects
// Struct layout from bw1-decomp (FootballInfo.h)
//
// Size: 0x120 bytes (extends GMultiMapFixedInfo)

#include "GMultiMapFixedInfo.h"

struct GPFootballInfo : public GMultiMapFixedInfo {
};
static_assert(sizeof(GPFootballInfo) == 0x120, "GPFootballInfo size mismatch");
