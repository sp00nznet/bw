// SingleMapFixed class implementation
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)
// Cross-referenced with bw1-decomp (v1.20)
//
// SingleMapFixed objects occupy exactly one map cell (trees, rocks, etc.)
// Map insertion links the object into the cell's fixed object linked list.

#include <black/SingleMapFixed.h>
#include <black/Map.h>

extern GMap* g_map;

void SingleMapFixed::CreateCollideData() {}

void SingleMapFixed::InsertMapObject() {
    // Original at 0x005c53d0 — inserts this object into the map cell
    // Convert world coords to cell coords (upper 16 bits = cell index)
    if (!g_map) return;
    uint32_t cell_x = static_cast<uint32_t>(coords.x) >> 16;
    uint32_t cell_z = static_cast<uint32_t>(coords.z) >> 16;
    if (!g_map->InBounds(cell_x, cell_z)) return;

    MapCell* cell = g_map->ToMap(cell_x, cell_z);
    // Link into the fixed object list: new object becomes head
    map_parent = cell->first_object_fixed;
    cell->SetFirstObjectFixed(this);

    // Set the "in map" flag (bit 0 of field_0x24)
    field_0x24 |= 1;

    // Store the object coords for movement tracking
    obj_coords = coords;
}

void SingleMapFixed::RemoveMapObject() {
    // Original at 0x005c5470 — removes this object from its map cell
    if (!g_map) return;
    uint32_t cell_x = static_cast<uint32_t>(obj_coords.x) >> 16;
    uint32_t cell_z = static_cast<uint32_t>(obj_coords.z) >> 16;
    if (!g_map->InBounds(cell_x, cell_z)) return;

    MapCell* cell = g_map->ToMap(cell_x, cell_z);

    // Unlink from the fixed object list
    Object* prev = nullptr;
    Object* curr = cell->first_object_fixed;
    while (curr) {
        if (curr == this) {
            if (prev) {
                prev->map_parent = map_parent;
            } else {
                cell->SetFirstObjectFixed(map_parent);
            }
            map_parent = nullptr;
            break;
        }
        prev = curr;
        curr = curr->map_parent;
    }

    // Clear the "in map" flag
    field_0x24 &= ~1;
}
