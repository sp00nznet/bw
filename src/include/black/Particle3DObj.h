#pragma once
// Particle3DObj — 3D object particle
// Struct layout from bw1-decomp (Particle3DObj.h)
//
// Size: 0x18 bytes (extends RenderParticle, no new fields)

#include "RenderParticle.h"

struct Particle3DObj : public RenderParticle {
    ~Particle3DObj() override;
    char* GetDebugText() override;
};
static_assert(sizeof(Particle3DObj) == 0x18, "Particle3DObj size mismatch");
