#pragma once
// SpellHeal — healing spell
// Struct layout from bw1-decomp
//
// Size: 0xEC bytes (inherits 0xEC from Spell, no added fields)

#include "Spell.h"

struct SpellHeal : public Spell {
    // === Overrides ===
    char* GetDebugText() override;
    uint32_t GetSaveType() override;
    int InitWithPos(GameThing* caster, const MapCoords& pos, SpellCastData* data, const PSysProcessInfo& psys) override;
};
static_assert(sizeof(SpellHeal) == 0xEC, "SpellHeal size mismatch");
