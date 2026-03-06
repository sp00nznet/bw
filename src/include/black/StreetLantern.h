#pragma once
// GStreetLantern — street lantern light source (extends Object)
// Struct layout from bw1-decomp
// Size: 0x64 bytes

#include "Object.h"

struct Creature;

struct GStreetLantern : public Object {
    uint8_t field_0x54[0x10];  // 0x54

    // === Virtual overrides ===
    virtual char*    GetDebugText() override { return nullptr; }
    virtual uint32_t GetSaveType() override { return 0; }
    virtual uint32_t Load(void* file) override { return 0; }
    virtual uint32_t Save(void* file) override { return 0; }
    virtual void     ToBeDeleted(int) override {}
    virtual bool32_t IsStreetLantern() override { return 1; }
    virtual uint32_t GetScriptObjectType() override { return 0; }
    virtual void     Draw() override {}
    virtual void     CallVirtualFunctionsForCreation(const MapCoords&) override {}
    virtual bool32_t CanBeStompedOnByCreature(Creature*) override { return 0; }
};
static_assert(sizeof(GStreetLantern) == 0x64, "GStreetLantern size mismatch");
