// Mobile class implementation
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)
// Cross-referenced with bw1-decomp (v1.20)
//
// Mobile adds no new virtual methods to Object — it's a thin wrapper
// that adds a single field (field_0x54) which is saved/loaded.

#include <black/Mobile.h>
#include <black/Map.h>

extern GMap* g_map;

// Mobile has no new virtual methods — all inherited from Object.
// The Save/Load methods (not virtual) serialize field_0x54.

// sub_5E8CA0: into the cell under it (sub_5BFA00), and marked as in the map.
// ponytail: the cell's mobile list (vslot 339, sub_5E8D90) is not kept --
// nothing in core walks it, and a moving object would have to be relinked
// (vslot 343) -- so only the flag the predicates read is set. Core builds no
// GMap yet (g_map stays null); without one, every position counts as on it.
void Mobile::InsertMapObject() {
    const uint32_t cx = static_cast<uint32_t>(coords.x) >> 16, cz = static_cast<uint32_t>(coords.z) >> 16;
    if (g_map && !g_map->InBounds(cx, cz)) return;
    field_0x24 |= 1;
}
