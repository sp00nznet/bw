#pragma once
// SetupEdit — text input field (extends SetupControl)
// Size: 0x468 bytes

#include "SetupControl.h"

struct SetupList;

struct SetupEdit : public SetupControl {
    SetupList* field_0x23c;      // 0x23C
    int        field_0x240;      // 0x240
    int        field_0x244;      // 0x244
    int        field_0x248;      // 0x248
    int        cursor_position;  // 0x24C
    int        select_start;     // 0x250
    int        select_end;       // 0x254
    int        field_0x258;      // 0x258
    uint32_t   editable;         // 0x25C
    bool       masked_text;      // 0x260
    char16_t   text[0x100];      // 0x262  (note: bool is 1 byte, so text starts at 0x261 after packing; but vendor says 0x260+bool at 0x260, text array follows)
    uint32_t   field_0x464;      // 0x464
};
static_assert(sizeof(SetupEdit) == 0x468, "SetupEdit size mismatch");
