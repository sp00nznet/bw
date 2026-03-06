#pragma once
// MainMenu — main menu dialog (extends DialogBoxBase)
// Size: 0x38 bytes

#include "DialogBoxBase.h"

struct MainMenu : public DialogBoxBase {
    uint8_t field_0x10[0x28];  // 0x10
};
static_assert(sizeof(MainMenu) == 0x38, "MainMenu size mismatch");
