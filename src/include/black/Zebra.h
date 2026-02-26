#pragma once
// Zebra — zebra animal entity (Cow subclass)
// Struct layout from bw1-decomp (file: AnimalZebra.h, struct: Zebra)
//
// Size: 0x148 bytes (same as Cow — no new fields)

#include "Cow.h"

struct Zebra : public Cow {
    // === Overrides of GameThing virtuals ===
    char* GetDebugText() override;
    uint32_t GetSaveType() override;

    // === Overrides of Object virtuals ===
    uint32_t StandAnimation() override;
};
static_assert(sizeof(Zebra) == 0x148, "Zebra size mismatch");
