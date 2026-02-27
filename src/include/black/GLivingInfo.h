#pragma once
// GLivingInfo — info for living entities (villagers, animals, creature)
// Struct layout from bw1-decomp (LivingInfo.h)
//
// Size: 0x1F4 bytes (extends GMobileWallHugInfo at 0x120)

#include "GMobileWallHugInfo.h"

struct GLivingInfo : public GMobileWallHugInfo {
    uint32_t field_0x120;       // 0x120
    uint8_t  move_to_state;     // 0x124
    float    life;              // 0x128
    float    field_0x12c;       // 0x12C
    float    field_0x130;       // 0x130
    int      field_0x134;       // 0x134
    uint32_t teen_age;          // 0x138
    uint32_t middle_age;        // 0x13C
    uint32_t old_age;           // 0x140
    uint32_t field_0x144;       // 0x144
    uint32_t field_0x148;       // 0x148
    uint32_t field_0x14c;       // 0x14C
    uint32_t field_0x150;       // 0x150
    uint32_t field_0x154;       // 0x154
    uint32_t field_0x158;       // 0x158
    uint32_t field_0x15c;       // 0x15C
    uint32_t field_0x160;       // 0x160
    uint32_t field_0x164;       // 0x164
    uint32_t field_0x168;       // 0x168
    uint32_t field_0x16c;       // 0x16C
    uint8_t  field_0x170[0x8];  // 0x170-0x177
    uint32_t field_0x178;       // 0x178
    uint8_t  field_0x17c[0x34]; // 0x17C-0x1AF
    uint32_t field_0x1b0;       // 0x1B0
    uint32_t field_0x1b4;       // 0x1B4
    uint8_t  field_0x1b8[0x3C]; // 0x1B8-0x1F3
};
static_assert(sizeof(GLivingInfo) == 0x1F4, "GLivingInfo size mismatch");
