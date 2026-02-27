#pragma once
// CreatureBelief — base class for creature belief objects
// Struct layout from bw1-decomp (CreatureMentalBelief.h)
//
// Size: 0x4C bytes (inherits 0x8 from Base)
// Creature beliefs represent knowledge/opinions about game objects.
// 10 subclass variants exist for different object types.

#include "Base.h"

struct CreatureBelief : public Base {
    uint8_t field_0x8[0x44];  // 0x08-0x4B
};
static_assert(sizeof(CreatureBelief) == 0x4C, "CreatureBelief size mismatch");
