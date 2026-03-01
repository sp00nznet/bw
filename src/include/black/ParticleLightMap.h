#pragma once
// ParticleLightMap — light map particle
// Struct layout from bw1-decomp (ParticleLightMap.h)
//
// Size: 0x18 bytes (extends RenderParticle, no new fields)

#include "RenderParticle.h"

struct ParticleLightMap : public RenderParticle {
    ~ParticleLightMap() override;
    char* GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
};
static_assert(sizeof(ParticleLightMap) == 0x18, "ParticleLightMap size mismatch");
