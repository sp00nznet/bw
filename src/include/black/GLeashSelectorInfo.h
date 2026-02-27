#pragma once
// GLeashSelectorInfo — info for leash selector objects
// Struct layout from bw1-decomp (LeashSelectorInfo.h)
//
// Size: 0x100 bytes (extends GObjectInfo)

#include "GObjectInfo.h"

struct GLeashSelectorInfo : public GObjectInfo {
};
static_assert(sizeof(GLeashSelectorInfo) == 0x100, "GLeashSelectorInfo size mismatch");
