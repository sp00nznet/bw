#pragma once
// EditingDebugBox — debug editing dialog (extends DialogBoxBase)
// Size: 0x10 bytes

#include "DialogBoxBase.h"

struct EditingDebugBox : public DialogBoxBase {
    // No new fields
};
static_assert(sizeof(EditingDebugBox) == 0x10, "EditingDebugBox size mismatch");
