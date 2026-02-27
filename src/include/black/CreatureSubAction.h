#pragma once
// CreatureSubAction — sub-action execution unit
// Struct layout from bw1-decomp (CreatureSubAction.h)
//
// Size: 0x60 bytes (inherits 0x8 from Base)
// Also defines CreatureSubActionAgenda (0xC50) — array of 32 sub-actions.

#include "Base.h"
#include "types.h"

struct Creature;

struct CreatureSubAction : public Base {
    uint8_t  field_0x8[0x4];   // 0x08-0x0B
    uint32_t field_0xc;        // 0x0C
    uint8_t  field_0x10[0x4];  // 0x10-0x13
    LHPoint  field_0x14;       // 0x14
    uint8_t  field_0x20[0xC];  // 0x20-0x2B
    uint32_t field_0x2c;       // 0x2C
    uint8_t  field_0x30[0x30]; // 0x30-0x5F
};
static_assert(sizeof(CreatureSubAction) == 0x60, "CreatureSubAction size mismatch");

struct CreatureSubActionAgenda : public Base {
    uint32_t         field_0x8;            // 0x08
    uint32_t         field_0xc;            // 0x0C
    uint32_t         field_0x10;           // 0x10
    uint32_t         field_0x14;           // 0x14
    uint32_t         field_0x18;           // 0x18
    int              field_0x1c;           // 0x1C
    uint32_t         field_0x20;           // 0x20
    uint32_t         field_0x24;           // 0x24
    CreatureSubAction sub_actions[0x20];   // 0x28 — 32 sub-actions
    Creature*        creature;             // 0xC28
    uint32_t         field_0xc2c;          // 0xC2C
    uint32_t         field_0xc30;          // 0xC30
    uint32_t         field_0xc34;          // 0xC34
    uint32_t         field_0xc38;          // 0xC38
    uint32_t         field_0xc3c;          // 0xC3C
    uint32_t         field_0xc40;          // 0xC40
    uint32_t         field_0xc44;          // 0xC44
    uint32_t         field_0xc48;          // 0xC48
    uint32_t         field_0xc4c;          // 0xC4C
};
static_assert(sizeof(CreatureSubActionAgenda) == 0xC50, "CreatureSubActionAgenda size mismatch");
