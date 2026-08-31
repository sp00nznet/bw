#pragma once
// CreatureDevelopmentPhaseEntry — creature development phase metadata
// Struct layout from bw1-decomp (CreatureDevelopment.h)
//
// Size: 0x10 bytes (inherits GBaseInfo)
// Linked-list info entry for creature development phases.

#include "GBaseInfo.h"

#include <cstdint>

struct CreatureDevelopmentPhaseEntry {
    GBaseInfo super;             // 0x00 -- the RTTI header
    // 116 bytes of payload loaded from info.dat. The field layout is not
    // recovered; the size is, from the loader's record copy (see
    // work/decomp/creature_data.md), and having it right means an array
    // of these indexes correctly.
    uint8_t   payload[0x74];      // 0x10
};
static_assert(sizeof(CreatureDevelopmentPhaseEntry) == 132, "CreatureDevelopmentPhaseEntry size mismatch");
