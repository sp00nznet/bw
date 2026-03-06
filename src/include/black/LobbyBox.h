#pragma once
// LobbyBox — multiplayer lobby dialog (extends DialogBoxBase)
// Size: 0x8C bytes

#include "DialogBoxBase.h"

struct LobbyBox : public DialogBoxBase {
    uint8_t field_0x10[0x7C];  // 0x10
};
static_assert(sizeof(LobbyBox) == 0x8C, "LobbyBox size mismatch");
