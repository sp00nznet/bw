#pragma once
// GSpellSeedInfo — info for spell seed objects
// Struct layout from bw1-decomp
//
// Size: 0x190 bytes (extends GObjectInfo at 0x100)
// Contains magic type arrays and spell seed configuration.

#include "ObjectInfo.h"

// Forward-declare enum
enum MAGIC_TYPE : uint32_t;

struct GSpellSeedInfo : public GObjectInfo {
    uint8_t     field_0x100[0x24];       // 0x100
    MAGIC_TYPE  magic_types[4];          // 0x124
    uint8_t     field_0x134[0x5C];       // 0x134
};
static_assert(sizeof(GSpellSeedInfo) == 0x190, "GSpellSeedInfo size mismatch");
