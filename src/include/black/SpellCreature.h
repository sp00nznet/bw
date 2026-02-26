#pragma once
// SpellCreature — creature summoning spell
// Struct layout from bw1-decomp
//
// Size: 0xEC bytes (inherits 0xEC from Spell, no added fields)

#include "Spell.h"

struct SpellCreature : public Spell {
    // === Overrides of GameThing virtuals ===
    char* GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;

    // === Overrides of Spell virtuals ===
    void ProcessSpellSeed() override;
    uintptr_t GetCreatureCastOn() override;
    uint32_t Process() override;
    void CloseDown() override;
    int InitWithObject(GameThing* caster, Object* target, SpellCastData* data, const PSysProcessInfo& psys) override;
};
static_assert(sizeof(SpellCreature) == 0xEC, "SpellCreature size mismatch");
