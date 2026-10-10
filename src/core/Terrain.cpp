// Terrain height query service — global function pointer
// The viewer or host application sets g_terrain_height_func at startup.

#include <black/Terrain.h>
#include <black/types.h>

TerrainHeightFunc g_terrain_height_func = nullptr;
MeshPointsFunc g_mesh_points_func = nullptr;
MeshRadiusFunc g_mesh_radius_func = nullptr;
CellFlagsFunc g_cell_flags_func = nullptr;
CellAltitudeFunc g_cell_altitude_func = nullptr;

float LandHeight(float x, float z) {
    if (!g_cell_altitude_func || !g_cell_flags_func) return GetTerrainHeightAt(x, z);
    const MapCoords c = MapCoordsFromMetres(x, z);
    const uint32_t ux = static_cast<uint32_t>(c.x.full), uz = static_cast<uint32_t>(c.z.full);
    const uint32_t cx = ux >> 16, cz = uz >> 16;
    if (cx >= 512 || cz >= 512) return 0.0f;
    const int32_t a0 = g_cell_altitude_func(cx, cz);
    const int32_t flags = g_cell_flags_func(cx, cz);
    if (a0 < 0 || flags < 0) return 0.0f;
    auto alt = [](uint32_t x_, uint32_t z_) { const int32_t v = g_cell_altitude_func(x_, z_); return v < 0 ? 0 : v; };
    // A (x, z), B (x, z+1), C (x+1, z), D (x+1, z+1).
    int A = a0, B = alt(cx, cz + 1), C = alt(cx + 1, cz), D = alt(cx + 1, cz + 1);
    if (A <= 4) {  // dword_B59D38, set in the shipped game
        if (A <= 3) A = 0;
        if (B <= 3) B = 0;
        if (C <= 3) C = 0;
        if (D <= 3) D = 0;
    }
    const uint32_t lx = ux & 0xFFFF, lz = uz & 0xFFFF;
    // The fourth corner is made from the triangle the point is on.
    if (flags & 0x80) {
        if (lz <= 0xFFFF - lx) D = B + C - A; else A = B + C - D;
    } else {
        if (lx > lz) B = D + A - C; else C = D + A - B;
    }
    const int fx = static_cast<int>(lx >> 8), fz = static_cast<int>(lz >> 8);
    const int near_edge = (A << 8) + fz * (B - A);
    const int far_edge = (C << 8) + fz * (D - C);
    const int h = near_edge + ((fx * (far_edge - near_edge)) >> 8);
    return static_cast<float>(h) * 0.67000002f * 0.00390625f;
}
