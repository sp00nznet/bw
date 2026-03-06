#pragma once
// SetupSlider — slider control (extends SetupControl)
// Size: 0x250 bytes

#include "SetupControl.h"
#include "LHCoord.h"

struct SetupSlider : public SetupControl {
    float   value;             // 0x23C
    float   drag_start_value;  // 0x240
    LHCoord drag_start;        // 0x244
    int     height;            // 0x24C
};
static_assert(sizeof(SetupSlider) == 0x250, "SetupSlider size mismatch");
