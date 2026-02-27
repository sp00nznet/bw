#pragma once
// CreatureDesireSource — source data for a creature desire
// Struct layout from bw1-decomp (CreatureMentalDesireSource.h)
//
// Size: 0x10 bytes (plain data, no Base inheritance)
// Linked into per-desire lists inside CreatureDesires.

#include "types.h"

// Forward-declare enum
enum CREATURE_DESIRE_SOURCE : uint32_t;

struct CreatureDesireSource {
    float                    value;      // 0x00
    float                    field_0x4;  // 0x04
    float                    field_0x8;  // 0x08
    CREATURE_DESIRE_SOURCE   type;       // 0x0C
};
static_assert(sizeof(CreatureDesireSource) == 0x10, "CreatureDesireSource size mismatch");

// Per-type linked list (8 bytes: first + last pointers)
struct LHLinkedList_CreatureDesireSource {
    CreatureDesireSource* first;
    CreatureDesireSource* last;
};
static_assert(sizeof(LHLinkedList_CreatureDesireSource) == 0x8, "LHLinkedList_CreatureDesireSource size mismatch");
