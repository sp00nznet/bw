#pragma once
// DialogBoxImmersion — immersion settings dialog (extends DialogBoxBase)
// Size: 0x30 bytes

#include "DialogBoxBase.h"

struct SetupStaticText;
struct SetupBigButton;
struct SetupButton;

struct DialogBoxImmersion : public DialogBoxBase {
    SetupStaticText* field_0x10;  // 0x10
    SetupStaticText* field_0x14;  // 0x14
    SetupBigButton*  field_0x18;  // 0x18
    SetupBigButton*  field_0x1c;  // 0x1C
    SetupButton*     field_0x20;  // 0x20
    SetupBigButton*  field_0x24;  // 0x24
    uint32_t         field_0x28;  // 0x28
    uint32_t         field_0x2c;  // 0x2C
};
static_assert(sizeof(DialogBoxImmersion) == 0x30, "DialogBoxImmersion size mismatch");
