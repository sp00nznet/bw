#pragma once
// GatheringBox — multiplayer gathering lobby (extends DialogBoxBase)
// Size: 0xF0 bytes

#include "DialogBoxBase.h"

struct GatheringBox : public DialogBoxBase {
    uint8_t field_0x10[0xE0];  // 0x10
};
static_assert(sizeof(GatheringBox) == 0xF0, "GatheringBox size mismatch");
