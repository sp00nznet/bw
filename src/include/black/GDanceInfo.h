#pragma once
#include "GBaseInfo.h"

struct GDanceInfo {
    GBaseInfo super;          // 0x00
    uint8_t   field_0x10[0xA0]; // 0x10
};
static_assert(sizeof(GDanceInfo) == 0xB0, "GDanceInfo size mismatch");
