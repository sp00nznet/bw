#pragma once
// Horse — horse animal entity (Cow subclass)
// Struct layout from bw1-decomp (file: AnimalHorse.h, struct: Horse)
//
// Size: 0x148 bytes (same as Cow — no new fields)

#include "Cow.h"

struct Horse : public Cow {
    // === Overrides of GameThing virtuals ===
    char* GetDebugText() override;
    uint32_t GetSaveType() override;

    // === Overrides of Object virtuals ===
    uint32_t StandAnimation() override;
};
static_assert(sizeof(Horse) == 0x148, "Horse size mismatch");
