#pragma once
// CreatureDesireSourceTable — desire source table info
// Struct layout from bw1-decomp (CreatureMentalDesire.h)
//
// Size: 0x10 bytes (inherits GBaseInfo)

#include "GBaseInfo.h"

#include <cstdint>

struct CreatureDesireSourceTable {
    GBaseInfo super;             // 0x00 -- the RTTI header
    // 148 bytes of payload loaded from info.dat. The field layout is not
    // recovered; the size is, from the loader's record copy (see
    // work/decomp/creature_data.md), and having it right means an array
    // of these indexes correctly.
    uint8_t   payload[0x94];      // 0x10
};
static_assert(sizeof(CreatureDesireSourceTable) == 164, "CreatureDesireSourceTable size mismatch");
