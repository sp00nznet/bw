#pragma once
// StatsDatabase — multiplayer stats database
// Struct layout from bw1-decomp
//
// Size: 0x10 bytes (empty MultiplayerDatabase subclass)
// Inheritance: MultiplayerDatabase (0x10) → StatsDatabase (0x10)

#include "MultiplayerDatabase.h"

struct StatsDatabase : MultiplayerDatabase {
};
static_assert(sizeof(StatsDatabase) == 0x10, "StatsDatabase size mismatch");
