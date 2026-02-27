#pragma once
// CreatureDesireSourceTable — desire source table info
// Struct layout from bw1-decomp (CreatureMentalDesire.h)
//
// Size: 0x10 bytes (inherits GBaseInfo)

#include "GBaseInfo.h"

struct CreatureDesireSourceTable {
    GBaseInfo super;  // 0x0
};
static_assert(sizeof(CreatureDesireSourceTable) == 0x10, "CreatureDesireSourceTable size mismatch");
