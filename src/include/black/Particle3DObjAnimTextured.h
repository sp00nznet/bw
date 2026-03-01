#pragma once
// Particle3DObjAnimTextured — textured animated 3D object particle
// Struct layout from bw1-decomp (Particle3DObjAnimTextured.h)
//
// Size: 0x18 bytes (extends Particle3DObj, no new fields)

#include "Particle3DObj.h"

struct Particle3DObjAnimTextured : public Particle3DObj {
    ~Particle3DObjAnimTextured() override;
};
static_assert(sizeof(Particle3DObjAnimTextured) == 0x18, "Particle3DObjAnimTextured size mismatch");
