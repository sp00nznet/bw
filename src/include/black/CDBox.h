#pragma once
// CDBox — CD check dialog (extends DialogBoxBase)
// Size: 0x34 bytes

#include "DialogBoxBase.h"

struct CDBox : public DialogBoxBase {
    uint8_t field_0x10[0x24];  // 0x10
};
static_assert(sizeof(CDBox) == 0x34, "CDBox size mismatch");
