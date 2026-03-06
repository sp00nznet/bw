#pragma once
// SetupMP3Button — MP3 playback button (extends SetupButton)
// Size: 0x250 bytes

#include "SetupButton.h"
#include "types.h"

struct SetupMP3Button : public SetupButton {
    uint32_t  field_0x244;  // 0x244
    uint32_t  field_0x248;  // 0x248
    LH3DColor color;        // 0x24C
};
static_assert(sizeof(SetupMP3Button) == 0x250, "SetupMP3Button size mismatch");
