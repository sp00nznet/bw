#pragma once
// CreatureBeliefAboutCitadel — creature belief about a Citadel
// Struct layout from bw1-decomp (CreatureMentalBelief.h)
//
// Size: 0x4C bytes (inherits CreatureBelief)

#include "CreatureBelief.h"

struct CreatureBeliefAboutCitadel : public CreatureBelief {
};
static_assert(sizeof(CreatureBeliefAboutCitadel) == 0x4C, "CreatureBeliefAboutCitadel size mismatch");
