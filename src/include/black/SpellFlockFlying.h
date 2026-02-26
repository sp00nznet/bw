#pragma once
// SpellFlockFlying — flying flock spell (e.g. doves)
// Struct layout from bw1-decomp
//
// Size: 0xF4 bytes (inherits 0xF4 from SpellFlock, no added fields)

#include "SpellFlock.h"

struct SpellFlockFlying : public SpellFlock {
    // === Overrides of GameThing virtuals ===
    char* GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;

    // === Overrides of Spell virtuals ===
    void GetParticleType() override;
    void Draw() override;
    uint32_t Process() override;
};
static_assert(sizeof(SpellFlockFlying) == 0xF4, "SpellFlockFlying size mismatch");
