#pragma once
// PSysProcessInfo — particle system per-frame processing context
// Struct layout from bw1-decomp
//
// Size: 0x3C bytes
// Plain data struct, no vtable

#include "types.h"

struct PSysProcessInfo {
    LHPoint  interface_position;          // 0x00
    LHPoint  field_0xc;                   // 0x0C
    LHPoint  camera_forward_unit_vector;  // 0x18
    LHPoint  hand_velocity;               // 0x24
    float    field_0x30;                  // 0x30
    uint32_t field_0x34;                  // 0x34
    uint8_t  field_0x38;                  // 0x38
};
static_assert(sizeof(PSysProcessInfo) == 0x3C, "PSysProcessInfo size mismatch");
