#pragma once
// NewProfileBox — new profile creation dialog (extends DialogBoxBase)
// Size: 0x24 bytes

#include "DialogBoxBase.h"

struct NewProfileBox : public DialogBoxBase {
    uint8_t field_0x10[0x14];  // 0x10
};
static_assert(sizeof(NewProfileBox) == 0x24, "NewProfileBox size mismatch");
