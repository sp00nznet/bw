#pragma once
// PuzzleGame — puzzle mini-game entity (extends GameThingWithPos)
// Size: 0x588 bytes

#include "GameThingWithPos.h"

struct PuzzleGame : public GameThingWithPos {
    uint8_t field_0x28[0x560];  // 0x28
};
static_assert(sizeof(PuzzleGame) == 0x588, "PuzzleGame size mismatch");
