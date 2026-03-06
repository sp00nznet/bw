#pragma once
// PictureRoomBase — base picture/image room in temple (extends TempleRoom)
// Size: 0x160 bytes

#include "TempleRoom.h"

struct PictureRoomBase : public TempleRoom {
    uint8_t field_0xec[0x74];  // 0xEC
};
static_assert(sizeof(PictureRoomBase) == 0x160, "PictureRoomBase size mismatch");
