#pragma once
// SetupBigButton — large styled button (extends SetupButton)
// Size: 0x25C bytes

#include "SetupButton.h"
#include "SetupThing.h"

struct SetupBigButton : public SetupButton {
    uint32_t  text_position;  // 0x244
    BBSTYLE   style;          // 0x248
    SetupRect inner_rect;     // 0x24C
};
static_assert(sizeof(SetupBigButton) == 0x25C, "SetupBigButton size mismatch");
