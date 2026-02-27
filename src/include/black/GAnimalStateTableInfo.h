#pragma once
#include "GBaseInfo.h"
struct GAnimalStateTableInfo { GBaseInfo super; };
static_assert(sizeof(GAnimalStateTableInfo) == 0x10, "GAnimalStateTableInfo size mismatch");
