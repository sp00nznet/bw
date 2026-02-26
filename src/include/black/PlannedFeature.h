#pragma once
// PlannedFeature — planned feature object (e.g. worship site upgrade)
// Struct layout from bw1-decomp
//
// Size: 0x48 bytes (inherits 0x48 from PlannedMultiMapFixed, no added fields)

#include "PlannedMultiMapFixed.h"

struct PlannedFeature : public PlannedMultiMapFixed {
    // === Overrides of GameThing virtuals ===
    char* GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;

    // === Overrides of PlannedMultiMapFixed virtuals ===
    MultiMapFixed* CreatePlanned(float param1) override;
};
static_assert(sizeof(PlannedFeature) == 0x48, "PlannedFeature size mismatch");
