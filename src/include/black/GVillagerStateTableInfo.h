#pragma once
// GVillagerStateTableInfo — villager state machine config
// Struct layout from bw1-decomp (VillagerStateTableInfo.h)
//
// Size: 0x114 bytes (extends GBaseInfo)

#include "GBaseInfo.h"

struct GVillagerStateTableInfo {
    GBaseInfo super;           // 0x00
    uint32_t  field_0x10;     // 0x10
    uint32_t  field_0x14;     // 0x14
    uint32_t  field_0x18;     // 0x18
    uint32_t  isFinalState;   // 0x1C
    uint32_t  field_0x20;     // 0x20
    uint32_t  field_0x24;     // 0x24
    uint32_t  isScriptState;  // 0x28
    uint32_t  isScriptInterruptableState; // 0x2C
    uint32_t  field_0x30;     // 0x30
    uint32_t  field_0x34;     // 0x34
    char      name[0x80];     // 0x38
    uint8_t   field_0xb8[0x5C]; // 0xB8
};
static_assert(sizeof(GVillagerStateTableInfo) == 0x114, "GVillagerStateTableInfo size mismatch");
