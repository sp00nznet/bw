#pragma once
#include "SingleMapFixed.h"

struct Creature;
struct GInterfaceStatus;

struct ScriptHighlight : public SingleMapFixed {
    // === Overrides (GameThing) ===
    char*    GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;

    // === Overrides (GameThingWithPos) ===
    bool32_t IsScriptHighlight() override;
    uint32_t GetScriptObjectType() override;
    bool32_t CanBePickedUpByCreature(Creature*) override;

    // === Overrides (Object) ===
    uint32_t Process() override;
    void     Draw() override;
    void     CallVirtualFunctionsForCreation(const MapCoords&) override;

    // === Fields ===
    uint8_t field_0x5c[0x30];  // 0x5C
};
static_assert(sizeof(ScriptHighlight) == 0x8C, "ScriptHighlight size mismatch");
