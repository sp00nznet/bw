#pragma once
// GGlobal — master global state container
// Struct layout from bw1-decomp
// Size: 0x2D500 bytes

#include "GDebug.h"

#include <stdint.h>

struct GAudio;

struct GGlobal {
    GAudio*  audio;                          // 0x00
    GDebug   debug;                          // 0x04
    void*    (__cdecl* field_0x2d2ac)(void); // 0x2D2AC
    uint32_t field_0x2d2b0;                  // 0x2D2B0
    uint32_t field_0x2d2b4;                  // 0x2D2B4
    uint32_t field_0x2d2b8;                  // 0x2D2B8
    uint32_t field_0x2d2bc;                  // 0x2D2BC
    uint32_t field_0x2d2c0;                  // 0x2D2C0
    uint32_t field_0x2d2c4;                  // 0x2D2C4
    uint32_t field_0x2d2c8;                  // 0x2D2C8
    uint32_t field_0x2d2cc;                  // 0x2D2CC
    uint32_t field_0x2d2d0;                  // 0x2D2D0
    uint32_t field_0x2d2d4;                  // 0x2D2D4
    uint32_t field_0x2d2d8;                  // 0x2D2D8
    uint32_t field_0x2d2dc;                  // 0x2D2DC
    uint32_t field_0x2d2e0;                  // 0x2D2E0
    void*    (__cdecl* field_0x2d2e4)(void); // 0x2D2E4
    uint8_t  field_0x2d2e8[0xC];             // 0x2D2E8
    char     current_directory[0x100];       // 0x2D2F4
    uint8_t  field_0x2d3f4[0x10C];           // 0x2D3F4
};
static_assert(sizeof(GGlobal) == 0x2D500, "GGlobal size mismatch");
