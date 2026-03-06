#pragma once
// EndGameBox — end-of-game results dialog (extends DialogBoxBase)
// Size: 0xBC bytes

#include "DialogBoxBase.h"

struct EndGameBox : public DialogBoxBase {
    uint8_t field_0x10[0xAC];  // 0x10
};
static_assert(sizeof(EndGameBox) == 0xBC, "EndGameBox size mismatch");
