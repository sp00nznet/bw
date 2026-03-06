#pragma once
// MiniDialogBoxOptions — compact options dialog (extends DialogBoxBase)
// Size: 0x48 bytes

#include "DialogBoxBase.h"

struct MiniDialogBoxOptions : public DialogBoxBase {
    uint8_t field_0x10[0x38];  // 0x10 — widget pointers
};
static_assert(sizeof(MiniDialogBoxOptions) == 0x48, "MiniDialogBoxOptions size mismatch");
