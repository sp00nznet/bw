#pragma once
// PlannedAbode — planned residential building
// Struct layout from bw1-decomp
//
// Size: 0x4C bytes (inherits 0x48 from PlannedMultiMapFixed)

#include "PlannedMultiMapFixed.h"

// Forward declarations
struct Town;

struct PlannedAbode : public PlannedMultiMapFixed {
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
    Town* town;  // 0x48 — owning town
};
static_assert(sizeof(PlannedAbode) == 0x4C, "PlannedAbode size mismatch");
