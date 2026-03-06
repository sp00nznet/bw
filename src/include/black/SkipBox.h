#pragma once
// SkipBox — skip cutscene dialog (extends DialogBoxBase)
// Size: 0x24 bytes

#include "DialogBoxBase.h"

struct SkipBox : public DialogBoxBase {
    uint8_t field_0x10[0x14];  // 0x10
};
static_assert(sizeof(SkipBox) == 0x24, "SkipBox size mismatch");
