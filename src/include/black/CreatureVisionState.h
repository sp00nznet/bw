#pragma once
// CreatureVisionState — creature vision/perception state
// Struct layout from bw1-decomp (CreatureVisionState.h)
//
// Size: 0x48 bytes (inherits 0x8 from Base)
// Contains an embedded CreatureInterestingThingToLookAt (0x20).

#include "Base.h"
#include "types.h"

struct CreatureInterestingThingToLookAt {
    uint32_t  field_0x0;   // 0x00
    uint32_t  field_0x4;   // 0x04
    uint32_t  field_0x8;   // 0x08
    MapCoords coords;      // 0x0C
    uint32_t  field_0x18;  // 0x18
    uint32_t  field_0x1c;  // 0x1C
};
static_assert(sizeof(CreatureInterestingThingToLookAt) == 0x20, "CreatureInterestingThingToLookAt size mismatch");

struct CreatureVisionState : public Base {
    CreatureInterestingThingToLookAt thing_to_look_at;  // 0x08
    uint32_t field_0x28;  // 0x28
    uint32_t field_0x2c;  // 0x2C
    uint32_t field_0x30;  // 0x30
    uint32_t field_0x34;  // 0x34
    uint32_t field_0x38;  // 0x38
    uint32_t field_0x3c;  // 0x3C
    uint32_t field_0x40;  // 0x40
    uint32_t field_0x44;  // 0x44
};
static_assert(sizeof(CreatureVisionState) == 0x48, "CreatureVisionState size mismatch");
