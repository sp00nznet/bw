#pragma once
// CreatureDesireDependency — desire dependency chain info
// Struct layout from bw1-decomp (CreatureMentalDesire.h)
//
// Size: 0x10 bytes (inherits GBaseInfo)

#include "GBaseInfo.h"

struct CreatureDesireDependency {
    GBaseInfo super;  // 0x0
};
static_assert(sizeof(CreatureDesireDependency) == 0x10, "CreatureDesireDependency size mismatch");
