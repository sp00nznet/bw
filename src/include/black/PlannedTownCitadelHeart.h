#pragma once
// PlannedTownCitadelHeart — planned town citadel heart
// Struct layout from bw1-decomp
//
// Size: 0x48 bytes (inherits 0x48 from PlannedMultiMapFixed, no added fields)

#include "PlannedMultiMapFixed.h"

struct PlannedTownCitadelHeart : public PlannedMultiMapFixed {
    // === Overrides of Base virtuals ===
    void ToBeDeleted(int param) override;

    // === Overrides of GameThing virtuals ===
    char* GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;

    // === Overrides of GameThingWithPos virtuals ===
    bool32_t IsWonder() override;

    // === Overrides of PlannedMultiMapFixed virtuals ===
    MultiMapFixed* CreatePlanned(float param1) override;
    MultiMapFixed* CreatePlannedNoFixedCheck(float param1) override;
    bool IsCivic() override;
    ABODE_TYPE GetAbodeType() override;
};
static_assert(sizeof(PlannedTownCitadelHeart) == 0x48, "PlannedTownCitadelHeart size mismatch");
