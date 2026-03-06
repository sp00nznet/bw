#pragma once
// ChannelBox — multiplayer channel browser dialog (extends DialogBoxBase)
// Size: 0xAD4 bytes

#include "DialogBoxBase.h"

struct ChannelBox : public DialogBoxBase {
    uint8_t field_0x10[0xAC4];  // 0x10
};
static_assert(sizeof(ChannelBox) == 0xAD4, "ChannelBox size mismatch");
