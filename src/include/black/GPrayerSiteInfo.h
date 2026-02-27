#pragma once
// GPrayerSiteInfo — info for prayer site objects
// Struct layout from bw1-decomp (PrayerSiteInfo.h)
//
// Size: 0x120 bytes (extends GMultiMapFixedInfo)

#include "GMultiMapFixedInfo.h"

struct GPrayerSiteInfo : public GMultiMapFixedInfo {
};
static_assert(sizeof(GPrayerSiteInfo) == 0x120, "GPrayerSiteInfo size mismatch");
