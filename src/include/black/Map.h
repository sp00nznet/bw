#pragma once
// Map — 512x512 cell grid that objects live on
// Struct layout from bw1-decomp
//
// MapCell: 0x8 bytes — linked list heads for mobile and fixed objects
// MapCellIterator: 0xC bytes — traversal state for cell contents
// GMap: 0x200050 bytes — the map grid (inherits 0x8 from Base)

#include "Base.h"
#include "types.h"

struct Object;
struct Fixed;

// A single cell in the map grid. Each cell holds two linked lists:
// one for mobile objects and one for fixed objects.
struct MapCell {
    Object* first_object_mobile;  // 0x0 — head of mobile object linked list
    Object* first_object_fixed;   // 0x4 — head of fixed object linked list

    void Clean();
    void SetFirstObjectMobile(Object* obj);
    void SetFirstObjectFixed(Object* obj);
};
static_assert(sizeof(MapCell) == 0x8, "MapCell size mismatch");

// Iterator for traversing all objects in a map cell
struct MapCellIterator {
    Object*  object;    // 0x0 — current object
    bool     is_fixed;  // 0x4 — true if iterating fixed objects
    MapCell* cell;      // 0x8 — cell being iterated
};
static_assert(sizeof(MapCellIterator) == 0xC, "MapCellIterator size mismatch");

// The game map: 512x512 grid of MapCells (2 MB of cell data alone)
struct GMap : public Base {
    uint8_t  field_0x8;             // 0x08
    uint8_t  field_0x9;             // 0x09
    uint8_t  field_0xa;             // 0x0A
    uint8_t  field_0xb;             // 0x0B
    uint32_t cell_extent_zx[2];     // 0x0C — [0]=z extent, [1]=x extent
    uint32_t field_0x14;            // 0x14
    uint32_t field_0x18;            // 0x18
    uint32_t field_0x1c;            // 0x1C
    uint32_t field_0x20;            // 0x20
    uint32_t field_0x24;            // 0x24
    uint32_t field_0x28;            // 0x28
    uint32_t field_0x2c;            // 0x2C
    uint32_t field_0x30;            // 0x30
    uint32_t field_0x34;            // 0x34
    uint32_t field_0x38;            // 0x38
    uint8_t  field_0x3c;            // 0x3C
    uint8_t  field_0x3d;            // 0x3D
    uint8_t  field_0x3e;            // 0x3E
    uint8_t  field_0x3f;            // 0x3F
    uint32_t field_0x40;            // 0x40
    MapCell  cells[0x200][0x200];   // 0x44 — 512x512 grid (2,097,152 bytes)
    uint16_t count_0x200044;        // 0x200044
    uint8_t  field_0x200046;        // 0x200046
    uint8_t  field_0x200047;        // 0x200047
    uint8_t  field_0x200048;        // 0x200048
    uint8_t  field_0x200049;        // 0x200049
    uint8_t  field_0x20004a;        // 0x20004A
    uint8_t  field_0x20004b;        // 0x20004B
    uint8_t  field_0x20004c;        // 0x20004C
    uint8_t  field_0x20004d;        // 0x20004D
    uint8_t  field_0x20004e;        // 0x20004E
    uint8_t  field_0x20004f;        // 0x20004F

    // Non-virtual methods
    MapCell* ToMap(uint32_t cell_x, uint32_t cell_z);
    bool InBounds(uint32_t x, uint32_t z) const;
};
static_assert(sizeof(GMap) == 0x200050, "GMap size mismatch");

// Global map instance (set during GGame initialization)
extern GMap* g_map;
