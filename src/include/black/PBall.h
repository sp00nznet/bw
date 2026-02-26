#pragma once
// PBall — physics ball object (thrown projectile)
// Struct layout from bw1-decomp
//
// Size: 0x68 bytes (same as MobileObject — no new fields)

#include "MobileObject.h"

struct PBall : public MobileObject {
    // === Overrides of Object virtuals ===
    uint32_t Process() override;
    void Draw() override;
};
static_assert(sizeof(PBall) == 0x68, "PBall size mismatch");
