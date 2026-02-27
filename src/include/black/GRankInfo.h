#pragma once
#include "GBaseInfo.h"
struct GRankInfo { GBaseInfo super; };
static_assert(sizeof(GRankInfo) == 0x10, "GRankInfo size mismatch");
