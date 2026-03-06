#pragma once
// IPSpecialDialog — IP address input dialog (extends DialogBoxBase)
// Size: 0x10 bytes

#include "DialogBoxBase.h"

struct IPSpecialDialog : public DialogBoxBase {
    // No new fields
};
static_assert(sizeof(IPSpecialDialog) == 0x10, "IPSpecialDialog size mismatch");
