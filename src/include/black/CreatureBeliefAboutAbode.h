#pragma once
// CreatureBeliefAboutAbode — creature belief about an Abode
// Struct layout from bw1-decomp (CreatureMentalBelief.h)
//
// Size: 0x4C bytes (inherits CreatureBelief)

#include "CreatureBelief.h"

struct CreatureBeliefAboutAbode : public CreatureBelief {
};
static_assert(sizeof(CreatureBeliefAboutAbode) == 0x4C, "CreatureBeliefAboutAbode size mismatch");
