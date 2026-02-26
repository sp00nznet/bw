#pragma once
// GTreeInfo — info for tree objects
// Struct layout from bw1-decomp
//
// Size: 0x140 bytes (extends GSingleMapFixedInfo at 0x100)

#include "GSingleMapFixedInfo.h"

struct GTreeInfo : public GSingleMapFixedInfo {
    uint8_t field_0x100[0x40];  // 0x100
};
static_assert(sizeof(GTreeInfo) == 0x140, "GTreeInfo size mismatch");
