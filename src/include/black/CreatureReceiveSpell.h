#pragma once
// CreatureReceiveSpell — tracks spells received by a creature
// Struct layout from bw1-decomp (CreatureReceiveSpell.h)
//
// Size: 0x1D8 bytes (plain data, NOT Base-derived)

#include "types.h"

struct Creature;

// Per-spell tracking data
struct CreatureReceiveSpellPerSpellData {
    uint32_t field_0x0;   // 0x00
    uint32_t field_0x4;   // 0x04
    uint32_t field_0x8;   // 0x08
    uint32_t field_0xc;   // 0x0C
    uint32_t field_0x10;  // 0x10
    uint32_t field_0x14;  // 0x14
};
static_assert(sizeof(CreatureReceiveSpellPerSpellData) == 0x18, "CreatureReceiveSpellPerSpellData size mismatch");

// GJVector<uint8_t> — spell queue data
struct GJVector_CreatureReceiveSpellQueueData {
    uint32_t field_0x0;   // 0x00
    uint32_t field_0x4;   // 0x04
    uint32_t field_0x8;   // 0x08
    uint32_t field_0xc;   // 0x0C
};
static_assert(sizeof(GJVector_CreatureReceiveSpellQueueData) == 0x10, "GJVector_CreatureReceiveSpellQueueData size mismatch");

struct CreatureReceiveSpell {
    Creature*                              creature;       // 0x00
    CreatureReceiveSpellPerSpellData       data[0x10];     // 0x04
    GJVector_CreatureReceiveSpellQueueData queue_data;     // 0x184
    uint8_t                                field_0x194[8]; // 0x194
    LHPoint                                field_0x19c;    // 0x19C
    LHPoint                                field_0x1a8;    // 0x1A8
    LHPoint                                field_0x1b4;    // 0x1B4
    LHPoint                                field_0x1c0;    // 0x1C0
    float                                  field_0x1cc;    // 0x1CC
    uint32_t                               field_0x1d0;    // 0x1D0
    uint8_t                                field_0x1d4;    // 0x1D4
};
static_assert(sizeof(CreatureReceiveSpell) == 0x1D8, "CreatureReceiveSpell size mismatch");
