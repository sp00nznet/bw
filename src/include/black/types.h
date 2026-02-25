#pragma once
// Common types used throughout Black & White
// Adapted from bw1-decomp's re_common.h and various headers

#include <cstdint>
#include <cstddef>

// Bool type matching original 32-bit bool representation
using bool32_t = uint32_t;

// Forward declarations for core types
struct LHPoint {
    float x, y, z;
};

struct MapCoords {
    int32_t x;  // Upper 16 bits = map coord, lower 16 = cell coord
    int32_t z;
    float altitude;
};
static_assert(sizeof(MapCoords) == 0xC, "MapCoords size mismatch");

// Resource types used by GameThing resource management
enum RESOURCE_TYPE : uint32_t {
    RESOURCE_TYPE_FOOD = 0,
    RESOURCE_TYPE_WOOD = 1,
    RESOURCE_TYPE_ORE  = 2,
    RESOURCE_TYPE_COUNT = 3
};
