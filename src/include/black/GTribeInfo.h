#pragma once
// GTribeInfo — info for tribes/civilizations
// Struct layout from bw1-decomp
//
// Size: 0x1C bytes (extends GBaseInfo at 0x10)
// Referenced by Abode, Citadel, CitadelHeart for tribe association.

#include "GBaseInfo.h"

// Forward-declare enum
enum TRIBE_TYPE : uint32_t;

struct GTribeInfo : public GBaseInfo {
    TRIBE_TYPE type;         // 0x10
    uint32_t   field_0x14;  // 0x14
    uint32_t   field_0x18;  // 0x18
};
static_assert(sizeof(GTribeInfo) == 0x1C, "GTribeInfo size mismatch");
