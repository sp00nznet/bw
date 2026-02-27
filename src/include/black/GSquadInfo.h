#pragma once
#include "GBaseInfo.h"
struct GSquadInfo { GBaseInfo super; };
static_assert(sizeof(GSquadInfo) == 0x10, "GSquadInfo size mismatch");
