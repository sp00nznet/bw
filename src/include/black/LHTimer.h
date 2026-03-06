#pragma once
// LHTimer — engine timer utility
// Struct layout from bw1-decomp
// Size: 0x110 bytes

#include <stdint.h>

struct LHTimer {
    uint8_t  field_0x0[0x100];       // 0x00
    uint32_t tick_count;             // 0x100
    int      elapsed_time;           // 0x104
    float    speed_up_factor;        // 0x108
    float    speed_up_factor_2;      // 0x10C
};
static_assert(sizeof(LHTimer) == 0x110, "LHTimer size mismatch");
