#pragma once
// GMagicInfo — info for magic spells
// Struct layout from bw1-decomp
//
// Size: 0x58 bytes (extends GBaseInfo at 0x10)
// Referenced by MapShield and SpellShield for spell configuration.

#include "GBaseInfo.h"

struct GMagicInfo : public GBaseInfo {
    int32_t  field_0x10;          // 0x10
    uint8_t  field_0x14[0x44];    // 0x14
};
static_assert(sizeof(GMagicInfo) == 0x58, "GMagicInfo size mismatch");
