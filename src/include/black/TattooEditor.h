#pragma once
// TattooEditor — creature tattoo editor dialog (extends DialogBoxBase)
// Size: 0x3228 bytes

#include "DialogBoxBase.h"

struct TattooEditor : public DialogBoxBase {
    uint8_t field_0x10[0x3218];  // 0x10
};
static_assert(sizeof(TattooEditor) == 0x3228, "TattooEditor size mismatch");
