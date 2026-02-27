#pragma once
// CreatureDesireActionEntry — desire-action mapping info
// Struct layout from bw1-decomp (CreatureMentalDesire.h)
//
// Size: 0x10 bytes (inherits GBaseInfo)

#include "GBaseInfo.h"

struct CreatureDesireActionEntry {
    GBaseInfo super;  // 0x0
};
static_assert(sizeof(CreatureDesireActionEntry) == 0x10, "CreatureDesireActionEntry size mismatch");
