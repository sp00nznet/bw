#pragma once
// ParticleCreator — particle creation base (Persistent-derived)
// Struct layout from bw1-decomp (ParticleCreator.h)
//
// Size: 0x4 bytes (extends Persistent)

#include "Persistent.h"

struct PropertyList;

struct ParticleCreator : public Persistent {
    ~ParticleCreator() override;
    void DefineProperties(void* list) override;
};
static_assert(sizeof(ParticleCreator) == 0x4, "ParticleCreator size mismatch");
