#pragma once
// CameraModeFollow — follow-target camera mode
// Size: 0x48 bytes (inherits 0x8 from CameraMode)

#include "CameraMode.h"

struct GameThingWithPos;

struct CameraModeFollow : public CameraMode {
    GameThingWithPos* target;          // 0x08
    float             pitch;           // 0x0C
    float             yaw;             // 0x10
    float             viewing_distance; // 0x14
    float             field_0x18;      // 0x18
    int32_t           field_0x1c;      // 0x1C
    int32_t           field_0x20;      // 0x20
    uint8_t           field_0x24[0x18]; // 0x24
    int32_t           field_0x3c;      // 0x3C
    int32_t           field_0x40;      // 0x40
    int32_t           field_0x44;      // 0x44

    // Non-virtual method
    void Set(GameThingWithPos* target);  // 0x0044ba00
};
static_assert(sizeof(CameraModeFollow) == 0x48, "CameraModeFollow size mismatch");
