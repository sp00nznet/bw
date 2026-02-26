#pragma once
// Temple — challenge room / temple front-end manager
// Struct layout from bw1-decomp
//
// Size: 0x54 bytes (standalone, no base class)
// Manages 7 TempleRoom slots and visual parameters (fov, etc.)

#include <cstdint>

struct TempleRoom;

struct Temple {
    TempleRoom*  rooms[7];       // 0x00
    TempleRoom*  active_room;    // 0x1C
    uintptr_t    field_0x20;     // 0x20
    uint32_t     field_0x24;     // 0x24
    float        fov;            // 0x28
    float        field_0x2c;     // 0x2C
    float        field_0x30;     // 0x30
    float        field_0x34;     // 0x34
    float        field_0x38;     // 0x38
    float        field_0x3c;     // 0x3C
    float        field_0x40;     // 0x40
    uint32_t     field_0x44;     // 0x44
    uint8_t      field_0x48;     // 0x48
    uint8_t      field_0x49;     // 0x49
    uint8_t      field_0x4a;     // 0x4A
    uint8_t      field_0x4b;     // 0x4B
    uint8_t      field_0x4c;     // 0x4C
    uint8_t      field_0x4d;     // 0x4D
    uint8_t      field_0x4e;     // 0x4E
    uint8_t      field_0x4f;     // 0x4F
    uint32_t     field_0x50;     // 0x50
};
static_assert(sizeof(Temple) == 0x54, "Temple size mismatch");
