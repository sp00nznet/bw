#pragma once
// CreatureFalling — falling creature 3D model (extends LH3DCreature)
// Struct layout from bw1-decomp
// Size: 0x57B8 bytes

#include "LH3DCreature.h"

struct CreatureFalling {
    LH3DCreature super;  // 0x00
};
static_assert(sizeof(CreatureFalling) == 0x57B8, "CreatureFalling size mismatch");
