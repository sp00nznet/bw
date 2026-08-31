#pragma once
// CreatureSourceBoundsInfo — creature source bounds metadata
// Struct layout from bw1-decomp
//
// Size: 0x10 bytes (inherits GBaseInfo)
// Linked-list info entry for creature source bounds.

#include "GBaseInfo.h"

#include <cstdint>

struct CreatureSourceBoundsInfo {
    GBaseInfo super;             // 0x00 -- the RTTI header
    // 12 bytes of payload loaded from info.dat. The field layout is not
    // recovered; the size is, from the loader's record copy (see
    // work/decomp/creature_data.md), and having it right means an array
    // of these indexes correctly.
    uint8_t   payload[0xC];      // 0x10
};
static_assert(sizeof(CreatureSourceBoundsInfo) == 28, "CreatureSourceBoundsInfo size mismatch");
