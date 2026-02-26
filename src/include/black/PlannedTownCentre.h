#pragma once
// PlannedTownCentre — planned town centre building
// Struct layout from bw1-decomp
//
// Size: 0x4C bytes (inherits 0x4C from PlannedAbode, no added fields)

#include "PlannedAbode.h"

struct PlannedTownCentre : public PlannedAbode {
    // === Overrides of GameThing virtuals ===
    char* GetDebugText() override;
    uint32_t GetSaveType() override;
};
static_assert(sizeof(PlannedTownCentre) == 0x4C, "PlannedTownCentre size mismatch");
