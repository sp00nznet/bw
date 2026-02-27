#pragma once
// PlayerMessage — player message display (extends Prss)
// Struct layout from bw1-decomp (PlayerMessage.h)
//
// Size: 0x10 bytes (extends Prss, no additional fields)
// Overrides: ProcessTurn, Display

#include "Prss.h"

struct PlayerMessage : public Prss {
    int  ProcessTurn() override;
    void Display() override;
};
static_assert(sizeof(PlayerMessage) == 0x10, "PlayerMessage size mismatch");
