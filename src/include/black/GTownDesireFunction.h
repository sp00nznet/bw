#pragma once
// GTownDesireFunction — function-pointer table for town desire calculations
// Struct layout from bw1-decomp
//
// Size: 0x68 bytes
// Each desire type has a set of function pointers for calculating
// desire values, actual/desired numbers, satisfaction checks, etc.

#include <cstdint>
#include <cstdbool>

// Forward declarations
struct Town;
struct Villager;

struct GTownDesireFunction {
    const char* name;                                             // 0x00
    uint32_t    field_0x04;                                       // 0x04
    uint32_t    field_0x08;                                       // 0x08
    uint32_t    field_0x0c;                                       // 0x0C
    float       (__fastcall* CalculateDesire)(Town* town);        // 0x10
    uint32_t    field_0x14;                                       // 0x14
    uint32_t    field_0x18;                                       // 0x18
    int32_t     field_0x1c;                                       // 0x1C
    int32_t     (__fastcall* CalculateActualNumber)(Town* town);  // 0x20
    uint32_t    field_0x24;                                       // 0x24
    uint32_t    field_0x28;                                       // 0x28
    int32_t     field_0x2c;                                       // 0x2C
    int32_t     (__fastcall* CalculateDesiredNumber)(Town* town); // 0x30
    uint32_t    field_0x34;                                       // 0x34
    uint32_t    field_0x38;                                       // 0x38
    int32_t     field_0x3c;                                       // 0x3C
    bool        (__fastcall* CheckSatisfyDesire)(Villager* villager); // 0x40
    uint32_t    field_0x44;                                       // 0x44
    uint32_t    field_0x48;                                       // 0x48
    int32_t     field_0x4c;                                       // 0x4C
    float       (__fastcall* GetDesireVillagerModification)(Town* town); // 0x50
    uint32_t    field_0x54;                                       // 0x54
    uint32_t    field_0x58;                                       // 0x58
    uint32_t    field_0x5c;                                       // 0x5C
    int32_t     field_0x60;                                       // 0x60
    uint32_t    field_0x64;                                       // 0x64
};
static_assert(sizeof(GTownDesireFunction) == 0x68, "GTownDesireFunction size mismatch");
