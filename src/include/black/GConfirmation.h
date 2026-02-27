#pragma once
#include "Base.h"
struct GConfirmation : public Base {};
static_assert(sizeof(GConfirmation) == 0x8, "GConfirmation size mismatch");
