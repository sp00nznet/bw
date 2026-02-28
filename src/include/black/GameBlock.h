#pragma once
// GameBlock — per-cell object container for map spatial indexing
// Struct layout from bw1-decomp (JCGameBlock.h)
//
// Size: 0x14 bytes
// Plain data struct, no vtable

#include <cstdint>

struct Object;
struct MapCell;

struct GameBlock {
    uint32_t size;           // 0x00
    uint32_t capacity;       // 0x04
    Object** array;          // 0x08
    Object*  last_inserted;  // 0x0C
    Object*  last_removed;   // 0x10
};
static_assert(sizeof(GameBlock) == 0x14, "GameBlock size mismatch");
