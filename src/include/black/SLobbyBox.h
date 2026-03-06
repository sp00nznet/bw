#pragma once
// GSLobbyBox — server lobby dialog (extends DialogBoxBase)
// Size: 0x2B4 bytes

#include "DialogBoxBase.h"

struct GSLobbyBox : public DialogBoxBase {
    uint8_t field_0x10[0x2A4];  // 0x10
};
static_assert(sizeof(GSLobbyBox) == 0x2B4, "GSLobbyBox size mismatch");
