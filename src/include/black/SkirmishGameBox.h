#pragma once
// SkirmishGameBox — skirmish game setup dialog (extends DialogBoxBase)
// Size: 0x23C bytes

#include "DialogBoxBase.h"

struct SkirmishGameBox : public DialogBoxBase {
    uint8_t field_0x10[0x22C];  // 0x10
};
static_assert(sizeof(SkirmishGameBox) == 0x23C, "SkirmishGameBox size mismatch");
