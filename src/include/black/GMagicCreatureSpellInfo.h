#pragma once
// GMagicCreatureSpellInfo — info for creature-cast spells
// Struct layout from bw1-decomp (MagicCreatureSpellInfo.h)
//
// Size: 0x58 bytes (extends GMagicInfo)

#include "GMagicInfo.h"

struct GMagicCreatureSpellInfo : public GMagicInfo {
};
static_assert(sizeof(GMagicCreatureSpellInfo) == 0x58, "GMagicCreatureSpellInfo size mismatch");
