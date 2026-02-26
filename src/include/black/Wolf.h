#pragma once
// Wolf and SpellWolf — wolf animal entities (Lion subclasses)
// Struct layout from bw1-decomp (file: AnimalWolf.h)
//
// Size: 0x148 bytes (same as Lion — no new fields)

#include "Lion.h"

// SpellWolf — summoned wolf (spell variant, more overrides)
struct SpellWolf : public Lion {
    // === Overrides of GameThing virtuals ===
    GPlayer* GetPlayer() override;
    void SetPlayer(GPlayer* player) override;
    char* GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;

    // === Overrides of Object virtuals ===
    void Draw() override;
    void CallVirtualFunctionsForCreation(const MapCoords& coords) override;
    bool SetDying() override;
    uint32_t StandAnimation() override;

    // === Overrides of MobileWallHug virtuals ===
    void SetSpeed(int speed) override;

    // === Overrides of Living virtuals ===
    uint32_t GetNumTurnsToDieOver() override;
};
static_assert(sizeof(SpellWolf) == 0x148, "SpellWolf size mismatch");

// Wolf — normal wolf animal
struct Wolf : public Lion {
    // === Overrides of GameThing virtuals ===
    char* GetDebugText() override;
    uint32_t GetSaveType() override;

    // === Overrides of Object virtuals ===
    uint32_t StandAnimation() override;
};
static_assert(sizeof(Wolf) == 0x148, "Wolf size mismatch");
