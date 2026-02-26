#pragma once
// PlannedWorshipSite — planned worship site
// Struct layout from bw1-decomp
//
// Size: 0x48 bytes (inherits 0x48 from PlannedCitadelPart, no added fields)

#include "PlannedCitadelPart.h"

struct PlannedWorshipSite : public PlannedCitadelPart {
    // === Overrides of GameThing virtuals ===
    char* GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;
};
static_assert(sizeof(PlannedWorshipSite) == 0x48, "PlannedWorshipSite size mismatch");
