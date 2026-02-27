#pragma once
// CreatureActionContext — action execution context
// Struct layout from bw1-decomp (CreatureAction.h)
//
// Contains CreatureActionContextStart (0x14) and CreatureActionContext (0x18).
// PreviousActionContextStack (0x13DC0) is a large 2D stack of contexts.

#include "types.h"

struct CreatureActionContext;

struct CreatureActionContextStart {
    uint32_t                  field_0x0;  // 0x00
    CreatureActionContext*    field_0x4;  // 0x04
    uint32_t                  field_0x8;  // 0x08
    uint32_t                  field_0xc;  // 0x0C
    uint32_t                  field_0x10; // 0x10
};
static_assert(sizeof(CreatureActionContextStart) == 0x14, "CreatureActionContextStart size mismatch");

struct CreatureActionContext {
    CreatureActionContextStart start;      // 0x00
    float                      field_0x14; // 0x14
};
static_assert(sizeof(CreatureActionContext) == 0x18, "CreatureActionContext size mismatch");

struct PreviousActionContextStack {
    uint32_t              indexes[2][0x148];       // 0x000
    CreatureActionContext stack[0x148][0xA];        // 0xA40
};
static_assert(sizeof(PreviousActionContextStack) == 0x13DC0, "PreviousActionContextStack size mismatch");
