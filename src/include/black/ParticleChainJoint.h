#pragma once
// ParticleChainJoint — chain joint particle for linked particle effects
// Struct layout from bw1-decomp (ParticleChainJoint.h)
//
// Size: 0x18 bytes (extends RenderParticle, no new fields)

#include "RenderParticle.h"

struct ParticleChainJoint : public RenderParticle {
    ~ParticleChainJoint() override;
    char* GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;
};
static_assert(sizeof(ParticleChainJoint) == 0x18, "ParticleChainJoint size mismatch");
