#pragma once
// CameraModeDance — dance sequence camera mode
// Size: 0x8 bytes (no added fields)
#include "CameraMode.h"

struct CameraModeDance : public CameraMode {};
static_assert(sizeof(CameraModeDance) == 0x8, "CameraModeDance size mismatch");
