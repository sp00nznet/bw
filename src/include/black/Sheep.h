#pragma once
// Sheep — sheep animal entity (Cow subclass)
// Struct layout from bw1-decomp (file: AnimalSheep.h, struct: Sheep)
//
// Size: 0x148 bytes (same as Cow — no new fields)

#include "Cow.h"

struct Sheep : public Cow {
    // === Overrides of GameThing virtuals ===
    char* GetDebugText() override;
    uint32_t GetSaveType() override;

    // === Overrides of Object virtuals ===
    uint32_t StandAnimation() override;
};
static_assert(sizeof(Sheep) == 0x148, "Sheep size mismatch");
