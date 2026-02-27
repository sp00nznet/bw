#pragma once
#include "GBaseInfo.h"
struct HelpSystemInfo { GBaseInfo super; };
static_assert(sizeof(HelpSystemInfo) == 0x10, "HelpSystemInfo size mismatch");
