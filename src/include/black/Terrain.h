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

// Mesh extent query — the host owns the meshes. The original sizes an abode
// from its 3D object's bounds (Abode vslot 25, sub_5EA550: the larger of two
// horizontal bounds, times scale); bw_core has no meshes, so it asks the host
// for the largest horizontal bound of AllMeshes.g3d entry `mesh_id`, in metres.
using MeshRadiusFunc = float (*)(int32_t mesh_id);
extern MeshRadiusFunc g_mesh_radius_func;

// Landscape cell flags — the host owns the .lnd. Returns the flags word of map
// cell (cx, cz) (LND cell +6), or -1 where there is no cell. The original reads
// it straight from its block grid (sub_5BFBF0).
using CellFlagsFunc = int32_t (*)(uint32_t cell_x, uint32_t cell_z);
extern CellFlagsFunc g_cell_flags_func;
