#pragma once
#include "GBaseInfo.h"
struct GSoundInfo { GBaseInfo super; };
static_assert(sizeof(GSoundInfo) == 0x10, "GSoundInfo size mismatch");
