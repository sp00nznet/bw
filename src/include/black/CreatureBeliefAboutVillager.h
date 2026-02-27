#pragma once
// CreatureBeliefAboutVillager — creature belief about a Villager
// Struct layout from bw1-decomp (CreatureMentalBelief.h)
//
// Size: 0x4C bytes (inherits CreatureBelief)

#include "CreatureBelief.h"

struct CreatureBeliefAboutVillager : public CreatureBelief {
};
static_assert(sizeof(CreatureBeliefAboutVillager) == 0x4C, "CreatureBeliefAboutVillager size mismatch");
