#pragma once
// Playtime — playtime activity tracker
// Struct layout from bw1-decomp
//
// Size: 0x14 bytes (same as GameThing — no added fields)

#include "GameThing.h"

struct Playtime : public GameThing {
    // No overrides besides implicit destructor
    // No additional fields
};
static_assert(sizeof(Playtime) == 0x14, "Playtime size mismatch");
