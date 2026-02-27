#pragma once
// GMagicTeleportInfo — info for teleport spell
// Struct layout from bw1-decomp (MagicTeleportInfo.h)
//
// Size: 0x58 bytes (extends GMagicInfo)

#include "GMagicInfo.h"

struct GMagicTeleportInfo : public GMagicInfo {
};
static_assert(sizeof(GMagicTeleportInfo) == 0x58, "GMagicTeleportInfo size mismatch");
