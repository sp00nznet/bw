#pragma once
#include "GLivingInfo.h"
struct GAnimalInfo : public GLivingInfo {};
static_assert(sizeof(GAnimalInfo) == 0x1F4, "GAnimalInfo size mismatch");
