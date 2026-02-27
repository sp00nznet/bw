#pragma once
// Common types used throughout Black & White
// Adapted from bw1-decomp's re_common.h and MapCoords.h

#include <cstdint>
#include <cstddef>

// Bool type matching original 32-bit bool representation
using bool32_t = uint32_t;

// Forward declarations for core types
struct LHPoint {
    float x, y, z;
};

// Map coordinate split: cell-local + map-global
struct MapCoordsSplit {
    uint16_t cell;  // 0x0 — sub-cell position (fractional)
    uint16_t map;   // 0x2 — cell index on grid
};
static_assert(sizeof(MapCoordsSplit) == 0x4, "MapCoordsSplit size mismatch");

// Full coordinate component: accessible as int32_t or split cell/map pair
union MapCoordsFull {
    int32_t full;
    MapCoordsSplit split;

    // Allow transparent use as int32_t in arithmetic and comparison
    MapCoordsFull() = default;
    MapCoordsFull(int32_t v) : full(v) {}
    operator int32_t() const { return full; }
};
static_assert(sizeof(MapCoordsFull) == 0x4, "MapCoordsFull size mismatch");

// Forward declarations for MapCoords methods
struct MapCell;

// 3D map coordinate (X/Z position + altitude)
struct MapCoords {
    MapCoordsFull x;   // 0x0
    MapCoordsFull z;   // 0x4
    float altitude;    // 0x8

    // Constructors (original at 0x00441b60, 0x006031b0)
    MapCoords() : x(0), z(0), altitude(0.0f) {}
    MapCoords(int32_t x_, int32_t z_, float alt) : x(x_), z(z_), altitude(alt) {}

    // Operators (original at 0x00605660, 0x006056b0, 0x00605410)
    bool operator==(const MapCoords& o) const { return x.full == o.x.full && z.full == o.z.full; }
    bool operator!=(const MapCoords& o) const { return !(*this == o); }

    MapCoords& operator+=(const MapCoords& o) {
        x.full += o.x.full;
        z.full += o.z.full;
        altitude += o.altitude;
        return *this;
    }

    // Map lookup (implemented in MapCoords.cpp — requires g_map)
    MapCell* ToMap() const;
    bool32_t InBounds() const;
};
static_assert(sizeof(MapCoords) == 0xC, "MapCoords size mismatch");

// 2D map position (int16 precision, no altitude)
struct JustMapXZ {
    int16_t x;  // 0x0
    int16_t z;  // 0x2
};
static_assert(sizeof(JustMapXZ) == 0x4, "JustMapXZ size mismatch");

// 2D whole-map position (full int32 precision, no altitude)
struct JustWholeMapXZ {
    int32_t x;  // 0x0
    int32_t z;  // 0x4
};
static_assert(sizeof(JustWholeMapXZ) == 0x8, "JustWholeMapXZ size mismatch");

// 3D color (ARGB packed)
struct LH3DColor {
    uint32_t color;
};

// Resource types used by GameThing resource management
enum RESOURCE_TYPE : uint32_t {
    RESOURCE_TYPE_FOOD = 0,
    RESOURCE_TYPE_WOOD = 1,
    RESOURCE_TYPE_ORE  = 2,
    RESOURCE_TYPE_COUNT = 3
};
