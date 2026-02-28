#pragma once
// ViscousLiquid — fragment mesh/vertex data for viscous liquid rendering
// Struct layout from bw1-decomp
//
// Contains: FragVertex (0x14), FragTriangle (0x58), FragPrimitive (0x14), FragMesh (0x28)
// All plain data, no vtables

#include <cstdint>

struct LH3DPrimitive;
struct LH3DMesh;

struct FragVertex {
    uint8_t field_0x0[0x14];  // 0x00
};
static_assert(sizeof(FragVertex) == 0x14, "FragVertex size mismatch");

struct FragTriangle {
    uint32_t   field_0x0;       // 0x00
    FragVertex vertices[0x3];   // 0x04
    uint8_t    field_0x40[0x18]; // 0x40
};
static_assert(sizeof(FragTriangle) == 0x58, "FragTriangle size mismatch");

struct FragPrimitive {
    LH3DPrimitive* lh3d_primitive; // 0x00
    uint32_t       field_0x4[0x3]; // 0x04
    FragTriangle*  triangle;       // 0x10
};
static_assert(sizeof(FragPrimitive) == 0x14, "FragPrimitive size mismatch");

struct FragMesh {
    uint32_t       field_0x0;       // 0x00
    uint32_t       count;           // 0x04
    uint32_t       field_0x8;       // 0x08
    FragPrimitive* primitives;      // 0x0C
    uint32_t       field_0x10;      // 0x10
    uint8_t        field_0x14[0x14]; // 0x14
};
static_assert(sizeof(FragMesh) == 0x28, "FragMesh size mismatch");
