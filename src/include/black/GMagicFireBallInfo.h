#pragma once
// GMagicFireBallInfo — info for magic fireball
// Struct layout from bw1-decomp (MagicFireBallInfo.h)
//
// Size: 0x100 bytes (extends GObjectInfo)

#include "GObjectInfo.h"

struct GMagicFireBallInfo : public GObjectInfo {
};
static_assert(sizeof(GMagicFireBallInfo) == 0x100, "GMagicFireBallInfo size mismatch");
