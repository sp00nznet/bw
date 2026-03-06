#pragma once
// SetupTabButton — tab selector button (extends SetupButton)
// Size: 0x254 bytes

#include "SetupButton.h"
#include "types.h"

struct SetupTabButton : public SetupButton {
    uint32_t  selected;      // 0x244
    uint32_t  first_in_row;  // 0x248
    uint32_t  last_in_row;   // 0x24C
    LH3DColor color;         // 0x250
};
static_assert(sizeof(SetupTabButton) == 0x254, "SetupTabButton size mismatch");
