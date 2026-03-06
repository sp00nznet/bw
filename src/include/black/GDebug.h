#pragma once
// GDebug — debug message system
// Struct layout from bw1-decomp
// Size: 0x2D2A8 bytes

#include "LHTimer.h"

#include <stdint.h>

struct GDebug {
    LHTimer  field_0x0;                      // 0x00
    uint32_t field_0x110;                    // 0x110
    uint32_t field_0x114;                    // 0x114
    uint32_t field_0x118;                    // 0x118
    uint32_t field_0x11c;                    // 0x11C
    uint32_t field_0x120;                    // 0x120
    uint32_t field_0x124;                    // 0x124
    uint32_t field_0x128;                    // 0x128
    uint32_t field_0x12c;                    // 0x12C
    uint32_t field_0x130;                    // 0x130
    uint32_t field_0x134;                    // 0x134
    uint32_t field_0x138;                    // 0x138
    uint32_t field_0x13c;                    // 0x13C
    uint32_t field_0x140;                    // 0x140
    uint32_t field_0x144;                    // 0x144
    uint32_t field_0x148;                    // 0x148
    uint32_t field_0x14c;                    // 0x14C
    uint32_t field_0x150;                    // 0x150
    uint32_t field_0x154;                    // 0x154
    uint32_t field_0x158;                    // 0x158
    uint32_t field_0x15c;                    // 0x15C
    uint8_t  field_0x160[0x2D040];           // 0x160
    uint32_t field_0x2d1a0;                  // 0x2D1A0
    uint8_t  field_0x2d1a4[0xE0];            // 0x2D1A4
    int      field_0x2d284;                  // 0x2D284
    uint32_t field_0x2d288;                  // 0x2D288
    uint32_t field_0x2d28c;                  // 0x2D28C
    uint32_t field_0x2d290;                  // 0x2D290
    uint32_t field_0x2d294;                  // 0x2D294
    uint32_t field_0x2d298;                  // 0x2D298
    uint32_t field_0x2d29c;                  // 0x2D29C
    uint32_t field_0x2d2a0;                  // 0x2D2A0
    uint32_t field_0x2d2a4;                  // 0x2D2A4
};
static_assert(sizeof(GDebug) == 0x2D2A8, "GDebug size mismatch");
