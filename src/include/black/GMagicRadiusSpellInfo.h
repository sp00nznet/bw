#pragma once
// GMagicRadiusSpellInfo — info for radius-based spells
// Struct layout from bw1-decomp (MagicRadiusSpellInfo.h)
//
// Size: 0x58 bytes (extends GMagicInfo)

#include "GMagicInfo.h"

struct GMagicRadiusSpellInfo : public GMagicInfo {
};
static_assert(sizeof(GMagicRadiusSpellInfo) == 0x58, "GMagicRadiusSpellInfo size mismatch");
