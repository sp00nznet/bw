#pragma once
// SetupLandscapeBox — landscape selection dialog for multiplayer setup
// Size: 0x10 bytes

#include "DialogBoxBase.h"

struct SetupLandscapeBox : public DialogBoxBase {
    // No new fields
};
static_assert(sizeof(SetupLandscapeBox) == 0x10, "SetupLandscapeBox size mismatch");
