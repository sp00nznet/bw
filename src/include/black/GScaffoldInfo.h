#pragma once
// GScaffoldInfo — info for scaffold objects
// Struct layout from bw1-decomp (ScaffoldInfo.h)
//
// Size: 0x114 bytes (extends GMobileObjectInfo)

#include "GMobileObjectInfo.h"

struct GScaffoldInfo : public GMobileObjectInfo {
};
static_assert(sizeof(GScaffoldInfo) == 0x114, "GScaffoldInfo size mismatch");
