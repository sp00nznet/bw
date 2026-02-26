#pragma once
// GAlignment — player alignment value (good/evil axis)
// Struct layout from bw1-decomp
//
// Size: 0x10 bytes (inherits 0x8 from Base)

#include "Base.h"

struct GAlignment : public Base {
    // No overrides besides implicit destructor

    // === Fields ===
    float value;      // 0x08 — alignment value (-1.0 evil to 1.0 good)
    float field_0xc;  // 0x0C
};
static_assert(sizeof(GAlignment) == 0x10, "GAlignment size mismatch");
