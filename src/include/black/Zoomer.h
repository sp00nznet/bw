#pragma once
// Zoomer / Zoomer3d — smooth interpolation primitives from lh3dlib
// Struct layout from bw1-decomp (lionhead/lh3dlib/development/Zoomer.h)
//
// Zoomer:   0x30 bytes — single-axis smooth interpolation
// Zoomer3d: 0x90 bytes — three-axis smooth interpolation

#include "types.h"

struct Zoomer {
    float    current_value;            // 0x00
    float    destination;              // 0x04
    float    destination_speed;        // 0x08
    float    current_speed;            // 0x0C
    float    time_m2;                  // 0x10
    float    current_time;             // 0x14
    float    duration;                 // 0x18
    float    start_value;              // 0x1C
    float    start_speed;              // 0x20
    LHPoint  non_linear_acceleration;  // 0x24
};
static_assert(sizeof(Zoomer) == 0x30, "Zoomer size mismatch");

struct Zoomer3d {
    Zoomer x;  // 0x00
    Zoomer y;  // 0x30
    Zoomer z;  // 0x60
};
static_assert(sizeof(Zoomer3d) == 0x90, "Zoomer3d size mismatch");
