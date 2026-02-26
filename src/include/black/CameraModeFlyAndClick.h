#pragma once
// CameraModeFlyAndClick — fly-and-click camera mode
// Size: 0x8 bytes (no added fields)
#include "CameraMode.h"

struct CameraModeFlyAndClick : public CameraMode {};
static_assert(sizeof(CameraModeFlyAndClick) == 0x8, "CameraModeFlyAndClick size mismatch");
