#pragma once
// CameraModeTwoObjects — two-object tracking camera mode
// Size: 0x8 bytes (no added fields)
#include "CameraMode.h"

struct CameraModeTwoObjects : public CameraMode {};
static_assert(sizeof(CameraModeTwoObjects) == 0x8, "CameraModeTwoObjects size mismatch");
