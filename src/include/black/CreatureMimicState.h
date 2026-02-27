#pragma once
// CreatureMimicState — creature mimic behavior tracking
// Struct layout from bw1-decomp (CreatureMimic.h)
//
// Size: 0x3C bytes (inherits 0x8 from Base)

#include "Base.h"
#include "types.h"

struct GameThingWithPos;

// Forward-declare enums
enum DETECTED_PLAYER_ACTION : uint32_t;
enum MAGIC_TYPE : uint32_t;

struct CreatureMimicState : public Base {
    uint32_t               field_0x8;                   // 0x08
    uint32_t               field_0xc;                   // 0x0C
    DETECTED_PLAYER_ACTION detected_player_action;      // 0x10
    MAGIC_TYPE             magic_type;                   // 0x14
    GameThingWithPos*      game_thing;                   // 0x18
    uint32_t               field_0x1c;                   // 0x1C
    uint32_t               field_0x20;                   // 0x20
    uint32_t               field_0x24;                   // 0x24
    uint32_t               field_0x28;                   // 0x28
    uint32_t               field_0x2c;                   // 0x2C
    MapCoords              coords;                       // 0x30
};
static_assert(sizeof(CreatureMimicState) == 0x3C, "CreatureMimicState size mismatch");
