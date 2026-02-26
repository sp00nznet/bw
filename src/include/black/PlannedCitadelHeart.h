#pragma once
// PlannedCitadelHeart — planned citadel heart
// Struct layout from bw1-decomp
//
// Size: 0x48 bytes (inherits 0x48 from PlannedCitadelPart, no added fields)

#include "PlannedCitadelPart.h"

struct PlannedCitadelHeart : public PlannedCitadelPart {
    // === Overrides of GameThingWithPos virtuals ===
    bool32_t CreateBuildingSite() override;

    // === Overrides of PlannedMultiMapFixed virtuals ===
    MultiMapFixed* CreatePlanned(float param1) override;
};
static_assert(sizeof(PlannedCitadelHeart) == 0x48, "PlannedCitadelHeart size mismatch");
