// Terrain height query service — global function pointer
// The viewer or host application sets g_terrain_height_func at startup.

#include <black/Terrain.h>

TerrainHeightFunc g_terrain_height_func = nullptr;
