#pragma once
#include "Base.h"

struct GInterfaceMessageBuffer : public Base {
    uint8_t field_0x8[0xC];  // 0x08
};
static_assert(sizeof(GInterfaceMessageBuffer) == 0x14, "GInterfaceMessageBuffer size mismatch");
