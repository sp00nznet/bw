#pragma once
// GestureSystemResult — result of gesture recognition
// Struct layout from bw1-decomp
//
// Size: 0x1 bytes
// Plain data struct, no vtable

#include <cstdint>

struct GestureSystemResult {
    uint8_t field_0x0;  // 0x00
};
static_assert(sizeof(GestureSystemResult) == 0x1, "GestureSystemResult size mismatch");
