#pragma once
// PhysicsObject — physics simulation for game objects
// Struct layout from bw1-decomp (PhysicsObject.h)
//
// Size: 0x1DC bytes (extends Base)

#include "Base.h"

struct PhysicsObject : public Base {
    uint8_t  field_0x8[0x1A0]; // 0x08
    float    field_0x1a8;      // 0x1A8
    uint32_t field_0x1ac;      // 0x1AC
    uint32_t field_0x1b0;      // 0x1B0
    uint32_t field_0x1b4;      // 0x1B4
    float    field_0x1b8;      // 0x1B8
    uint32_t field_0x1bc;      // 0x1BC
    uint32_t field_0x1c0;      // 0x1C0
    uint32_t field_0x1c4;      // 0x1C4
    float    field_0x1c8;      // 0x1C8
    uint32_t field_0x1cc;      // 0x1CC
    uint32_t field_0x1d0;      // 0x1D0
    uint32_t field_0x1d4;      // 0x1D4
    uint32_t field_0x1d8;      // 0x1D8
};
static_assert(sizeof(PhysicsObject) == 0x1DC, "PhysicsObject size mismatch");
