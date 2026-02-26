#pragma once
// Dove — dove animal entity
// Struct layout from bw1-decomp (file: AnimalDove.h, struct: Dove)
//
// Size: 0x148 bytes (same as Animal — no new fields)
// Simple methods at 0x0041ddxx are packed 16 bytes apart.
// Complex methods at 0x0041bdxx-0x0041f6xx.

#include "Animal.h"

struct Dove : public Animal {
    // === Overrides of GameThing virtuals ===
    char* GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;

    // === Overrides of GameThingWithPos virtuals ===
    bool32_t CanBePickedUpByCreature(Creature* creature) override;
    bool32_t CanBeStompedOnByCreature(Creature* creature) override;
    bool32_t CanBePoodOn(Creature* creature) override;
    float GetHowMuchCreatureWantsToLookAtMe() override;
    uint32_t GetScriptObjectType() override;

    // === Overrides of Object virtuals ===
    void Draw() override;
    void CallVirtualFunctionsForCreation(const MapCoords& coords) override;
    uint32_t StandAnimation() override;
};
static_assert(sizeof(Dove) == 0x148, "Dove size mismatch");

// SpellDove — summoned dove (spell variant)
struct SpellDove : public Dove {
    // === Overrides of GameThing virtuals ===
    char* GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;

    // === Overrides of Object virtuals ===
    bool SetDying() override;
    uint32_t StandAnimation() override;

    // === Overrides of Living virtuals ===
    uint32_t GetNumTurnsToDieOver() override;
};
static_assert(sizeof(SpellDove) == 0x148, "SpellDove size mismatch");
