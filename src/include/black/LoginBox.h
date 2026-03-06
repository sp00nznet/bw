#pragma once
// LoginBox — online login dialog (extends DialogBoxBase)
// Size: 0x89C bytes

#include "DialogBoxBase.h"

struct LoginBox : public DialogBoxBase {
    uint8_t field_0x10[0x88C];  // 0x10
};
static_assert(sizeof(LoginBox) == 0x89C, "LoginBox size mismatch");
