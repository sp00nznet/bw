#pragma once
// PSysPCreator — specialized RenderParticle subtypes for particle creation
// Struct layout from bw1-decomp (PSysPCreator.h)
//
// 8 RenderParticle subclasses (all 0x18 bytes)

#include "RenderParticle.h"

struct RenderParticleCreatureRef : public RenderParticle {
    ~RenderParticleCreatureRef() override;
    char* GetDebugText() override;
};
static_assert(sizeof(RenderParticleCreatureRef) == 0x18, "RenderParticleCreatureRef size mismatch");

struct RenderParticleGJMesh : public RenderParticle {
    ~RenderParticleGJMesh() override;
};
static_assert(sizeof(RenderParticleGJMesh) == 0x18, "RenderParticleGJMesh size mismatch");

struct RenderParticleGJMeshRotatingUV : public RenderParticleGJMesh {
    ~RenderParticleGJMeshRotatingUV() override;
};
static_assert(sizeof(RenderParticleGJMeshRotatingUV) == 0x18, "RenderParticleGJMeshRotatingUV size mismatch");

struct RenderParticleGameObject : public RenderParticle {
    ~RenderParticleGameObject() override;
    char* GetDebugText() override;
};
static_assert(sizeof(RenderParticleGameObject) == 0x18, "RenderParticleGameObject size mismatch");

struct RenderParticleGameObjectRef : public RenderParticle {
    ~RenderParticleGameObjectRef() override;
    char* GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
};
static_assert(sizeof(RenderParticleGameObjectRef) == 0x18, "RenderParticleGameObjectRef size mismatch");

struct RenderParticleGoldenShower : public RenderParticleGameObjectRef {
    ~RenderParticleGoldenShower() override;
    char* GetDebugText() override;
};
static_assert(sizeof(RenderParticleGoldenShower) == 0x18, "RenderParticleGoldenShower size mismatch");

struct RenderParticleMist : public RenderParticle {
    ~RenderParticleMist() override;
    char* GetDebugText() override;
};
static_assert(sizeof(RenderParticleMist) == 0x18, "RenderParticleMist size mismatch");

struct RenderParticleVolBlendMesh : public RenderParticle {
    ~RenderParticleVolBlendMesh() override;
};
static_assert(sizeof(RenderParticleVolBlendMesh) == 0x18, "RenderParticleVolBlendMesh size mismatch");
