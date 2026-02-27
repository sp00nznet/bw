#pragma once
// CreatureCommand — creature direct control command
// Struct layout from bw1-decomp (CreatureDirectControl.h)
//
// Size: 0x8 bytes (Base only, no additional fields)

#include "Base.h"

struct CreatureCommand : public Base {
};
static_assert(sizeof(CreatureCommand) == 0x8, "CreatureCommand size mismatch");
