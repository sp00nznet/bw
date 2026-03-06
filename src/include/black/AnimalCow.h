#pragma once
// Cow — herbivore base type (cows, goats, sheep, pigs, etc.)
// Struct layout from bw1-decomp
//
// Size: 0x148 bytes (same as Animal — no new fields)
// Vtable: overrides GetDebugText, GetSaveType, IsCow, DecideWhatToDo

#include "Animal.h"

struct Creature;

struct Cow : public Animal {
    // No new fields — same size as Animal

    // === Virtual overrides ===
    virtual char*    GetDebugText() override { return nullptr; }
    virtual uint32_t GetSaveType() override { return 0; }
    virtual bool32_t IsCow(Creature*) override { return 1; }
    virtual bool     DecideWhatToDo() override { return false; }
};
static_assert(sizeof(Cow) == 0x148, "Cow size mismatch");
