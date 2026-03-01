#pragma once
// Particle3DAnimWithCamera — animated 3D particle with camera awareness
// Struct layout from bw1-decomp (Particle3DAnimWithCamera.h)
//
// Size: 0x18 bytes (extends Particle3DAnim, no new fields)

#include "Particle3DAnim.h"

struct Particle3DAnimWithCamera : public Particle3DAnim {
    ~Particle3DAnimWithCamera() override;
};
static_assert(sizeof(Particle3DAnimWithCamera) == 0x18, "Particle3DAnimWithCamera size mismatch");
