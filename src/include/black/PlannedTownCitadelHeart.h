#pragma once
// PlannedTownCitadelHeart — planned town citadel heart
// Struct layout from bw1-decomp
//
// Size: 0x4C bytes in v1.0 (sub_4530C0 allocates 76; the town is at +0x48)

#include "PlannedMultiMapFixed.h"

struct Town;

struct PlannedTownCitadelHeart : public PlannedMultiMapFixed {
    // === Overrides of Base virtuals ===
    void ToBeDeleted(int param) override;

    // === Overrides of GameThing virtuals ===
    Town* GetTown() override;
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

    // === Fields ===
    Town* town;  // 0x48 -- sub_4530C0: this[18], and the plan joins its planned list
};
static_assert(sizeof(PlannedTownCitadelHeart) == 0x4C, "PlannedTownCitadelHeart size mismatch");
