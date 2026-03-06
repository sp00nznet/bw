#pragma once
// GJPSysInterface — game particle system interface (extends PSysInterface)
// Struct layout from bw1-decomp
// Size: 0x18 bytes

#include "PSysInterface.h"

struct PSysManager;

struct GJPSysInterface : public PSysInterface {
    PSysManager* manager;  // 0x14
};
static_assert(sizeof(GJPSysInterface) == 0x18, "GJPSysInterface size mismatch");
