#pragma once
// Cow — cow animal entity
// Struct layout from bw1-decomp (file: AnimalCow.h, struct: Cow)
//
// Size: 0x148 bytes (same as Animal — no new fields)
// Simple methods at 0x0041d0xx are packed 16 bytes apart.

#include "Animal.h"

struct Cow : public Animal {
    // === Overrides of GameThing virtuals ===
    char* GetDebugText() override;
    uint32_t GetSaveType() override;

    // === Overrides of GameThingWithPos virtuals ===
    bool32_t IsCow(Creature* creature) override;

    // === Overrides of Living virtuals ===
    bool DecideWhatToDo() override;
};
static_assert(sizeof(Cow) == 0x148, "Cow size mismatch");
