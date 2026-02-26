#pragma once
// ScriptMarker — script marker position entity
// Struct layout from bw1-decomp
//
// Size: 0x28 bytes (same as GameThingWithPos, no new fields)

#include "GameThingWithPos.h"

struct ScriptMarker : public GameThingWithPos {
    // === Overrides of Base virtuals ===
    void ToBeDeleted(int param) override;

    // === Overrides of GameThing virtuals ===
    char* GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;

    // === Overrides of GameThingWithPos virtuals ===
    void PhysicsEditorCreate(int param1) override;
    bool32_t IsDeletedWhenReleasedFromScript() override;
    const char* GetText() override;
    bool32_t IsScriptMarker() override;
    uint32_t GetScriptObjectType() override;
};
static_assert(sizeof(ScriptMarker) == 0x28, "ScriptMarker size mismatch");
