#pragma once
// Lion — predator base type (lions, leopards, tigers, wolves)
// Struct layout from bw1-decomp
//
// Size: 0x148 bytes (same as Animal — no new fields)
// Vtable: overrides GetDebugText, GetSaveType, CanBeFrighteningToCreature, StandAnimation

#include "Animal.h"

struct Creature;

struct Lion : public Animal {
    // No new fields — same size as Animal

    // === Virtual overrides ===
    virtual char*    GetDebugText() override { return nullptr; }
    virtual uint32_t GetSaveType() override { return 0; }
    virtual bool32_t CanBeFrighteningToCreature(Creature*) override { return 1; }
    virtual uint32_t StandAnimation() override { return 0; }
};
static_assert(sizeof(Lion) == 0x148, "Lion size mismatch");
