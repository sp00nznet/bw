#pragma once
// Plasma — plasma rendering buffer
// Struct layout from bw1-decomp (Plasma.h)
//
// Size: 0xE930 bytes (plain data, no vtable)

#include "types.h"

// Forward declarations
struct LH3DMaterial;
struct LH3DTexture;

struct Plasma {
    LHPoint      points[0x4F7];       // 0x0000
    Point2D      uvs[0x4F7];          // 0x3B94
    uint32_t     indices[3][0x960];    // 0x634C
    LH3DColor    colors[0x4F7];       // 0xD3CC
    LHPoint      field_0xe7a8[0x10];  // 0xE7A8
    LHPoint      field_0xe868[0x10];  // 0xE868
    LH3DTexture* pin_texture;         // 0xE928
    LH3DMaterial* pin_material;       // 0xE92C
};
static_assert(sizeof(Plasma) == 0xE930, "Plasma size mismatch");
