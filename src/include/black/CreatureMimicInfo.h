#pragma once
// CreatureMimicInfo — creature mimic metadata
// Struct layout from bw1-decomp
//
// Size: 0x10 bytes (inherits GBaseInfo)
// Linked-list info entry for creature mimic behavior.

#include "GBaseInfo.h"

#include <cstdint>

struct CreatureMimicInfo {
    GBaseInfo super;             // 0x00 -- the RTTI header
    // 176 bytes of payload loaded from info.dat. The field layout is not
    // recovered; the size is, from the loader's record copy (see
    // work/decomp/creature_data.md), and having it right means an array
    // of these indexes correctly.
    uint8_t   payload[0xB0];      // 0x10
};
static_assert(sizeof(CreatureMimicInfo) == 192, "CreatureMimicInfo size mismatch");
