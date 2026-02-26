#pragma once
// CameraModeCitadel — citadel interior camera mode
// Size: 0x8 bytes (no added fields)
#include "CameraMode.h"

struct CameraModeCitadel : public CameraMode {};
static_assert(sizeof(CameraModeCitadel) == 0x8, "CameraModeCitadel size mismatch");
