#pragma once
// ProfileEditor — player profile editor dialog (extends DialogBoxBase)
// Size: 0x58 bytes

#include "DialogBoxBase.h"

struct ProfileEditor : public DialogBoxBase {
    uint8_t field_0x10[0x48];  // 0x10
};
static_assert(sizeof(ProfileEditor) == 0x58, "ProfileEditor size mismatch");
