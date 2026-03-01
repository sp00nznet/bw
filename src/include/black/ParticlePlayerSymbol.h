#pragma once
// ParticlePlayerSymbol — player symbol particle
// Struct layout from bw1-decomp (ParticlePlayerSymbol.h)
//
// Size: 0x18 bytes (extends RenderParticle, no new fields)

#include "RenderParticle.h"

struct ParticlePlayerSymbol : public RenderParticle {
    ~ParticlePlayerSymbol() override;
};
static_assert(sizeof(ParticlePlayerSymbol) == 0x18, "ParticlePlayerSymbol size mismatch");
