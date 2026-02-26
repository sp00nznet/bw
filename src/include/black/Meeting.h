#pragma once
// Meeting — meeting point entity
// Struct layout from bw1-decomp
//
// Size: 0x28 bytes (same as GameThingWithPos, no new fields)

#include "GameThingWithPos.h"

struct Meeting : public GameThingWithPos {
    // === Overrides of Base virtuals ===
    void ToBeDeleted(int param) override;

    // === Overrides of GameThing virtuals ===
    GPlayer* GetPlayer() override;
    void RemoveDance() override;
    Town* GetTown() override;
};
static_assert(sizeof(Meeting) == 0x28, "Meeting size mismatch");
