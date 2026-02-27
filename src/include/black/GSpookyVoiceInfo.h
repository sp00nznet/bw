#pragma once
#include "GBaseInfo.h"
struct GSpookyVoiceInfo { GBaseInfo super; };
static_assert(sizeof(GSpookyVoiceInfo) == 0x10, "GSpookyVoiceInfo size mismatch");
