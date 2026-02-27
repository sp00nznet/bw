#pragma once
#include "Base.h"

struct GLanguage : public Base {
    uint32_t field_0x8;  // 0x08
};
static_assert(sizeof(GLanguage) == 0xC, "GLanguage size mismatch");
