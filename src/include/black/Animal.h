#pragma once
// Animal — non-player animals (cows, sheep, wolves, etc.)
// Struct layout from bw1-decomp
//
// Size: 0x148 bytes (inherits 0xE0 from Living)
// Vtable: same as Living (0xB40 — no new virtual methods)

#include "Living.h"

struct Animal : public Living {
    // No new virtual methods — inherits Living's vtable

    // === Fields ===
    uint8_t  field_0xe0[0x2C];   // 0xE0 — various state data (44 bytes)
    uint8_t  death_reason;        // 0x10C
    uint8_t  pad_0x10d[3];       // 0x10D-0x10F — padding
    float    field_0x110;        // 0x110
    float    field_0x114;        // 0x114
    float    field_0x118;        // 0x118
    float    field_0x11c;        // 0x11C
    float    field_0x120;        // 0x120
    float    field_0x124;        // 0x124
    float    field_0x128;        // 0x128
    float    field_0x12c;        // 0x12C
    float    field_0x130;        // 0x130
    float    field_0x134;        // 0x134
    float    field_0x138;        // 0x138
    float    field_0x13c;        // 0x13C
    float    field_0x140;        // 0x140
    float    field_0x144;        // 0x144
};
static_assert(sizeof(Animal) == 0x148, "Animal size mismatch");
