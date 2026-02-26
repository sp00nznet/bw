#pragma once
// Tiger — tiger animal entity (Lion subclass)
// Struct layout from bw1-decomp (file: AnimalTiger.h, struct: Tiger)
//
// Size: 0x148 bytes (same as Lion — no new fields)

#include "Lion.h"

struct Tiger : public Lion {
    // === Overrides of GameThing virtuals ===
    char* GetDebugText() override;
    uint32_t GetSaveType() override;

    // === Overrides of Object virtuals ===
    uint32_t StandAnimation() override;
};
static_assert(sizeof(Tiger) == 0x148, "Tiger size mismatch");
