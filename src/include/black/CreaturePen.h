#pragma once
// CreaturePen — creature pen enclosure (extends CitadelPart)
// Struct layout from bw1-decomp (CreaturePen.h)
//
// Size: 0x8C bytes (extends CitadelPart, no additional fields)
// Overrides: destructor, SaveObject, ConvertToPlanned

#include "CitadelPart.h"

struct CreaturePen : public CitadelPart {
};
static_assert(sizeof(CreaturePen) == 0x8C, "CreaturePen size mismatch");
