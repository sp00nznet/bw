#pragma once
// GestureSystemDataList — list of gesture recognition data
// Struct layout from bw1-decomp
//
// Size: 0x10 bytes
// Inheritance: Base (0x8) → GestureSystemDataList (0x10)

#include "Base.h"

struct GestureSystemDataList : Base {
    uint8_t field_0x8[0x8];  // 0x08
};
static_assert(sizeof(GestureSystemDataList) == 0x10, "GestureSystemDataList size mismatch");
