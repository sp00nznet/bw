#pragma once
// GMagicForestInfo — info for forest spell
// Struct layout from bw1-decomp (MagicForestInfo.h)
//
// Size: 0x58 bytes (extends GMagicInfo)

#include "GMagicInfo.h"

struct GMagicForestInfo : public GMagicInfo {
};
static_assert(sizeof(GMagicForestInfo) == 0x58, "GMagicForestInfo size mismatch");
