#pragma once
// HelpText — on-screen help text display
// Struct layout from bw1-decomp (HelpText.h)
//
// Size: 0xBC bytes (extends Base)

#include "Base.h"
#include "types.h"

struct LHRegion {
    float x, y, w, h;
};
static_assert(sizeof(LHRegion) == 0x10, "LHRegion size mismatch");

struct HelpText : public Base {
    char*      str;            // 0x08
    uint32_t   field_0xc;     // 0x0C
    uint32_t   field_0x10;    // 0x10
    uint32_t   field_0x14;    // 0x14
    uint32_t   field_0x18;    // 0x18
    LH3DColor  field_0x1c;    // 0x1C
    LH3DColor  field_0x20;    // 0x20
    LHRegion   field_0x24;    // 0x24
    uint32_t   field_0x34[24]; // 0x34 — 4x6 array
    uint32_t   field_0x94;    // 0x94
    uint32_t   field_0x98;    // 0x98
    uint32_t   field_0x9c;    // 0x9C
    uint32_t   field_0xa0;    // 0xA0
    uint32_t   field_0xa4;    // 0xA4
    uint32_t   field_0xa8;    // 0xA8
    uint32_t   field_0xac;    // 0xAC
    uint32_t   field_0xb0;    // 0xB0
    uint32_t   field_0xb4;    // 0xB4
    uint32_t   field_0xb8;    // 0xB8
};
static_assert(sizeof(HelpText) == 0xBC, "HelpText size mismatch");
