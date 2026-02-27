#pragma once
#include "Base.h"

struct GData : public Base {
    uint32_t rand_seed;   // 0x08
    uint32_t field_0xc;   // 0x0C
    uint32_t game_turn;   // 0x10
    uint32_t field_0x14;  // 0x14
    uint32_t field_0x18;  // 0x18
    uint32_t field_0x1c;  // 0x1C
    uint32_t field_0x20;  // 0x20
    uint32_t field_0x24;  // 0x24
};
static_assert(sizeof(GData) == 0x28, "GData size mismatch");
