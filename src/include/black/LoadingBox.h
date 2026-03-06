#pragma once
// LoadingBox — loading screen dialog (extends DialogBoxBase)
// Size: 0x10 bytes

#include "DialogBoxBase.h"

struct LoadingBox : public DialogBoxBase {
    // No new fields
};
static_assert(sizeof(LoadingBox) == 0x10, "LoadingBox size mismatch");
