#pragma once
// CreatureDesireForType — desire-for-type mapping info
// Struct layout from bw1-decomp (CreatureMentalDesire.h)
//
// Size: 0x10 bytes (inherits GBaseInfo)

#include "GBaseInfo.h"

struct CreatureDesireForType {
    GBaseInfo super;  // 0x0
};
static_assert(sizeof(CreatureDesireForType) == 0x10, "CreatureDesireForType size mismatch");
