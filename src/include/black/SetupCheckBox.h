#pragma once
// SetupCheckBox — checkbox toggle widget (extends SetupButton)
// Size: 0x260 bytes

#include "SetupButton.h"
#include "SetupThing.h"

struct SetupCheckBox : public SetupButton {
    uint32_t  text_position;  // 0x244
    BBSTYLE   style;          // 0x248
    bool      checked;        // 0x24C
    SetupRect inner_rect;     // 0x250
};
static_assert(sizeof(SetupCheckBox) == 0x260, "SetupCheckBox size mismatch");
