#pragma once
// GMagicLivingInfo — info for living magic entities
// Struct layout from bw1-decomp (MagicLivingInfo.h)
//
// Size: 0x1F4 bytes (extends GLivingInfo)

#include "GLivingInfo.h"

struct GMagicLivingInfo : public GLivingInfo {
};
static_assert(sizeof(GMagicLivingInfo) == 0x1F4, "GMagicLivingInfo size mismatch");
