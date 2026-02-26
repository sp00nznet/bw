#pragma once
// CameraModeFollowHeading — follow-heading camera mode
// Size: 0x8 bytes (no added fields)
#include "CameraMode.h"

struct CameraModeFollowHeading : public CameraMode {};
static_assert(sizeof(CameraModeFollowHeading) == 0x8, "CameraModeFollowHeading size mismatch");
