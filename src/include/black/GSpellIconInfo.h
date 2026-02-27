#pragma once
#include "GMultiMapFixedInfo.h"

struct GSpellIconInfo {
    GMultiMapFixedInfo super;   // 0x000
    uint32_t field_0x120;       // 0x120
    uint32_t field_0x124;       // 0x124
    uint32_t field_0x128;       // 0x128
};
static_assert(sizeof(GSpellIconInfo) == 0x12C, "GSpellIconInfo size mismatch");
