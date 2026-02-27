#pragma once
// GMagicFlockFlyingInfo — info for flying flock spell
// Struct layout from bw1-decomp (MagicFlockFlyingInfo.h)
//
// Size: 0x58 bytes (extends GMagicInfo)

#include "GMagicInfo.h"

struct GMagicFlockFlyingInfo : public GMagicInfo {
};
static_assert(sizeof(GMagicFlockFlyingInfo) == 0x58, "GMagicFlockFlyingInfo size mismatch");
