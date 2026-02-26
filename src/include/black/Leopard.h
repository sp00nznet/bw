#pragma once
// Leopard — leopard animal entity (Lion subclass)
// Struct layout from bw1-decomp (file: AnimalLeopard.h, struct: Leopard)
//
// Size: 0x148 bytes (same as Lion — no new fields)

#include "Lion.h"

struct Leopard : public Lion {
    // === Overrides of GameThing virtuals ===
    char* GetDebugText() override;
    uint32_t GetSaveType() override;

    // === Overrides of Object virtuals ===
    uint32_t StandAnimation() override;
};
static_assert(sizeof(Leopard) == 0x148, "Leopard size mismatch");
