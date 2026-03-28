#pragma once
// Terrain height query service
// Provides a global terrain height function that bw_core can call.
// The viewer (or any host) registers its terrain implementation on startup.

#include <cstdint>

// Function pointer type: given world X, Z returns terrain height Y
using TerrainHeightFunc = float (*)(float world_x, float world_z);

// Global terrain height query — set by the viewer/host at startup
extern TerrainHeightFunc g_terrain_height_func;

// Convenience wrapper
inline float GetTerrainHeightAt(float x, float z) {
    if (g_terrain_height_func) return g_terrain_height_func(x, z);
    return 0.0f;
}
