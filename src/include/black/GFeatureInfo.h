#pragma once
#include "GMultiMapFixedInfo.h"

struct GFeatureInfo : public GMultiMapFixedInfo {
};
static_assert(sizeof(GFeatureInfo) == 0x120, "GFeatureInfo size mismatch");
