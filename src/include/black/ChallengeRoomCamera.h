#pragma once
// ChallengeRoomCamera — camera for challenge room (extends InnerCamera)
// Size: 0x46C bytes

#include "InnerCamera.h"

struct ChallengeRoomCamera : public InnerCamera {
    // No new fields
};
static_assert(sizeof(ChallengeRoomCamera) == 0x46C, "ChallengeRoomCamera size mismatch");
