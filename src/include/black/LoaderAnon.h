#pragma once
// LoaderAnon — anonymous data loader helper
// Struct layout from bw1-decomp (LoaderAnon.h)
//
// Size: 0x4 bytes (plain data, no vtable)

#include <cstdint>

struct LoaderAnon {
    uint32_t field_0x0;  // 0x0
};
static_assert(sizeof(LoaderAnon) == 0x4, "LoaderAnon size mismatch");
