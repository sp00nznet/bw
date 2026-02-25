#pragma once
// Mobile — moveable Object (adds minimal state to Object)
// Struct layout from bw1-decomp
//
// Size: 0x58 bytes (inherits 0x54 from Object)
// Vtable: 0x85C bytes (same size as Object — no new virtuals)

#include "Object.h"

struct Mobile : public Object {
    // No new virtual methods — vtable same as Object (0x85C bytes)

    // === Fields ===
    uint16_t field_0x54;   // 0x54 — saved/loaded in Mobile::Save/Load
    uint16_t pad_0x56;     // 0x56 — padding to 0x58
};
static_assert(sizeof(Mobile) == 0x58, "Mobile size mismatch");
