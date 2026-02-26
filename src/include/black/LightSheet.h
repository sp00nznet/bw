#pragma once
// LightSheet — visual effect sheet (force field / charging glow)
// Struct layout from bw1-decomp
//
// Size: 0x60 bytes

#include "types.h"

// Forward declarations
struct LH3DMaterial;

struct LightSheet {
    int       count;           // 0x00
    float     field_0x4;       // 0x04
    float     field_0x8;       // 0x08
    float     field_0xc;       // 0x0C
    float     field_0x10;      // 0x10
    float     field_0x14;      // 0x14
    float     field_0x18;      // 0x18
    float     field_0x1c;      // 0x1C
    LHPoint*  field_0x20;      // 0x20
    float*    field_0x24;      // 0x24
    float*    field_0x28;      // 0x28
    uint32_t  field_0x2c;      // 0x2C
    uint32_t  field_0x30;      // 0x30
    float     field_0x34;      // 0x34
    uint32_t  field_0x38;      // 0x38
    uint32_t  field_0x3c;      // 0x3C
    float     field_0x40;      // 0x40
    float*    field_0x44;      // 0x44
    uint16_t* field_0x48;      // 0x48
    float*    field_0x4c;      // 0x4C
    uint32_t  field_0x50;      // 0x50
    int       field_0x54;      // 0x54
    LH3DMaterial* material_0x58; // 0x58
    uint32_t  field_0x5c;      // 0x5C
};
static_assert(sizeof(LightSheet) == 0x60, "LightSheet size mismatch");
