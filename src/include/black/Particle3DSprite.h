#pragma once
// Particle3DSprite — sprite particle
// Struct layout from bw1-decomp (Particle3DSprite.h)
//
// Size: 0x18 bytes (extends RenderParticle, no new fields)

#include "RenderParticle.h"

struct Particle3DSprite : public RenderParticle {
    ~Particle3DSprite() override;
    char* GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
};
static_assert(sizeof(Particle3DSprite) == 0x18, "Particle3DSprite size mismatch");
