#pragma once
// CreatureBeliefAboutForest — creature belief about a Forest
// Struct layout from bw1-decomp (CreatureMentalBelief.h)
//
// Size: 0x4C bytes (inherits CreatureBelief)

#include "CreatureBelief.h"

struct CreatureBeliefAboutForest : public CreatureBelief {
};
static_assert(sizeof(CreatureBeliefAboutForest) == 0x4C, "CreatureBeliefAboutForest size mismatch");
