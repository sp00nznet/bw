#pragma once
#include "Base.h"

struct Rank : public Base {};
static_assert(sizeof(Rank) == 0x8, "Rank size mismatch");
