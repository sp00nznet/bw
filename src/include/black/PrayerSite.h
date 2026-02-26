#pragma once
// PrayerSite — worship location on the map
// Struct layout from bw1-decomp
//
// Size: 0x7C bytes (same as MultiMapFixed — no new fields)
// Vtable: uses MultiMapFixed's vtable layout

#include "MultiMapFixed.h"

struct PrayerSite : public MultiMapFixed {
    // === Overrides of Base virtuals ===
    void ToBeDeleted(int param) override;

    // === Overrides of GameThing virtuals ===
    GPlayer* GetPlayer() override;
    Town* GetTown() override;

    // === Overrides of Object virtuals ===
    uint32_t Process() override;
    int GetMesh() const override;
    bool CreatureMustAvoid(Creature* creature) override;
};
static_assert(sizeof(PrayerSite) == 0x7C, "PrayerSite size mismatch");
