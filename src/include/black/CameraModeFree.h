#pragma once
// CameraModeFree — free-roam camera mode
// Size: 0x18 bytes (inherits 0x8 from CameraMode)

#include "CameraMode.h"

struct CameraModeFree : public CameraMode {
    float    field_0x8;    // 0x08
    uint32_t field_0xc;    // 0x0C
    uint32_t field_0x10;   // 0x10
    uint32_t field_0x14;   // 0x14
};
static_assert(sizeof(CameraModeFree) == 0x18, "CameraModeFree size mismatch");
