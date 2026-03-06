#pragma once
// SetupOnlineLandscapes — online landscape browser dialog (extends DialogBoxBase)
// Size: 0x10 bytes

#include "DialogBoxBase.h"

struct SetupOnlineLandscapes : public DialogBoxBase {
    // No new fields
};
static_assert(sizeof(SetupOnlineLandscapes) == 0x10, "SetupOnlineLandscapes size mismatch");
