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

namespace {
// sub_5BFA00: the cell under a position, or null off the map.
MapCell* CellAt(const MapCoords& c) {
    const uint32_t cx = static_cast<uint32_t>(c.x) >> 16, cz = static_cast<uint32_t>(c.z) >> 16;
    return g_map && g_map->InBounds(cx, cz) ? g_map->ToMap(cx, cz) : nullptr;
}
}  // namespace

// sub_4140F0 / sub_414120: the next in its cell's list is +0x20.
Object* Mobile::GetMapChild(const MapCell*) { return map_child; }
void Mobile::SetMapChild(Object* o, MapCell*) { map_child = o; }

// sub_5E8CA0: into the cell under it (vslot 339), and marked as in the map.
// Without a GMap (a host that builds none), only the flag is set.
void Mobile::InsertMapObject() {
    if (!g_map) {
        field_0x24 |= 1;
        return;
    }
    if (MapCell* cell = CellAt(coords)) {
        InsertMapObjectToCell(cell);
        field_0x24 |= 1;
    }
}

// sub_5E8D00
void Mobile::RemoveMapObject() {
    if (!g_map) {
        field_0x24 &= ~1u;
        return;
    }
    if (MapCell* cell = CellAt(coords)) {
        RemoveMapObjectFromCell(cell);
        field_0x24 &= ~1u;
    }
}

// sub_5E8D90: at the head of the cell's mobile list, linked both ways (+0x20
// next, +0x38 previous).
// ponytail: one flagged 0x8000 goes on the end of the fixed list in v1.0;
// nothing in core sets that flag, and core's fixed lists chain through +0x38,
// so that branch is left out. Nor are the game block's record of it
// (sub_59DB30) and the 0x100-info hook (sub_5A2B10) translated.
void Mobile::InsertMapObjectToCell(MapCell* cell) {
    if (Object* head = cell->first_object_mobile) {
        head->map_parent = this;
        SetMapChild(head, cell);
    }
    cell->SetFirstObjectMobile(this);
}

// sub_5E8E30
void Mobile::RemoveMapObjectFromCell(MapCell* cell) {
    Object* next = GetMapChild(cell);
    if (Object* prev = map_parent) {
        prev->SetMapChild(next, cell);
        if (next) next->map_parent = prev;
        map_parent = nullptr;
    } else {
        cell->SetFirstObjectMobile(next);
        if (next) next->map_parent = nullptr;
    }
    SetMapChild(nullptr, cell);
}

// sub_5E8FA0: within its cell it only moves (6); into another it is relinked
// (vslot 344, sub_5EA470: out, moved, in) (7).
int Mobile::MoveMapObject(const MapCoords& c) {
    if ((static_cast<uint32_t>(coords.x) >> 16) == (static_cast<uint32_t>(c.x) >> 16) &&
        (static_cast<uint32_t>(coords.z) >> 16) == (static_cast<uint32_t>(c.z) >> 16)) {
        coords = c;
        return 6;
    }
    ActualMoveMapObject(c);
    return 7;
}

void Mobile::ActualMoveMapObject(const MapCoords& c) {
    RemoveMapObject();
    SetPos(c);
    InsertMapObject();
}
