#pragma once
// CreatureActionInfo — creature action metadata
// Struct layout from bw1-decomp
//
// Size: 0x10 bytes (inherits GBaseInfo)
// Linked-list info entry for creature action types.

#include "GBaseInfo.h"

#include <cstdint>

struct CreatureActionInfo {
    GBaseInfo super;             // 0x00 -- the RTTI header
    // 252 bytes of payload loaded from info.dat. The field layout is not
    // recovered; the size is, from the loader's record copy (see
    // work/decomp/creature_data.md), and having it right means an array
    // of these indexes correctly.
    uint8_t   payload[0xFC];      // 0x10
};
static_assert(sizeof(CreatureActionInfo) == 268, "CreatureActionInfo size mismatch");
