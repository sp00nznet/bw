#pragma once
// CameraModeCtrInteract — creature interaction camera mode
// Size: 0x8 bytes (no added fields)
#include "CameraMode.h"

struct CameraModeCtrInteract : public CameraMode {};
static_assert(sizeof(CameraModeCtrInteract) == 0x8, "CameraModeCtrInteract size mismatch");
