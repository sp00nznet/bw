#pragma once
// GStreetLight — street light (extends GameThingWithPos)
// Struct layout from bw1-decomp
// Size: 0x2C bytes

#include "GameThingWithPos.h"

struct GPlayer;

struct GStreetLight : public GameThingWithPos {
    uint32_t field_0x28;  // 0x28

    // === Virtual overrides ===
    virtual GPlayer* GetPlayer() override { return nullptr; }
    virtual char*    GetDebugText() override { return nullptr; }
    virtual uint32_t GetSaveType() override { return 0; }
    virtual uint32_t Load(void* file) override { return 0; }
    virtual uint32_t Save(void* file) override { return 0; }
    virtual void     ToBeDeleted(int) override {}
    virtual void     ResolveLoad() override {}
};
static_assert(sizeof(GStreetLight) == 0x2C, "GStreetLight size mismatch");
