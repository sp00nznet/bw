#pragma once
// CameraModePath — path-following camera mode
// Size: 0x8 bytes (no added fields)
#include "CameraMode.h"

struct CameraModePath : public CameraMode {};
static_assert(sizeof(CameraModePath) == 0x8, "CameraModePath size mismatch");
