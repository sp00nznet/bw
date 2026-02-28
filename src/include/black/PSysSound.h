#pragma once
// PSysSound — particle system with 3D sound
// Struct layout from bw1-decomp (PSysSound.h)
//
// Size: 0x14 bytes (inherits PSysBase, no new fields)

#include "PSysBase.h"

struct PSysSound : public PSysBase {
    ~PSysSound() override;

    // === Overrides of Base virtuals ===
    int Get3DSoundPos(LHPoint* pos) override;

    // === Overrides of GameThing virtuals ===
    char* GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;
};
static_assert(sizeof(PSysSound) == 0x14, "PSysSound size mismatch");
