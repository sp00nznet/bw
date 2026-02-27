#pragma once
// CreatureDevelopmentPhaseEntry — creature development phase metadata
// Struct layout from bw1-decomp (CreatureDevelopment.h)
//
// Size: 0x10 bytes (inherits GBaseInfo)
// Linked-list info entry for creature development phases.

#include "GBaseInfo.h"

struct CreatureDevelopmentPhaseEntry {
    GBaseInfo super;  // 0x0
};
static_assert(sizeof(CreatureDevelopmentPhaseEntry) == 0x10, "CreatureDevelopmentPhaseEntry size mismatch");
