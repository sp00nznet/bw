// MapCoords utility method implementations
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)
// Cross-referenced with bw1-decomp (v1.20)
//
// Methods here depend on the global g_map pointer and therefore
// cannot be inlined in types.h.

#include <black/Map.h>

MapCell* MapCoords::ToMap() const {
    // Original at win1.41 0x00603430
    // Converts coordinates to a map cell using the upper 16 bits (cell index)
    return g_map->ToMap(x.split.map, z.split.map);
}

bool32_t MapCoords::InBounds() const {
    // Original at win1.41 0x006042c0
    return g_map->InBounds(x.split.map, z.split.map);
}
