#pragma once
// HistoryBox — game history viewer (extends DialogBoxBase)
// Size: 0x1C bytes

#include "DialogBoxBase.h"

struct HistoryBox : public DialogBoxBase {
    uint8_t field_0x10[0xC];  // 0x10
};
static_assert(sizeof(HistoryBox) == 0x1C, "HistoryBox size mismatch");
