#pragma once
// Arrow — projectile entity
// Struct layout from bw1-decomp
//
// Size: 0x68 bytes (same as MobileObject — no new fields)
// Vtable: uses MobileObject's vtable layout

#include "MobileObject.h"

struct Arrow : public MobileObject {
    // === Overrides of GameThing virtuals ===
    GPlayer* GetPlayer() override;
};
static_assert(sizeof(Arrow) == 0x68, "Arrow size mismatch");
