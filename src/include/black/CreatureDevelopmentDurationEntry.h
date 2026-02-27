#pragma once
// CreatureDevelopmentDurationEntry — creature development duration metadata
// Struct layout from bw1-decomp (CreatureDevelopment.h)
//
// Size: 0x10 bytes (inherits GBaseInfo)
// Linked-list info entry for creature development phase durations.

#include "GBaseInfo.h"

struct CreatureDevelopmentDurationEntry {
    GBaseInfo super;  // 0x0
};
static_assert(sizeof(CreatureDevelopmentDurationEntry) == 0x10, "CreatureDevelopmentDurationEntry size mismatch");
