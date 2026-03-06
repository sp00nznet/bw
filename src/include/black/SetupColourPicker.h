#pragma once
// SetupColourPicker — color picker widget (extends SetupButton)
// Size: 0x258 bytes

#include "SetupButton.h"
#include "types.h"

struct LH3DMaterial;

struct SetupColourPicker : public SetupButton {
    LH3DColor     color_0x244;       // 0x244
    LH3DMaterial* material;          // 0x248
    bool          brightness_slider; // 0x24C
    float         slider_position;   // 0x250
    LH3DColor     color;             // 0x254
};
static_assert(sizeof(SetupColourPicker) == 0x258, "SetupColourPicker size mismatch");
