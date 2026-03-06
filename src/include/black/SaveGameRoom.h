#pragma once
// SaveGameRoom — save/load room in temple (extends PictureRoomBase)
// Size: 0x160 bytes (same as PictureRoomBase)

#include "PictureRoom.h"

struct SaveGameRoom : public PictureRoomBase {
    // No new fields
};
static_assert(sizeof(SaveGameRoom) == 0x160, "SaveGameRoom size mismatch");
