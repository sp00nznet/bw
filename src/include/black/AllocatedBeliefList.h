#pragma once
// AllocatedBeliefList — allocated/pre-allocated belief list
// Struct layout from bw1-decomp (CreatureMentalBeliefs.h)
//
// Size: 0x18 bytes (inherits 0x8 from Base)
// Pre-allocated pool of belief entries for creature memory.

#include "Base.h"

struct AllocatedBeliefList : public Base {
    uint32_t field_0x8;   // 0x08
    uint32_t field_0xc;   // 0x0C
    uint32_t field_0x10;  // 0x10
    uint32_t field_0x14;  // 0x14
};
static_assert(sizeof(AllocatedBeliefList) == 0x18, "AllocatedBeliefList size mismatch");
