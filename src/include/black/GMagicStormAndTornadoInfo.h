#pragma once
// GMagicStormAndTornadoInfo — info for storm and tornado spells
// Struct layout from bw1-decomp (MagicStormAndTornadoInfo.h)
//
// Size: 0x58 bytes (extends GMagicRadiusSpellInfo)

#include "GMagicRadiusSpellInfo.h"

struct GMagicStormAndTornadoInfo : public GMagicRadiusSpellInfo {
};
static_assert(sizeof(GMagicStormAndTornadoInfo) == 0x58, "GMagicStormAndTornadoInfo size mismatch");
