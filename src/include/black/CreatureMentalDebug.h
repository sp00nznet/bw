#pragma once
// CreatureMentalDebug — debug state for creature mental model
// Struct layout from bw1-decomp (CreatureMentalDebug.h)
//
// Size: 0x4C bytes (inherits 0x8 from Base)

#include "Base.h"

struct CreatureMentalDebug : public Base {
    uint32_t field_0x8;        // 0x08
    uint32_t field_0xc;        // 0x0C
    uint32_t field_0x10;       // 0x10
    uint32_t field_0x14;       // 0x14
    uint32_t field_0x18;       // 0x18
    uint32_t field_0x1c;       // 0x1C
    uint32_t field_0x20;       // 0x20
    uint32_t field_0x24;       // 0x24
    uint32_t field_0x28;       // 0x28
    uint8_t  field_0x2c[0x10]; // 0x2C-0x3B
    uint32_t field_0x3c;       // 0x3C
    uint8_t  field_0x40[0xC];  // 0x40-0x4B
};
static_assert(sizeof(CreatureMentalDebug) == 0x4C, "CreatureMentalDebug size mismatch");
