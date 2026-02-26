#pragma once
// PlannedCreaturePen — planned creature pen
// Struct layout from bw1-decomp
//
// Size: 0x48 bytes (inherits 0x48 from PlannedCitadelPart, no added fields)

#include "PlannedCitadelPart.h"

struct PlannedCreaturePen : public PlannedCitadelPart {
    // === Overrides of GameThingWithPos virtuals ===
    const char* GetText() override;
};
static_assert(sizeof(PlannedCreaturePen) == 0x48, "PlannedCreaturePen size mismatch");
