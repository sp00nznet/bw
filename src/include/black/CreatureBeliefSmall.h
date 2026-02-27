#pragma once
// CreatureBeliefSmall — small/lightweight creature belief
// Struct layout from bw1-decomp (CreatureMentalBelief.h)
//
// Size: 0x4C bytes (inherits CreatureBelief)

#include "CreatureBelief.h"

struct CreatureBeliefSmall : public CreatureBelief {
};
static_assert(sizeof(CreatureBeliefSmall) == 0x4C, "CreatureBeliefSmall size mismatch");
