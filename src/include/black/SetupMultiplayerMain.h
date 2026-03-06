#pragma once
// SetupMultiplayerMain — multiplayer setup dialog (extends DialogBoxBase)
// Size: 0x10 bytes

#include "DialogBoxBase.h"

struct SetupMultiplayerMain : public DialogBoxBase {
    // No new fields
};
static_assert(sizeof(SetupMultiplayerMain) == 0x10, "SetupMultiplayerMain size mismatch");
