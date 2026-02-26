#pragma once
// CameraModeNew — new-style camera base mode
// Size: 0x8 bytes (no added fields)
#include "CameraMode.h"

struct CameraModeNew : public CameraMode {};
static_assert(sizeof(CameraModeNew) == 0x8, "CameraModeNew size mismatch");
