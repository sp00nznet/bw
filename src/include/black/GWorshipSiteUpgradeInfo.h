#pragma once
// GWorshipSiteUpgradeInfo — info for worship site upgrade objects
// Struct layout from bw1-decomp (WorshipSiteUpgradeInfo.h)
//
// Size: 0x120 bytes (extends GFeatureInfo)

#include "GFeatureInfo.h"

struct GWorshipSiteUpgradeInfo : public GFeatureInfo {
};
static_assert(sizeof(GWorshipSiteUpgradeInfo) == 0x120, "GWorshipSiteUpgradeInfo size mismatch");
