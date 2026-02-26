#pragma once
// Lion — lion animal entity
// Struct layout from bw1-decomp (file: AnimalLion.h, struct: Lion)
//
// Size: 0x148 bytes (same as Animal — no new fields)
// Simple methods at 0x0041fdxx are packed 16 bytes apart.

#include "Animal.h"

struct Lion : public Animal {
    // === Overrides of GameThing virtuals ===
    char* GetDebugText() override;
    uint32_t GetSaveType() override;

    // === Overrides of GameThingWithPos virtuals ===
    bool32_t CanBeFrighteningToCreature(Creature* creature) override;

    // === Overrides of Object virtuals ===
    uint32_t StandAnimation() override;
};
static_assert(sizeof(Lion) == 0x148, "Lion size mismatch");
