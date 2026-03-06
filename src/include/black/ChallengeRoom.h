#pragma once
// ChallengeRoom — challenge room in temple (extends PictureRoomBase)
// Also contains TempleChallenge (0xD8) data struct
// Size: 0x160 bytes

#include "PictureRoom.h"

struct TempleChallenge {
    uint8_t field_0x0[0xD8];
};
static_assert(sizeof(TempleChallenge) == 0xD8, "TempleChallenge size mismatch");

struct ChallengeRoom : public PictureRoomBase {
    // No new fields
};
static_assert(sizeof(ChallengeRoom) == 0x160, "ChallengeRoom size mismatch");
