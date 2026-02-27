#pragma once
// CreatureObjectsInspected — objects the creature has inspected
// Struct layout from bw1-decomp (CreatureObjectsInspected.h)
//
// Size: 0x68 bytes (inherits 0x8 from Base)
// Tracks up to 24 inspected game objects.

#include "Base.h"

struct CreatureObjectsInspected : public Base {
    uint32_t field_0x8[0x18];  // 0x08 — 24 entries
};
static_assert(sizeof(CreatureObjectsInspected) == 0x68, "CreatureObjectsInspected size mismatch");
