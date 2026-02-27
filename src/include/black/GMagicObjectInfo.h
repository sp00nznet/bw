#pragma once
// GMagicObjectInfo — info for magic objects
// Struct layout from bw1-decomp (MagicObjectInfo.h)
//
// Size: 0x58 bytes (extends GMagicInfo)

#include "GMagicInfo.h"

struct GMagicObjectInfo : public GMagicInfo {
};
static_assert(sizeof(GMagicObjectInfo) == 0x58, "GMagicObjectInfo size mismatch");
