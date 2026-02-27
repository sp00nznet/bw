#pragma once
// CreatureActionsKnownAbout — creature's known action repertoire
// Struct layout from bw1-decomp (CreatureActionsKnownAbout.h)
//
// Size: 0x18 bytes (inherits 0x8 from Base)

#include "Base.h"

struct CreatureActionsKnownAbout : public Base {
    uint32_t field_0x8[2][2];  // 0x08 — 2x2 matrix
};
static_assert(sizeof(CreatureActionsKnownAbout) == 0x18, "CreatureActionsKnownAbout size mismatch");
