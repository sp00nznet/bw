#pragma once
// CreatureInitialDesireInfo — creature initial desire metadata
// Struct layout from bw1-decomp
//
// Size: 0x10 bytes (inherits GBaseInfo)
// Linked-list info entry for creature initial desire values.

#include "GBaseInfo.h"

#include <cstdint>

struct CreatureInitialDesireInfo {
    GBaseInfo super;             // 0x00 -- the RTTI header
    // 432 bytes of payload loaded from info.dat. Four string fields are pinned
    // by sub_4C3030, the learning-feedback reporter, which formats them
    // directly out of this record at 448-byte stride; the rest is unmapped.
    uint8_t   payload[0x70];     // 0x10
    char      name[0x40];        // 0x80 -- the desire's name, e.g. for debug text
    uint8_t   field_0xc0[0x10];  // 0xC0
    char      text_a[0x80];      // 0xD0
    uint8_t   field_0x150[0x10]; // 0x150
    char      text_b[0x40];      // 0x160
    char      text_c[0x30];      // 0x1A0
    uint8_t   tail[0x10];        // 0x1D0
};
static_assert(sizeof(CreatureInitialDesireInfo) == 448, "CreatureInitialDesireInfo size mismatch");
