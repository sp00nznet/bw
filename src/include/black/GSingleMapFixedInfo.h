#pragma once
// GSingleMapFixedInfo — info for single-map-fixed objects
// Struct layout from bw1-decomp
//
// Size: 0x100 bytes (same size as GObjectInfo, different vtable)

#include "ObjectInfo.h"

struct GSingleMapFixedInfo : public GObjectInfo {
    // No additional fields — same size as parent
    // Uses GSingleMapFixedInfoVftable (no extra virtuals beyond GObjectInfo)
};
static_assert(sizeof(GSingleMapFixedInfo) == 0x100, "GSingleMapFixedInfo size mismatch");
