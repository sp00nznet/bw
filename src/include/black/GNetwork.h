#pragma once
// GNetwork — network/multiplayer state
// Struct layout from bw1-decomp
//
// Size: 0x14 bytes
// Plain data struct, no vtable

#include <cstdint>

struct LHSession;

struct GNetwork {
    uint8_t    field_0x0;   // 0x00
    uint8_t    field_0x1;   // 0x01
    uint8_t    field_0x2;   // 0x02
    uint8_t    field_0x3;   // 0x03
    uint8_t    field_0x4;   // 0x04
    uint8_t    field_0x5;   // 0x05
    uint8_t    field_0x6;   // 0x06
    uint8_t    field_0x7;   // 0x07
    uint8_t    field_0x8;   // 0x08
    uint8_t    field_0x9;   // 0x09
    uint8_t    field_0xa;   // 0x0A
    uint8_t    field_0xb;   // 0x0B
    uint8_t    field_0xc;   // 0x0C
    uint8_t    field_0xd;   // 0x0D
    uint8_t    field_0xe;   // 0x0E
    uint8_t    field_0xf;   // 0x0F
    LHSession* session;     // 0x10
};
static_assert(sizeof(GNetwork) == 0x14, "GNetwork size mismatch");
