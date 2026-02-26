#pragma once
// CameraModeNew2 — new-style camera variant 2
// Size: 0x8 bytes (no added fields)
#include "CameraMode.h"

struct CameraModeNew2 : public CameraMode {};
static_assert(sizeof(CameraModeNew2) == 0x8, "CameraModeNew2 size mismatch");
