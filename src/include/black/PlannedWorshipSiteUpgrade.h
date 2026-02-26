#pragma once
// PlannedWorshipSiteUpgrade — planned worship site upgrade
// Struct layout from bw1-decomp
//
// Size: 0x48 bytes (inherits 0x48 from PlannedFeature, no added fields)

#include "PlannedFeature.h"

struct PlannedWorshipSiteUpgrade : public PlannedFeature {
    // === Overrides of PlannedMultiMapFixed virtuals ===
    MultiMapFixed* CreatePlanned(float param1) override;
};
static_assert(sizeof(PlannedWorshipSiteUpgrade) == 0x48, "PlannedWorshipSiteUpgrade size mismatch");
