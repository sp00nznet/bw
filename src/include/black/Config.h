#pragma once
// Config — game configuration file handler
// Struct layout from bw1-decomp (Config.h)
//
// Size: 0x110 bytes (plain data, no vtable)
// Contains an LHOSFile (0x8) at offset 0x0

#include <cstdint>

struct Config {
    uint8_t file[0x8];          // 0x00 — LHOSFile (opaque, own vtable hierarchy)
    uint8_t field_0x8[0x104];   // 0x08
    int     field_0x10c;        // 0x10C
};
static_assert(sizeof(Config) == 0x110, "Config size mismatch");
