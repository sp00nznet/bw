#pragma once
// SpellWithObjects — spell that creates/manages objects in the world
// Struct layout from bw1-decomp
//
// Size: 0xF4 bytes (inherits 0xEC from Spell)
// Vtable: 0x558 bytes (extends Spell's 0x554 with 1 method)

#include "Spell.h"

struct SpellWithObjects : public Spell {
    // === Overrides of Base virtuals ===
    void ToBeDeleted(int param) override;

    // === Overrides of GameThing virtuals ===
    char* GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;

    // === Overrides of Spell virtuals ===
    void ProcessSpellSeed() override;
    uint32_t Process() override;
    void CloseDown() override;
    int GetMaxObjectsToCreate() override;

    // === New virtual methods (vtable 0x554) ===
    virtual bool GetSetObjectsDyingOnCloseDown();

    // === Fields ===
    uint8_t field_0xec[0x8];  // 0xEC
};
static_assert(sizeof(SpellWithObjects) == 0xF4, "SpellWithObjects size mismatch");
