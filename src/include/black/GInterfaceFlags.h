#pragma once
#include "Base.h"

struct GInterfaceFlags : public Base {
    int      field_0x8;   // 0x08
    uint32_t field_0xc;   // 0x0C
    uint32_t field_0x10;  // 0x10
};
static_assert(sizeof(GInterfaceFlags) == 0x14, "GInterfaceFlags size mismatch");
