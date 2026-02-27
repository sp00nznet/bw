#pragma once
#include "DrawingObject.h"

struct PowerSpin : public DrawingObject {};
static_assert(sizeof(PowerSpin) == 0x4, "PowerSpin size mismatch");

struct PowerSpinRunner : public PowerSpin {};
static_assert(sizeof(PowerSpinRunner) == 0x4, "PowerSpinRunner size mismatch");
