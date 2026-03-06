#pragma once
// CreatureFaceState — creature facial expression state
// Struct layout from bw1-decomp
// Size: 0xC bytes

#include <stdint.h>

struct CreatureFaceState {
    int      field_0x0;
    float    field_0x4;
    uint32_t field_0xc;
};
static_assert(sizeof(CreatureFaceState) == 0xC, "CreatureFaceState size mismatch");
