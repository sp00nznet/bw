#pragma once
// CreatureDevelopmentDurationEntry / CreatureDevelopmentPhaseEntry
// Struct layout from bw1-decomp
//
// Both are GBaseInfo-derived (0x10), no new fields, only override destructor + GetBaseInfo

#include "GBaseInfo.h"

struct CreatureDevelopmentDurationEntry : GBaseInfo {
};
static_assert(sizeof(CreatureDevelopmentDurationEntry) == 0x10, "CreatureDevelopmentDurationEntry size mismatch");

struct CreatureDevelopmentPhaseEntry : GBaseInfo {
};
static_assert(sizeof(CreatureDevelopmentPhaseEntry) == 0x10, "CreatureDevelopmentPhaseEntry size mismatch");
