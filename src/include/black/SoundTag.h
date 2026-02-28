#pragma once
// SoundTag — spatial sound attached to a game object
// Struct layout from bw1-decomp
//
// Size: 0x54 bytes
// Inheritance: Base (0x8) → LocalBase (0x8) → SoundTag (0x54)
// Overrides: ToBeDeleted, Get3DSoundPos

#include "LocalBase.h"
#include "types.h"

struct GameThingWithPos;

struct SoundTag : LocalBase {
    // === Virtual overrides (Base) ===
    void ToBeDeleted(int param) override;
    int  Get3DSoundPos(LHPoint* pos) override;

    // === Fields ===
    SoundTag*         next;        // 0x08
    GameThingWithPos* game_thing;  // 0x0C
    LHPoint           field_0x10;  // 0x10
    LHPoint           field_0x1c;  // 0x1C
    uint32_t          field_0x28;  // 0x28
    uint32_t          field_0x2c;  // 0x2C
    uint32_t          field_0x30;  // 0x30 (bool in vendor, but 4-byte aligned)
    int               field_0x34;  // 0x34
    uint32_t          field_0x38;  // 0x38
    uint32_t          field_0x3c;  // 0x3C
    int               field_0x40;  // 0x40
    int               field_0x44;  // 0x44
    int               field_0x48;  // 0x48
    uint32_t          field_0x4c;  // 0x4C
    uint16_t          field_0x50;  // 0x50
};
static_assert(sizeof(SoundTag) == 0x54, "SoundTag size mismatch");
