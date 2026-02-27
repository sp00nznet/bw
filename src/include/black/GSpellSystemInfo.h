#pragma once
#include "GBaseInfo.h"
struct GSpellSystemInfo { GBaseInfo super; };
static_assert(sizeof(GSpellSystemInfo) == 0x10, "GSpellSystemInfo size mismatch");
