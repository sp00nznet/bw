#pragma once
// CreatureDesireAttributeEntry — desire-attribute mapping info
// Struct layout from bw1-decomp (CreatureMentalDesire.h)
//
// Size: 0x10 bytes (inherits GBaseInfo)

#include "GBaseInfo.h"

struct CreatureDesireAttributeEntry {
    GBaseInfo super;  // 0x0
};
static_assert(sizeof(CreatureDesireAttributeEntry) == 0x10, "CreatureDesireAttributeEntry size mismatch");
