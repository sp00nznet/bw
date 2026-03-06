#pragma once
// MultiplayerConditionBox — multiplayer win condition dialog (extends DialogBoxBase)
// Size: 0x3C bytes

#include "DialogBoxBase.h"

struct MultiplayerConditionBox : public DialogBoxBase {
    uint8_t field_0x10[0x2C];  // 0x10
};
static_assert(sizeof(MultiplayerConditionBox) == 0x3C, "MultiplayerConditionBox size mismatch");
