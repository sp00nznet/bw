#pragma once
// SetupButton — clickable button widget (extends SetupControl)
// Size: 0x244 bytes

#include "SetupControl.h"

struct SetupButton : public SetupControl {
    bool     pressed;       // 0x23C
    int      field_0x240;   // 0x240
};
static_assert(sizeof(SetupButton) == 0x244, "SetupButton size mismatch");
