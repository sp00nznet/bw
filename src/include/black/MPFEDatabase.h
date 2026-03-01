#pragma once
// MPFEDatabase — multiplayer frontend database query handler
// Struct layout from bw1-decomp (MPFEDatabase.h)
//
// Size: 0xC bytes (own vtable hierarchy with 2 entries)

#include <cstdint>

struct MPFEDatabase {
    virtual void DatabaseError();
    virtual void DatabaseComplete();

    float    progress_percentage;  // 0x04
    uint32_t populated;            // 0x08
};
static_assert(sizeof(MPFEDatabase) == 0xC, "MPFEDatabase size mismatch");
