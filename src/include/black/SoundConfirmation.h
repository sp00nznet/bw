#pragma once
// GConfirmation — sound confirmation system
// Struct layout from bw1-decomp
// Size: 0x8 bytes (just Base)

#include "Base.h"

struct GConfirmation : public Base {
    // No new fields
};
static_assert(sizeof(GConfirmation) == 0x8, "GConfirmation size mismatch");
