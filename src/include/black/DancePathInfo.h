#pragma once
// DancePathInfo — dance path data for villager celebrations
// Struct layout from bw1-decomp
//
// Size: 0x20 bytes (inherits 0x14 from GameThing)

#include "GameThing.h"

struct DancePathInfo : public GameThing {
    // No overrides besides implicit destructor

    // === Fields ===
    uint8_t  field_0x14;           // 0x14
    uint8_t  field_0x15[0x3];      // 0x15 — padding/data
    uint8_t  (*field_0x18)[0xC];   // 0x18 — pointer to array of 12-byte entries
    uint32_t field_0x1c;           // 0x1C
};
static_assert(sizeof(DancePathInfo) == 0x20, "DancePathInfo size mismatch");
