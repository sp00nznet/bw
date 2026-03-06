#pragma once
// RegisterBox — user registration dialog (extends DialogBoxBase)
// Size: 0x28 bytes

#include "DialogBoxBase.h"

struct RegisterBox : public DialogBoxBase {
    uint8_t field_0x10[0x18];  // 0x10
};
static_assert(sizeof(RegisterBox) == 0x28, "RegisterBox size mismatch");
