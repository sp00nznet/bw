#pragma once
// SetupRect — UI rectangle defined by two LHCoord corners
// Struct layout from bw1-decomp (SetupRect.h)
//
// Size: 0x10 bytes (plain data, no vtable)

#include "LHCoord.h"

struct SetupRect {
    LHCoord p0;  // 0x00
    LHCoord p1;  // 0x08
};
static_assert(sizeof(SetupRect) == 0x10, "SetupRect size mismatch");
