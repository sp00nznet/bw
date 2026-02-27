#pragma once
// GAlignmentInfo — info for alignment data
// Struct layout from bw1-decomp (AlignmentInfo.h)
//
// Size: 0x10 bytes (extends GBaseInfo)

#include "GBaseInfo.h"

struct GAlignmentInfo {
    GBaseInfo super;  // 0x0
};
static_assert(sizeof(GAlignmentInfo) == 0x10, "GAlignmentInfo size mismatch");
