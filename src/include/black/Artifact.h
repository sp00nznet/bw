#pragma once
// TownArtifact — artifact placed in a town (extends GameThing)
// Struct layout from bw1-decomp
// Size: 0x40 bytes

#include "GameThing.h"

struct GPlayer;
struct Town;
struct Villager;

struct TownArtifact : public GameThing {
    uint8_t field_0x14[0x2C];  // 0x14

    // === Virtual overrides ===
    virtual GPlayer* GetPlayer() override { return nullptr; }
    virtual void     SetPlayer(GPlayer*) override {}
    virtual Town*    GetTown() override { return nullptr; }
    virtual float    GetVillagerActivityDesire(Villager*) override { return 0.0f; }
    virtual uint32_t SetVillagerActivity(Villager*) override { return 0; }
    virtual char*    GetDebugText() override { return nullptr; }
    virtual uint32_t GetSaveType() override { return 0; }
    virtual uint32_t Load(void* file) override { return 0; }
    virtual uint32_t Save(void* file) override { return 0; }
    virtual void     ToBeDeleted(int) override {}
};
static_assert(sizeof(TownArtifact) == 0x40, "TownArtifact size mismatch");
