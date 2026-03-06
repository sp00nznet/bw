#pragma once
// StatsBox — statistics display dialog (extends DialogBoxBase)
// Size: 0x74 bytes

#include "DialogBoxBase.h"

struct StatsBox : public DialogBoxBase {
    uint8_t field_0x10[0x64];  // 0x10
};
static_assert(sizeof(StatsBox) == 0x74, "StatsBox size mismatch");
