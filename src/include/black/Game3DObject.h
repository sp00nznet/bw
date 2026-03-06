#pragma once
// Game3DObject — 3D object wrapper extending LH3DObject
// Struct layout from bw1-decomp
// Size: 0x7C bytes

#include <stdint.h>

struct LH3DObject;
struct MapCoords;

// LH3DObject is 0x7C bytes (opaque engine type)
struct LH3DObject {
    uint8_t data[0x7C];  // 0x00 — opaque engine data
};
static_assert(sizeof(LH3DObject) == 0x7C, "LH3DObject size mismatch");

struct Game3DObject {
    LH3DObject super;  // 0x00
};
static_assert(sizeof(Game3DObject) == 0x7C, "Game3DObject size mismatch");
