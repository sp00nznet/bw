#pragma once
// CreatureInnatePersonality — fixed personality trait values
// Struct layout from bw1-decomp (CreatureMental.h)
//
// Size: 0x24 bytes (plain data, no Base inheritance)

#include "types.h"

struct CreatureInnatePersonality {
    float field_0x0;       // 0x00
    float field_0x4;       // 0x04
    float field_0x8;       // 0x08
    float field_0xc;       // 0x0C
    float field_0x10;      // 0x10
    float field_0x14;      // 0x14
    float field_0x18[3];   // 0x18-0x23
};
static_assert(sizeof(CreatureInnatePersonality) == 0x24, "CreatureInnatePersonality size mismatch");
