#pragma once
// CreatureLearningContext — learning context state
// Struct layout from bw1-decomp (CreatureLearning.h)
//
// Size: 0x8 bytes (Base only)

#include "Base.h"

struct CreatureLearningContext : public Base {
};
static_assert(sizeof(CreatureLearningContext) == 0x8, "CreatureLearningContext size mismatch");
