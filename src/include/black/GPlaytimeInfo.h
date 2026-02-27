#pragma once
#include "GBaseInfo.h"
struct GPlaytimeInfo { GBaseInfo super; };
static_assert(sizeof(GPlaytimeInfo) == 0x10, "GPlaytimeInfo size mismatch");
