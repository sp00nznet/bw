#pragma once
// Settings — game configuration settings
// Struct layout from bw1-decomp
//
// Size: 0x104 bytes
// Plain data struct, no vtable

#include <cstdint>

struct Settings {
    char     quest_path[0x1];    // 0x00
    uint8_t  field_0x1[0x103];   // 0x01
};
static_assert(sizeof(Settings) == 0x104, "Settings size mismatch");
