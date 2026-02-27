#pragma once
#include "GBaseInfo.h"
struct GInfluenceInfo { GBaseInfo super; };
static_assert(sizeof(GInfluenceInfo) == 0x10, "GInfluenceInfo size mismatch");
