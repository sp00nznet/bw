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

// Mesh physics points -- the host owns the meshes. The original's rigid body
// takes the vertices of the mesh's physics submeshes (flag 0x2000, else
// 0x20000000; sub_75A110). Writes up to max_points (x, y, z) triples of
// AllMeshes.g3d entry `mesh_id` into xyz, unscaled, and returns how many;
// 0 when it has none (the physics then uses a 1 m box).
using MeshPointsFunc = int (*)(int32_t mesh_id, float* xyz, int max_points);
extern MeshPointsFunc g_mesh_points_func;

// Landscape cell flags — the host owns the .lnd. Returns the flags word of map
// cell (cx, cz) (LND cell +6), or -1 where there is no cell. The original reads
// it straight from its block grid (sub_5BFBF0).
using CellFlagsFunc = int32_t (*)(uint32_t cell_x, uint32_t cell_z);
extern CellFlagsFunc g_cell_flags_func;

// Its altitude byte (LND cell +4; x 0.67 is metres), or -1 where there is no
// cell -- what the creature's feature map measures heights from (sub_4C1660).
using CellAltitudeFunc = int32_t (*)(uint32_t cell_x, uint32_t cell_z);
extern CellAltitudeFunc g_cell_altitude_func;
