#pragma once
// DialogBoxSaveMessage — save game message dialog (extends DialogBoxBase)
// Size: 0x24 bytes

#include "DialogBoxBase.h"

struct DialogBoxSaveMessage : public DialogBoxBase {
    uint32_t field_0x10;  // 0x10
    uint32_t field_0x14;  // 0x14
    uint32_t field_0x18;  // 0x18
    uint32_t field_0x1c;  // 0x1C
    uint32_t field_0x20;  // 0x20
};
static_assert(sizeof(DialogBoxSaveMessage) == 0x24, "DialogBoxSaveMessage size mismatch");
