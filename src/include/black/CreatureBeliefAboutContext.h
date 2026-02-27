#pragma once
// CreatureBeliefAboutContext — creature belief about a context
// Struct layout from bw1-decomp (CreatureMentalBelief.h)
//
// Size: 0x4C bytes (inherits CreatureBelief)

#include "CreatureBelief.h"

struct CreatureBeliefAboutContext : public CreatureBelief {
};
static_assert(sizeof(CreatureBeliefAboutContext) == 0x4C, "CreatureBeliefAboutContext size mismatch");
