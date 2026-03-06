#pragma once
// CreatureLookState — creature gaze/look tracking state
// Struct layout from bw1-decomp
// Size: 0x38 bytes

#include <stdint.h>
#include "types.h"

struct CreatureLookState {
    uint32_t  field_0x0;
    uint32_t  field_0x4;
    MapCoords coords;       // 0x08
    uint32_t  game_turn;    // 0x14
    float     field_0x18;
    uint32_t  field_0x1c;
    uint32_t  field_0x20;
    uint32_t  field_0x24;
    uint32_t  field_0x28;
    uint32_t  field_0x2c;
    uint32_t  field_0x30;
    uint32_t  field_0x34;
};
static_assert(sizeof(CreatureLookState) == 0x38, "CreatureLookState size mismatch");
