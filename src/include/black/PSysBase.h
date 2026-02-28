#pragma once
// PSysBase — base class for particle system entities
// Struct layout from bw1-decomp (PSysBase.h)
//
// Size: 0x14 bytes (inherits GameThing, no new fields)
// Unlocks Chain, DefensiveShield, PSysHandFX, PSysManager, etc.

#include "GameThing.h"

struct PSysBase : public GameThing {
    // === Overrides of Base virtuals ===
    ~PSysBase() override;

    // === Overrides of GameThing virtuals ===
    char* GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
};
static_assert(sizeof(PSysBase) == 0x14, "PSysBase size mismatch");
