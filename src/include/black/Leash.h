#pragma once
// Leash — leash connection between hand and object
// Struct layout from bw1-decomp (Leash.h)
//
// Size: 0x28 bytes (plain data, NOT Base-derived)

#include "types.h"

struct Leash {
    LHPoint field_0x0;   // 0x00
    LHPoint field_0xc;   // 0x0C
    float   field_0x18;  // 0x18
    LHPoint field_0x1c;  // 0x1C
};
static_assert(sizeof(Leash) == 0x28, "Leash size mismatch");
