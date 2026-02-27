#pragma once
// GMagicEffectInfo — info for magic visual effects
// Struct layout from bw1-decomp (MagicEffectInfo.h)
//
// Size: 0x11C bytes (extends GEffectInfo)

#include "GEffectInfo.h"

struct GMagicEffectInfo {
    GEffectInfo super;       // 0x00
    char        name[0x30];  // 0x34
    uint32_t    field_0x64;  // 0x64
    uint32_t    field_0x68;  // 0x68
    uint32_t    field_0x6c;  // 0x6C
    uint32_t    field_0x70;  // 0x70
    float       field_0x74;  // 0x74
    float       field_0x78;  // 0x78
    float       field_0x7c;  // 0x7C
    float       field_0x80;  // 0x80
    float       field_0x84;  // 0x84
    uint32_t    field_0x88;  // 0x88
    uint32_t    field_0x8c;  // 0x8C
    uint32_t    field_0x90;  // 0x90
    int32_t     field_0x94;  // 0x94
    uint32_t    field_0x98;  // 0x98
    uint32_t    field_0x9c;  // 0x9C
    int32_t     field_0xa0;  // 0xA0
    uint32_t    field_0xa4;  // 0xA4
    float       field_0xa8;  // 0xA8
    float       field_0xac;  // 0xAC
    float       field_0xb0;  // 0xB0
    float       field_0xb4;  // 0xB4
    float       field_0xb8;  // 0xB8
    float       field_0xbc;  // 0xBC
    float       field_0xc0;  // 0xC0
    float       field_0xc4;  // 0xC4
    float       field_0xc8;  // 0xC8
    uint32_t    field_0xcc;  // 0xCC
    uint32_t    field_0xd0;  // 0xD0
    uint32_t    field_0xd4;  // 0xD4
    uint32_t    field_0xd8;  // 0xD8
    uint32_t    field_0xdc;  // 0xDC
    uint32_t    field_0xe0;  // 0xE0
    uint32_t    field_0xe4;  // 0xE4
    uint32_t    field_0xe8;  // 0xE8
    uint32_t    field_0xec;  // 0xEC
    uint32_t    field_0xf0;  // 0xF0
    uint32_t    field_0xf4;  // 0xF4
    uint32_t    field_0xf8;  // 0xF8
    uint32_t    field_0xfc;  // 0xFC
    uint32_t    field_0x100; // 0x100
    uint32_t    field_0x104; // 0x104
    uint32_t    field_0x108; // 0x108
    uint32_t    field_0x10c; // 0x10C
    uint32_t    field_0x110; // 0x110
    float       field_0x114; // 0x114
    float       field_0x118; // 0x118
};
static_assert(sizeof(GMagicEffectInfo) == 0x11C, "GMagicEffectInfo size mismatch");
