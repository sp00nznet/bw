#pragma once
// GLandscape — terrain rendering interface
// Struct layout from bw1-decomp (Landscape.h)
//
// Size: 0x8 bytes (plain data, NOT Base-derived)

#include <cstdint>

struct LH3DTexture;
struct LH3DMaterial;

struct GLandscape {
    LH3DTexture*  texture;   // 0x00
    LH3DMaterial* material;  // 0x04
};
static_assert(sizeof(GLandscape) == 0x8, "GLandscape size mismatch");
