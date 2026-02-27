#pragma once
// CreatureHelpState — creature help system state
// Struct layout from bw1-decomp (CreatureHelp.h)
//
// Also defines CreatureHelpStackEntry (0x1C) — help stack entry.

#include "types.h"

struct GameThingWithPos;

struct CreatureHelpStackEntry {
    uint32_t          field_0x0;   // 0x00
    GameThingWithPos* thing;       // 0x04
    MapCoords         coords;      // 0x08
    uint32_t          field_0x14;  // 0x14
    uint32_t          field_0x18;  // 0x18
};
static_assert(sizeof(CreatureHelpStackEntry) == 0x1C, "CreatureHelpStackEntry size mismatch");

// Per-type linked list (LH_LINKED_LIST pattern)
struct LHLinkedList_CreatureHelpStackEntry {
    CreatureHelpStackEntry* first;
    CreatureHelpStackEntry* last;
};
static_assert(sizeof(LHLinkedList_CreatureHelpStackEntry) == 0x8, "LHLinkedList_CreatureHelpStackEntry size mismatch");

// GJVector<uint8_t> — dynamic byte vector for help state
struct GJVector_CreatureHelpStateField {
    uint32_t field_0x0;   // 0x00
    uint32_t field_0x4;   // 0x04
    uint32_t field_0x8;   // 0x08
    uint32_t field_0xc;   // 0x0C
};
static_assert(sizeof(GJVector_CreatureHelpStateField) == 0x10, "GJVector_CreatureHelpStateField size mismatch");

struct CreatureHelpState {
    uint32_t                       field_0x0;       // 0x00
    uint32_t                       field_0x4;       // 0x04
    uint32_t                       field_0x8;       // 0x08
    uint32_t                       field_0xc;       // 0x0C
    uint32_t                       field_0x10[0xC]; // 0x10
    uint32_t                       field_0x40[0xC]; // 0x40
    uint32_t                       field_0x70[0x6]; // 0x70
    GJVector_CreatureHelpStateField field_0x88;      // 0x88
};
static_assert(sizeof(CreatureHelpState) == 0x98, "CreatureHelpState size mismatch");
