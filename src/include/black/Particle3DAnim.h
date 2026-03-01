#pragma once
// Particle3DAnim — animated 3D particle
// Struct layout from bw1-decomp (Particle3DAnim.h)
//
// Size: 0x18 bytes (extends RenderParticle, no new fields)

#include "RenderParticle.h"

struct Particle3DAnim : public RenderParticle {
    ~Particle3DAnim() override;
    char* GetDebugText() override;
};
static_assert(sizeof(Particle3DAnim) == 0x18, "Particle3DAnim size mismatch");
