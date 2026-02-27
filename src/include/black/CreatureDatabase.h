#pragma once
// CreatureDatabase — creature-specific multiplayer database
// Struct layout from bw1-decomp (CreatureDatabase.h)
//
// Size: 0x10 bytes (extends MultiplayerDatabase, no additional fields)
// Overrides: Send

#include "MultiplayerDatabase.h"

struct CreatureDatabase : public MultiplayerDatabase {
    // Override methods (stubs — bodies come from Ghidra decompilation)
    uint32_t Send() override;
};
static_assert(sizeof(CreatureDatabase) == 0x10, "CreatureDatabase size mismatch");
