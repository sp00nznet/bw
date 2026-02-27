#pragma once
#include "GBaseInfo.h"
struct GJobInfo { GBaseInfo super; };
static_assert(sizeof(GJobInfo) == 0x10, "GJobInfo size mismatch");
