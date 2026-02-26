#pragma once
// TownArtifact — town artifact entity (inherits directly from GameThing, NOT Object)
// Struct layout from bw1-decomp
//
// Size: 0x40 bytes (inherits 0x14 from GameThing)

#include "GameThing.h"

struct TownArtifact : public GameThing {
    // === Overrides of Base virtuals ===
    void ToBeDeleted(int param) override;

    // === Overrides of GameThing virtuals ===
    GPlayer* GetPlayer() override;
    void SetPlayer(GPlayer* player) override;
    Town* GetTown() override;
    float GetVillagerActivityDesire(Villager* villager) override;
    void SetVillagerActivity(Villager* villager) override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;

    // === Fields ===
    uint8_t field_0x14[0x2C];  // 0x14
};
static_assert(sizeof(TownArtifact) == 0x40, "TownArtifact size mismatch");
