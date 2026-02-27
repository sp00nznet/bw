#pragma once
#include "GBaseInfo.h"
struct GVortexInfo { GBaseInfo super; };
static_assert(sizeof(GVortexInfo) == 0x10, "GVortexInfo size mismatch");
