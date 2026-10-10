// Terrain height query service — global function pointer
// The viewer or host application sets g_terrain_height_func at startup.

#include <black/Terrain.h>

TerrainHeightFunc g_terrain_height_func = nullptr;
MeshPointsFunc g_mesh_points_func = nullptr;
MeshRadiusFunc g_mesh_radius_func = nullptr;
CellFlagsFunc g_cell_flags_func = nullptr;
CellAltitudeFunc g_cell_altitude_func = nullptr;
