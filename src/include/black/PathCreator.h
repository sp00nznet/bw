#pragma once
// PathCreator — filesystem path management
// Struct layout from bw1-decomp (PathCreator.h)
//
// Size: 0x220 bytes (plain data, no vtable)

#include <cstdint>

struct PathCreator {
    char*     dev_black;      // 0x00
    char*     profiles;       // 0x04
    char*     saved_games;    // 0x08
    char*     pictures;       // 0x0C
    char*     current;        // 0x10
    char*     field_0x14;     // 0x14
    char      field_0x18[0x10];   // 0x18
    uint8_t   field_0x28[0xF4];   // 0x28
    char      field_0x11c[0x44];  // 0x11C
    uint8_t   field_0x160[0xBC];  // 0x160
    char16_t* field_0x21c;        // 0x21C
};
static_assert(sizeof(PathCreator) == 0x220, "PathCreator size mismatch");
