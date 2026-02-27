#pragma once
#include "Base.h"
struct GameArea : public Base {};
static_assert(sizeof(GameArea) == 0x8, "GameArea size mismatch");
