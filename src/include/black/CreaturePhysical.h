#pragma once
// CreaturePhysical — creature physical simulation state
// Struct layout from bw1-decomp (CreaturePhysical.h)
//
// Also defines CreatureDamageMap (0x10) — damage tracking map.

#include "Base.h"
#include "types.h"

struct Creature;
struct CreatureInfo;
struct LH3DCreature;

struct CreatureDamageMap : public Base {
    uint32_t field_0x8;   // 0x08
    uint32_t field_0xc;   // 0x0C
};
static_assert(sizeof(CreatureDamageMap) == 0x10, "CreatureDamageMap size mismatch");

struct CreaturePhysical : public Base {
    uint32_t          field_0x8;      // 0x08
    float             strength;       // 0x0C
    uint32_t          field_0x10;     // 0x10
    float             field_0x14;     // 0x14
    float             field_0x18;     // 0x18
    uint32_t          field_0x1c;     // 0x1C
    uint32_t          field_0x20;     // 0x20
    uint16_t          field_0x24;     // 0x24
    uint8_t           field_0x26;     // 0x26
    uint8_t           field_0x27;     // 0x27
    uint32_t          field_0x28;     // 0x28
    uint32_t          field_0x2c;     // 0x2C
    float             field_0x30;     // 0x30
    uint32_t          field_0x34;     // 0x34
    uint32_t          field_0x38;     // 0x38
    float             field_0x3c;     // 0x3C
    uint32_t          field_0x40;     // 0x40
    uint32_t          field_0x44;     // 0x44
    float             field_0x48;     // 0x48
    uint32_t          field_0x4c;     // 0x4C
    uint32_t          field_0x50;     // 0x50
    Creature*         creature;       // 0x54
    LH3DCreature*     creature_3d;    // 0x58
    CreatureDamageMap damage_map;     // 0x5C
    uint8_t*          field_0x6c;     // 0x6C
    uint32_t          field_0x70;     // 0x70
};
static_assert(sizeof(CreaturePhysical) == 0x74, "CreaturePhysical size mismatch");
