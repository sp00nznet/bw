#pragma once
// CreatureLookState — creature look/gaze state
// Struct layout from bw1-decomp (CreatureLook.h)
//
// Size: 0x38 bytes (plain data, no Base inheritance)

#include "types.h"

struct CreatureLookState {
    uint32_t  field_0x0;   // 0x00
    uint32_t  field_0x4;   // 0x04
    MapCoords coords;      // 0x08
    uint32_t  game_turn;   // 0x14
    float     field_0x18;  // 0x18
    uint32_t  field_0x1c;  // 0x1C
    uint32_t  field_0x20;  // 0x20
    uint32_t  field_0x24;  // 0x24
    uint32_t  field_0x28;  // 0x28
    uint32_t  field_0x2c;  // 0x2C
    uint32_t  field_0x30;  // 0x30
    uint32_t  field_0x34;  // 0x34
};
static_assert(sizeof(CreatureLookState) == 0x38, "CreatureLookState size mismatch");
