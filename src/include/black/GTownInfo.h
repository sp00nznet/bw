#pragma once
// GTownInfo — info for town containers
// Struct layout from bw1-decomp
//
// Size: 0x18C bytes (extends GContainerInfo at 0x148)
// Mostly float configuration fields for town behavior.

#include "GContainerInfo.h"

struct GTownInfo : public GContainerInfo {
    float    field_0x148;   // 0x148
    float    field_0x14c;   // 0x14C
    uint32_t field_0x150;   // 0x150
    float    field_0x154;   // 0x154
    float    field_0x158;   // 0x158
    float    field_0x15c;   // 0x15C
    uint32_t field_0x160;   // 0x160
    float    field_0x164;   // 0x164
    uint32_t field_0x168;   // 0x168
    float    field_0x16c;   // 0x16C
    float    field_0x170;   // 0x170
    float    field_0x174;   // 0x174
    float    field_0x178;   // 0x178
    float    field_0x17c;   // 0x17C
    float    field_0x180;   // 0x180
    float    field_0x184;   // 0x184
    float    field_0x188;   // 0x188
};
static_assert(sizeof(GTownInfo) == 0x18C, "GTownInfo size mismatch");
