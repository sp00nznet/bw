#pragma once
// TownStats — tracks population, resources, and disciple counts for a town
// Struct layout from bw1-decomp
//
// Size: 0x118 bytes (inherits 0x8 from Base)
// Vtable: BaseVftable (inherits Base's 7 virtual methods, overrides destructor)
//
// Embedded directly inside Town struct — not heap-allocated separately.

#include "Base.h"

// Forward declarations
struct BuildingSite;
struct PlannedMultiMapFixed;
struct Villager;

// Forward-declare enum
enum VILLAGER_DISCIPLE : uint32_t;

struct TownStats : public Base {
    // === Override of Base virtuals ===
    ~TownStats() override;  // 0x007391a0

    // === Non-virtual methods ===
    void Remove(Villager* villager);                              // 0x007493c0
    void ChildToAdult(Villager* villager);                        // 0x00749490
    void VillagerMoveOutOfAbode(Villager* villager);              // 0x007494c0
    void Add(PlannedMultiMapFixed* planned);                      // 0x00749a60
    void Add(BuildingSite* building_site);                        // 0x00749aa0
    void IncrementNumOfDisciples(VILLAGER_DISCIPLE disciple);     // 0x00749c60
    void DecrementNumOfDisciples(VILLAGER_DISCIPLE disciple);     // 0x00749c80

    // === Fields ===
    int32_t    num_adults;             // 0x08
    int32_t    num_children;           // 0x0C
    uint32_t   field_0x10;            // 0x10
    uint32_t   field_0x14;            // 0x14
    uint32_t   field_0x18;            // 0x18
    uint32_t   field_0x1c;            // 0x1C
    uint32_t   field_0x20;            // 0x20
    uint32_t   field_0x24;            // 0x24
    uint32_t   field_0x28;            // 0x28
    uint32_t   field_0x2c;            // 0x2C
    uint32_t   field_0x30;            // 0x30
    uint32_t   field_0x34;            // 0x34
    uint32_t   field_0x38;            // 0x38
    uint32_t   field_0x3c;            // 0x3C
    uint32_t   field_0x40;            // 0x40
    int32_t    field_0x44;            // 0x44
    int32_t    field_0x48;            // 0x48
    uint32_t   field_0x4c;            // 0x4C
    uint32_t   field_0x50;            // 0x50
    uint32_t   field_0x54;            // 0x54
    uint32_t   field_0x58;            // 0x58
    uint32_t   field_0x5c[8];         // 0x5C
    uint32_t   field_0x7c[10];        // 0x7C
    uint32_t   field_0xa4[9];         // 0xA4
    uint8_t    num_disciples[16];     // 0xC8  (VILLAGER_DISCIPLE_LAST = 16)
    uint32_t   field_0xd8;            // 0xD8
    uint32_t   field_0xdc;            // 0xDC
    uint32_t   field_0xe0;            // 0xE0
    uint32_t   field_0xe4;            // 0xE4
    uint32_t   field_0xe8;            // 0xE8
    float      wood_used;             // 0xEC
    float      field_0xf0;            // 0xF0
    float      field_0xf4;            // 0xF4
    float      total_food;            // 0xF8
    float      total_wood;            // 0xFC
    uint32_t   field_0x100;           // 0x100
    uint32_t   field_0x104;           // 0x104
    uint32_t   field_0x108;           // 0x108
    void*      field_0x10c;           // 0x10C — BaseVftable*
    uint32_t   field_0x110;           // 0x110
    uint32_t   field_0x114;           // 0x114
};
static_assert(sizeof(TownStats) == 0x118, "TownStats size mismatch");
