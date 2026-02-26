#pragma once
// WorshipSiteUpgrade — upgrade decoration attached to a worship site
// Struct layout from bw1-decomp
//
// Size: 0x7C bytes (same as Feature — no new fields)

#include "Feature.h"

struct WorshipSiteUpgrade : public Feature {
    // === Overrides of Base virtuals ===
    void ToBeDeleted(int param) override;

    // === Overrides of GameThing virtuals ===
    GPlayer* GetPlayer() override;

    // === Overrides of GameThingWithPos virtuals ===
    WorshipSite* GetWorshipSite() override;

    // === Overrides of Object virtuals ===
    size_t SaveObject(LHOSFile* param1, const MapCoords* param2) override;

    // === Overrides of MultiMapFixed virtuals ===
    bool IsRepaired() override;
    bool IsBuilt() override;
    bool IsDrawBuilding() override;
    PlannedMultiMapFixed* ConvertToPlanned() override;
};
static_assert(sizeof(WorshipSiteUpgrade) == 0x7C, "WorshipSiteUpgrade size mismatch");
