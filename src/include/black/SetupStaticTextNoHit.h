#pragma once
// SetupStaticTextNoHit — text label that ignores mouse input
// Size: 0x244 bytes (same as SetupStaticText)

#include "SetupStaticText.h"

struct SetupStaticTextNoHit : public SetupStaticText {
    // No new fields
};
static_assert(sizeof(SetupStaticTextNoHit) == 0x244, "SetupStaticTextNoHit size mismatch");
