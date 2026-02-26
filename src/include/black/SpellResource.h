#pragma once
// SpellResource — resource creation spell (food/wood)
// Struct layout from bw1-decomp
//
// Size: 0xEC bytes (inherits 0xEC from Spell, no added fields)

#include "Spell.h"

struct SpellResource : public Spell {
    // === Overrides of GameThing virtuals ===
    char* GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;

    // === Overrides of Spell virtuals ===
    void HasEnoughChantsAndLifeForRecast() override;
    void SpellEvent(const SpellEventInfo& info) override;
};
static_assert(sizeof(SpellResource) == 0xEC, "SpellResource size mismatch");
