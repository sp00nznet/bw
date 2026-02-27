#pragma once
// GMagicFlockGroundInfo — info for ground flock spell
// Struct layout from bw1-decomp (MagicFlockGroundInfo.h)
//
// Size: 0x58 bytes (extends GMagicInfo)

#include "GMagicInfo.h"

struct GMagicFlockGroundInfo : public GMagicInfo {
};
static_assert(sizeof(GMagicFlockGroundInfo) == 0x58, "GMagicFlockGroundInfo size mismatch");
