// Map class implementation
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)
// Cross-referenced with bw1-decomp (v1.20)
//
// GMap is the 512x512 cell grid that all game objects are placed on.
// Each MapCell holds linked lists of mobile and fixed objects.

#include <cstdlib>
#include <cstring>
#include <black/Map.h>

// Global map pointer (set during GGame initialization)
GMap* g_map = nullptr;

// ============================================================================
// MapCell methods
// ============================================================================

void MapCell::Clean() {
    // Original at win1.41 0x00601380
    first_object_mobile = nullptr;
    first_object_fixed = nullptr;
}

void MapCell::SetFirstObjectMobile(Object* obj) {
    // Original at win1.41 0x00601b60
    first_object_mobile = obj;
}

void MapCell::SetFirstObjectFixed(Object* obj) {
    // Original at win1.41 0x00601b70
    first_object_fixed = obj;
}

// ============================================================================
// GMap methods
// ============================================================================

MapCell* GMap::ToMap(uint32_t cell_x, uint32_t cell_z) {
    // v1.0 sub_5BFA00: cell + 8 * (z + x * extent) -- x-major.
    return &cells[cell_x][cell_z];
}

// The game's map (game +6772): emptied and sized at level load.
GMap* ResetMap() {
    static GMap* m = static_cast<GMap*>(std::calloc(1, sizeof(GMap)));  // ponytail: Base's vtable is never called on it
    std::memset(static_cast<void*>(m), 0, sizeof(GMap));
    m->cell_extent_zx[0] = m->cell_extent_zx[1] = 0x200;
    g_map = m;
    return m;
}

bool GMap::InBounds(uint32_t x, uint32_t z) const {
    // Original at win1.41 0x00612690
    // cell_extent_zx[0] = z extent, cell_extent_zx[1] = x extent
    return x < cell_extent_zx[1] && z < cell_extent_zx[0];
}
