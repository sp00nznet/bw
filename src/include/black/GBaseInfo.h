#pragma once
// GBaseInfo — base class for all game info/metadata objects
// Struct layout from bw1-decomp
//
// Size: 0x10 bytes
// Forms a linked list of info entries. Has its own vtable (GBaseInfoVftable)
// with GetDebugText, GetDebugColor, GetBaseInfo, UpdateValue.

#include "types.h"

struct GBaseInfo {
    void*       vftable;      // 0x00 — GBaseInfoVftable*
    uint32_t    field_0x04;   // 0x04 — from Base
    GBaseInfo*  next;         // 0x08 — linked list next
    int32_t     index;        // 0x0C — info table index
};
static_assert(sizeof(GBaseInfo) == 0x10, "GBaseInfo size mismatch");
