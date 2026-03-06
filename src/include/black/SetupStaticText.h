#pragma once
// SetupStaticText — non-interactive text label (extends SetupControl)
// Size: 0x244 bytes

#include "SetupControl.h"
#include "GatheringText.h"

struct SetupStaticText : public SetupControl {
    TEXTJUSTIFY text_justify;       // 0x23C
    int         display_text_size;  // 0x240
};
static_assert(sizeof(SetupStaticText) == 0x244, "SetupStaticText size mismatch");
