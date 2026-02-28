#pragma once
// GestureSystemData — gesture recognition data storage
// Struct layout from bw1-decomp (GestureSystemData.h)
//
// Size: 0x65C bytes (Base-derived, opaque body)

#include "Base.h"

struct GestureSystemData : Base {
    uint8_t field_0x8[0x654];  // 0x08
};
static_assert(sizeof(GestureSystemData) == 0x65C, "GestureSystemData size mismatch");
