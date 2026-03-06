#pragma once
// GameOptionsRoom — game options room in temple (extends PictureRoomBase)
// Size: 0x160 bytes (same as PictureRoomBase)

#include "PictureRoom.h"

struct GameOptionsRoom : public PictureRoomBase {
    // No new fields
};
static_assert(sizeof(GameOptionsRoom) == 0x160, "GameOptionsRoom size mismatch");
