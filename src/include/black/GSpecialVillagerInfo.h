#pragma once
// GSpecialVillagerInfo — info for special villagers
// Struct layout from bw1-decomp (SpecialVillagerInfo.h)
//
// Size: 0x60 bytes (extends GBaseInfo)

#include "GBaseInfo.h"

struct GSpecialVillagerInfo {
    GBaseInfo super;       // 0x00
    char      name[0x30];  // 0x10
    uint32_t  field_0x40;  // 0x40
    uint32_t  field_0x44;  // 0x44
    uint32_t  field_0x48;  // 0x48
    uint32_t  field_0x4c;  // 0x4C
    uint32_t  field_0x50;  // 0x50
    int32_t   field_0x54;  // 0x54
    uint32_t  field_0x58;  // 0x58
    uint32_t  field_0x5c;  // 0x5C
};
static_assert(sizeof(GSpecialVillagerInfo) == 0x60, "GSpecialVillagerInfo size mismatch");
