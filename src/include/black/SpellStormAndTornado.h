#pragma once
// SpellStormAndTornado — storm and tornado spells
// Struct layout from bw1-decomp
//
// Size: 0xEC bytes (inherits 0xEC from Spell, no added fields)

#include "Spell.h"

struct SpellStormAndTornado : public Spell {
    // === Overrides of Base virtuals ===
    void ToBeDeleted(int param) override;

    // === Overrides of GameThing virtuals ===
    float GetRadius() override;
    float Get2DRadius() override;
    char* GetDebugText() override;
    uint32_t GetSaveType() override;
};
static_assert(sizeof(SpellStormAndTornado) == 0xEC, "SpellStormAndTornado size mismatch");
