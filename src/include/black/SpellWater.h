#pragma once
// SpellWater — water/rain spell
// Struct layout from bw1-decomp
//
// Size: 0xF4 bytes (inherits 0xEC from Spell)

#include "Spell.h"

struct SpellWater : public Spell {
    // === Overrides of GameThing virtuals ===
    char* GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;

    // === Overrides of Spell virtuals ===
    uint32_t Process() override;

    // === Fields ===
    uint8_t field_0xec[0x8];  // 0xEC
};
static_assert(sizeof(SpellWater) == 0xF4, "SpellWater size mismatch");
