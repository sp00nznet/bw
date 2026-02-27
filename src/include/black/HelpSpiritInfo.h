#pragma once
// HelpSpiritInfo — info for help spirit (Conscience)
// Struct layout from bw1-decomp (HelpSpiritInfo.h)
//
// Size: 0x1F4 bytes (extends GLivingInfo)

#include "GLivingInfo.h"

struct HelpSpiritInfo : public GLivingInfo {
};
static_assert(sizeof(HelpSpiritInfo) == 0x1F4, "HelpSpiritInfo size mismatch");
