#pragma once
// CreatureBeliefAboutTown — creature belief about a Town
// Struct layout from bw1-decomp (CreatureMentalBelief.h)
//
// Size: 0x4C bytes (inherits CreatureBelief)

#include "CreatureBelief.h"

struct CreatureBeliefAboutTown : public CreatureBelief {
};
static_assert(sizeof(CreatureBeliefAboutTown) == 0x4C, "CreatureBeliefAboutTown size mismatch");
