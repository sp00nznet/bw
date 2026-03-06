#pragma once
// StartGameBox — start game dialog (extends DialogBoxBase)
// Size: 0x20 bytes

#include "DialogBoxBase.h"

struct SetupStaticText;
struct SetupList;
struct SetupButton;
struct SetupBigButton;

struct StartGameBox : public DialogBoxBase {
    SetupStaticText* text;        // 0x10
    SetupList*       list;        // 0x14
    SetupButton*     button;      // 0x18
    SetupBigButton*  big_button;  // 0x1C
};
static_assert(sizeof(StartGameBox) == 0x20, "StartGameBox size mismatch");
