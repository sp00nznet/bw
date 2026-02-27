#pragma once
// CreatureBeliefAboutMobileObject — creature belief about a MobileObject
// Struct layout from bw1-decomp (CreatureMentalBelief.h)
//
// Size: 0x4C bytes (inherits CreatureBelief)

#include "CreatureBelief.h"

struct CreatureBeliefAboutMobileObject : public CreatureBelief {
};
static_assert(sizeof(CreatureBeliefAboutMobileObject) == 0x4C, "CreatureBeliefAboutMobileObject size mismatch");
