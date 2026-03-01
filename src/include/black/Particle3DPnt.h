#pragma once
// Particle3DPnt — point particle
// Struct layout from bw1-decomp (Particle3DPnt.h)
//
// Size: 0x18 bytes (extends RenderParticle, no new fields)

#include "RenderParticle.h"

struct Particle3DPnt : public RenderParticle {
    ~Particle3DPnt() override;
    char* GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;
};
static_assert(sizeof(Particle3DPnt) == 0x18, "Particle3DPnt size mismatch");
