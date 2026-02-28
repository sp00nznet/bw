#pragma once
// CameraExclusion — camera exclusion zone
// Struct layout from bw1-decomp
//
// Size: 0x28 bytes
// Plain data struct with linked list pointers, no vtable

#include "types.h"

struct CameraExclusion {
    CameraExclusion* next;      // 0x00
    CameraExclusion* prev;      // 0x04
    uint32_t         field_0x8; // 0x08
    LHPoint          field_0xc; // 0x0C
    float            field_0x18; // 0x18
    float            field_0x1c; // 0x1C
    uint32_t         type;       // 0x20
    uint32_t         field_0x24; // 0x24
};
static_assert(sizeof(CameraExclusion) == 0x28, "CameraExclusion size mismatch");
