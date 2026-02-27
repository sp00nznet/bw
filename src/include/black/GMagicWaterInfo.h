#pragma once
// GMagicWaterInfo — info for water spell
// Struct layout from bw1-decomp (MagicWaterInfo.h)
//
// Size: 0x58 bytes (extends GMagicInfo)

#include "GMagicInfo.h"

struct GMagicWaterInfo : public GMagicInfo {
};
static_assert(sizeof(GMagicWaterInfo) == 0x58, "GMagicWaterInfo size mismatch");
