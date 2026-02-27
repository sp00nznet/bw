#pragma once
// LandFeature — landscape feature marker
// Struct layout from bw1-decomp (LandFeature.h)
//
// Size: 0x1 byte (minimal opaque placeholder)

#include <cstdint>

struct LandFeature {
    uint8_t field_0x0;  // 0x00
};
static_assert(sizeof(LandFeature) == 0x1, "LandFeature size mismatch");
