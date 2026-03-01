#pragma once
// ParticleBaseMeshCreator — mesh-based particle creation
// Struct layout from bw1-decomp (ParticleBaseMeshCreator.h)
//
// Size: 0x4 bytes (extends ParticleCreator)

#include "ParticleCreator.h"

struct ParticleBaseMeshCreator : public ParticleCreator {
    ~ParticleBaseMeshCreator() override;
    void DefineProperties(void* list) override;
};
static_assert(sizeof(ParticleBaseMeshCreator) == 0x4, "ParticleBaseMeshCreator size mismatch");
