#pragma once
// PFootball — football pitch (playtime structure)
// Struct layout from bw1-decomp
//
// Size: 0x7C bytes (same as MultiMapFixed — no new fields)
// Simple methods at 0x006438xx-0x006439xx are packed 16 bytes apart.
// Complex methods at 0x00643fxx-0x006442xx.

#include "MultiMapFixed.h"

struct PFootball : public MultiMapFixed {
    // === Overrides of GameThing virtuals ===
    GPlayer* GetPlayer() override;

    // === Overrides of Object virtuals ===
    int GetMesh() const override;
    void Draw() override;
    void CallVirtualFunctionsForCreation(const MapCoords& coords) override;
    size_t SaveObject(LHOSFile* param1, const MapCoords* param2) override;

    // === Overrides of MultiMapFixed virtuals ===
    bool IsPlaytimeStructure() override;
    bool IsPlaytimeStarted() override;
    bool AddPlaytimeVillager(Villager* villager) override;
    bool IsRepaired() override;
    bool IsBuilt() override;
};
static_assert(sizeof(PFootball) == 0x7C, "PFootball size mismatch");
