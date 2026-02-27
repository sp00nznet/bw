#pragma once
// CreatureBeliefAboutFlock — creature belief about a Flock
// Struct layout from bw1-decomp (CreatureMentalBelief.h)
//
// Size: 0x4C bytes (inherits CreatureBelief)

#include "CreatureBelief.h"

struct CreatureBeliefAboutFlock : public CreatureBelief {
};
static_assert(sizeof(CreatureBeliefAboutFlock) == 0x4C, "CreatureBeliefAboutFlock size mismatch");
