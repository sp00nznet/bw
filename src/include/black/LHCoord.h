#pragma once
// LHCoord — 2D integer coordinate
// Struct layout from lionhead lh3dlib

#include <cstdint>

struct LHCoord {
    int x;  // 0x0
    int y;  // 0x4
};
static_assert(sizeof(LHCoord) == 0x8, "LHCoord size mismatch");
