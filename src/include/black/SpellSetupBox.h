#pragma once
// SpellSetupBox — spell configuration dialog (extends DialogBoxBase)
// Size: 0x10 bytes

#include "DialogBoxBase.h"

struct SpellSetupBox : public DialogBoxBase {
    // No new fields
};
static_assert(sizeof(SpellSetupBox) == 0x10, "SpellSetupBox size mismatch");
