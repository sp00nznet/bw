#pragma once
// GMagicHealInfo — info for healing spell
// Struct layout from bw1-decomp (MagicHealInfo.h)
//
// Size: 0x58 bytes (extends GMagicInfo)

#include "GMagicInfo.h"

struct GMagicHealInfo : public GMagicInfo {
};
static_assert(sizeof(GMagicHealInfo) == 0x58, "GMagicHealInfo size mismatch");
