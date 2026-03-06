#pragma once
// DialogBoxKeyBinding — key binding settings dialog (extends DialogBoxBase)
// Size: 0x1C bytes

#include "DialogBoxBase.h"

struct SetupList;

struct DialogBoxKeyBinding : public DialogBoxBase {
    uint8_t    field_0x10[0x8];  // 0x10
    SetupList* list;             // 0x18
};
static_assert(sizeof(DialogBoxKeyBinding) == 0x1C, "DialogBoxKeyBinding size mismatch");
