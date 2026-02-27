#pragma once
// GRewardInfo — info for reward objects
// Struct layout from bw1-decomp (RewardInfo.h)
//
// Size: 0x114 bytes (extends GMobileObjectInfo)

#include "GMobileObjectInfo.h"

struct GRewardInfo : public GMobileObjectInfo {
};
static_assert(sizeof(GRewardInfo) == 0x114, "GRewardInfo size mismatch");
