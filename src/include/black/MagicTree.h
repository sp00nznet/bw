#pragma once
// MagicTree — sacred/magic tree with special fire behavior
// Struct layout from bw1-decomp
//
// Size: 0x6C bytes (same as Tree — no new fields)
// Simple methods at 0x005fcfxx are packed 16 bytes apart.
// Complex methods at 0x005fd0xx-0x005fd1xx.

#include "Tree.h"

struct MagicTree : public Tree {
    // === Overrides of Base virtuals ===
    void ToBeDeleted(int param) override;

    // === Overrides of GameThing virtuals ===
    GPlayer* GetPlayer() override;
    char* GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;

    // === Overrides of GameThingWithPos virtuals ===
    IMPRESSIVE_TYPE GetImpressiveType() override;

    // === Overrides of Object virtuals ===
    void StartOnFire() override;
    void EndOnFire() override;
};
static_assert(sizeof(MagicTree) == 0x6C, "MagicTree size mismatch");
