#pragma once
// CameraModeNew1 — new-style camera variant 1
// Size: 0x8 bytes (no added fields)
#include "CameraMode.h"

struct CameraModeNew1 : public CameraMode {};
static_assert(sizeof(CameraModeNew1) == 0x8, "CameraModeNew1 size mismatch");
