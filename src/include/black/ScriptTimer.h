#pragma once
// ScriptTimer — script-controlled timer entity
// Struct layout from bw1-decomp
//
// Size: 0x28 bytes (same as GameThingWithPos, no new fields)

#include "GameThingWithPos.h"

struct ScriptTimer : public GameThingWithPos {
    // === Overrides of GameThing virtuals ===
    char* GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;

    // === Overrides of GameThingWithPos virtuals ===
    bool32_t IsDeletedWhenReleasedFromScript() override;
    const char* GetText() override;
    bool32_t IsScriptTimer() override;
    uint32_t GetScriptObjectType() override;
};
static_assert(sizeof(ScriptTimer) == 0x28, "ScriptTimer size mismatch");
