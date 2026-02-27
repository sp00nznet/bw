#pragma once
// GMagicShieldInfo — info for shield spell
// Struct layout from bw1-decomp (MagicShieldInfo.h)
//
// Size: 0x58 bytes (extends GMagicRadiusSpellInfo)

#include "GMagicRadiusSpellInfo.h"

struct GMagicShieldInfo : public GMagicRadiusSpellInfo {
};
static_assert(sizeof(GMagicShieldInfo) == 0x58, "GMagicShieldInfo size mismatch");
