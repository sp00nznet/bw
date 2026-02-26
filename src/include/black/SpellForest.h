#pragma once
// SpellForest — forest creation spell
// Struct layout from bw1-decomp
//
// Size: 0xEC bytes (inherits 0xEC from Spell, no added fields)

#include "Spell.h"

struct SpellForest : public Spell {
    // === Overrides of Base virtuals ===
    void ToBeDeleted(int param) override;

    // === Overrides of GameThing virtuals ===
    char* GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;

    // === Overrides of Spell virtuals ===
    void HasEnoughChantsAndLifeForRecast() override;
    uint32_t Process() override;
    void SpellEvent(const SpellEventInfo& info) override;
    void CloseDown() override;
    int InitWithPos(GameThing* caster, const MapCoords& pos, SpellCastData* data, const PSysProcessInfo& psys) override;
    float CalculateCostToMaintain() override;
    void AdjustSpellSeedPos(MapCoords* pos) override;
    void SetMaxObjectsToCreate(int value) override;
    int GetMaxObjectsToCreate() override;
};
static_assert(sizeof(SpellForest) == 0xEC, "SpellForest size mismatch");
