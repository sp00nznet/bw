#pragma once
// CreatureBeliefAboutCreature — creature belief about another Creature
// Struct layout from bw1-decomp (CreatureMentalBelief.h)
//
// Size: 0x4C bytes (inherits CreatureBelief)

#include "CreatureBelief.h"

struct CreatureBeliefAboutCreature : public CreatureBelief {
};
static_assert(sizeof(CreatureBeliefAboutCreature) == 0x4C, "CreatureBeliefAboutCreature size mismatch");
