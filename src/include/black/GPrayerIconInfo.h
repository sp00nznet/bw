#pragma once
// GPrayerIconInfo — info for prayer icon objects
// Struct layout from bw1-decomp (PrayerIconInfo.h)
//
// Size: 0x108 bytes (extends GSingleMapFixedInfo)

#include "GSingleMapFixedInfo.h"

struct GPrayerIconInfo : public GSingleMapFixedInfo {
    uint32_t field_0x100;  // 0x100
    uint32_t field_0x104;  // 0x104
};
static_assert(sizeof(GPrayerIconInfo) == 0x108, "GPrayerIconInfo size mismatch");
