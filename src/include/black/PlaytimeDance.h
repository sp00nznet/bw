#pragma once
// PlaytimeElement — playtime/dance element entity (extends GameThing)
// Size: 0x14 bytes (same as GameThing)

#include "GameThing.h"

struct Town;

struct PlaytimeElement : public GameThing {
    // No new fields

    // === Virtual overrides ===
    virtual Town* GetTown() override { return nullptr; }
    virtual bool  IsFunctional() override { return false; }
    virtual void  ToBeDeleted(int) override {}
};
static_assert(sizeof(PlaytimeElement) == 0x14, "PlaytimeElement size mismatch");
