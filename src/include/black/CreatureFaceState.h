#pragma once
// CreatureFaceState — creature facial expression state
// Struct layout from bw1-decomp (CreatureFace.h)
//
// Size: 0xC bytes (plain data, no Base inheritance)

#include "types.h"

struct CreatureFaceState {
    int      field_0x0;  // 0x00
    float    field_0x4;  // 0x04
    uint32_t field_0xc;  // 0x08
};
static_assert(sizeof(CreatureFaceState) == 0xC, "CreatureFaceState size mismatch");
