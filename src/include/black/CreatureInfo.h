#pragma once
// CreatureInfo — metadata/configuration for a creature type
// Struct layout from bw1-decomp (CreatureInfo.h)
//
// Size: 0x394 bytes (extends GLivingInfo at 0x1F4)
// Contains creature-specific stats, abilities, and configuration data.

#include "GLivingInfo.h"

struct CreatureInfo : public GLivingInfo {
    uint32_t creature_type;     // 0x1F4
    float    field_0x1f8[4];    // 0x1F8-0x207
    uint32_t field_0x208;       // 0x208
    float    field_0x20c;       // 0x20C
    uint32_t field_0x210;       // 0x210
    float    field_0x214[0x15]; // 0x214-0x267
    uint32_t field_0x268;       // 0x268
    uint32_t field_0x26c;       // 0x26C
    uint32_t field_0x270;       // 0x270
    uint32_t field_0x274;       // 0x274
    float    field_0x278[3];    // 0x278-0x283
    uint32_t field_0x284;       // 0x284
    float    field_0x288[8];    // 0x288-0x2A7
    uint32_t field_0x2a8;       // 0x2A8
    float    field_0x2ac[0x26]; // 0x2AC-0x343
    uint32_t field_0x344;       // 0x344
    float    field_0x348[0x13]; // 0x348-0x393
};
static_assert(sizeof(CreatureInfo) == 0x394, "CreatureInfo size mismatch");
