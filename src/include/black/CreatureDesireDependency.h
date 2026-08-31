#pragma once
// CreatureDesireDependency — desire dependency chain info
// Struct layout from bw1-decomp (CreatureMentalDesire.h)
//
// Size: 0x10 bytes (inherits GBaseInfo)

#include "GBaseInfo.h"

#include <cstdint>

struct CreatureDesireDependency {
    GBaseInfo super;             // 0x00 -- the RTTI header
    // 160 bytes of payload loaded from info.dat. The field layout is not
    // recovered; the size is, from the loader's record copy (see
    // work/decomp/creature_data.md), and having it right means an array
    // of these indexes correctly.
    uint8_t   payload[0xA0];      // 0x10
};
static_assert(sizeof(CreatureDesireDependency) == 176, "CreatureDesireDependency size mismatch");
