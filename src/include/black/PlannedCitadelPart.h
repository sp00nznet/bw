#pragma once
// PlannedCitadelPart — planned citadel structural component
// Struct layout from bw1-decomp
//
// Size: 0x48 bytes (inherits 0x48 from PlannedMultiMapFixed, no added fields)

#include "PlannedMultiMapFixed.h"

struct PlannedCitadelPart : public PlannedMultiMapFixed {
    // === Overrides of Base virtuals ===
    void ToBeDeleted(int param) override;

    // === Overrides of GameThing virtuals ===
    char* GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;
};
static_assert(sizeof(PlannedCitadelPart) == 0x48, "PlannedCitadelPart size mismatch");
