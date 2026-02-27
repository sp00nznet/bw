#pragma once
// GMagicResourceInfo — info for resource spell
// Struct layout from bw1-decomp (MagicResourceInfo.h)
//
// Size: 0x58 bytes (extends GMagicObjectInfo)

#include "GMagicObjectInfo.h"

struct GMagicResourceInfo : public GMagicObjectInfo {
};
static_assert(sizeof(GMagicResourceInfo) == 0x58, "GMagicResourceInfo size mismatch");
