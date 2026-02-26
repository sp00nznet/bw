#pragma once
// Pig — pig animal entity (Cow subclass)
// Struct layout from bw1-decomp (file: AnimalPig.h, struct: Pig)
//
// Size: 0x148 bytes (same as Cow — no new fields)

#include "Cow.h"

struct Pig : public Cow {
    // === Overrides of GameThing virtuals ===
    char* GetDebugText() override;
    uint32_t GetSaveType() override;

    // === Overrides of Object virtuals ===
    uint32_t StandAnimation() override;
};
static_assert(sizeof(Pig) == 0x148, "Pig size mismatch");
