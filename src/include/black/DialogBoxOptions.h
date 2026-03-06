#pragma once
// DialogBoxOptions — game options dialog (extends DialogBoxBase)
// Size: 0x68 bytes

#include "DialogBoxBase.h"

struct DialogBoxOptions : public DialogBoxBase {
    uint8_t field_0x10[0x58];  // 0x10 — various UI widget pointers
};
static_assert(sizeof(DialogBoxOptions) == 0x68, "DialogBoxOptions size mismatch");
