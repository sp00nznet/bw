#pragma once
// GPotInfo — info for pot (resource container) objects
// Struct layout from bw1-decomp
//
// Size: 0x114 bytes (same as GMobileObjectInfo, no added fields)

#include "GMobileObjectInfo.h"

struct GPotInfo : public GMobileObjectInfo {
    // No additional fields
};
static_assert(sizeof(GPotInfo) == 0x114, "GPotInfo size mismatch");
