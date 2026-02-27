#pragma once
// CreatureCommandState — creature command execution state
// Struct layout from bw1-decomp (CreatureCommandState.h)
//
// Size: 0x2C bytes (inherits 0x8 from Base)

#include "Base.h"

struct CreatureCommandState : public Base {
    uint8_t  field_0x8[0x14];  // 0x08-0x1B
    uint32_t field_0x1c;       // 0x1C
    uint32_t field_0x20;       // 0x20
    uint32_t field_0x24;       // 0x24
    int      field_0x28;       // 0x28
};
static_assert(sizeof(CreatureCommandState) == 0x2C, "CreatureCommandState size mismatch");
