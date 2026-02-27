#pragma once
// CreatureAttitudeToPlayer — creature's relationship with players
// Struct layout from bw1-decomp (CreatureAttitudeToPlayer.h)
//
// Size: 0x1DB4 bytes (inherits 0x8 from Base)
// Contains embedded CreaturePerceivedPlayerDesires (0x177C).

#include "Base.h"

struct GameThingWithPos;

// Forward-declare enums
enum DETECTED_PLAYER_ACTION : uint32_t;
enum MAGIC_TYPE : uint32_t;

struct CreaturePerceivedPlayerDesires_field_0x15c {
    uint8_t field_0x0[0x20];
};
static_assert(sizeof(CreaturePerceivedPlayerDesires_field_0x15c) == 0x20, "size mismatch");

struct CreaturePerceivedPlayerDesires {
    uint32_t field_0x0[0x28];                                            // 0x000
    uint32_t field_0xa0[0x11];                                           // 0x0A0
    uint8_t  field_0xe4[0x78];                                           // 0x0E4
    CreaturePerceivedPlayerDesires_field_0x15c field_0x15c[0x28];         // 0x15C
    uint8_t  field_0x65c[0xF00];                                         // 0x65C
    CreaturePerceivedPlayerDesires_field_0x15c field_0x155c[0x11];        // 0x155C
};
static_assert(sizeof(CreaturePerceivedPlayerDesires) == 0x177C, "CreaturePerceivedPlayerDesires size mismatch");

struct CreatureAttitudeToPlayer_field_0x1da4 {
    DETECTED_PLAYER_ACTION detected_action;  // 0x00
    GameThingWithPos*      game_thing;       // 0x04
    uint32_t               field_0x8;        // 0x08
    MAGIC_TYPE             magic_type;       // 0x0C
};
static_assert(sizeof(CreatureAttitudeToPlayer_field_0x1da4) == 0x10, "size mismatch");

struct CreatureAttitudeToPlayer : public Base {
    uint32_t field_0x8;       // 0x08
    uint32_t field_0xc;       // 0x0C
    uint32_t field_0x10;      // 0x10
    uint32_t field_0x14;      // 0x14
    uint32_t field_0x18;      // 0x18
    uint32_t field_0x1c;      // 0x1C
    uint32_t field_0x20;      // 0x20
    uint32_t field_0x24;      // 0x24
    float    field_0x28;      // 0x28
    uint32_t field_0x2c;      // 0x2C
    uint32_t field_0x30;      // 0x30
    uint32_t field_0x34;      // 0x34
    uint32_t field_0x38;      // 0x38
    uint32_t field_0x3c;      // 0x3C
    CreaturePerceivedPlayerDesires field_0x40;      // 0x40
    uint8_t  field_0x17bc[0x5E8];                  // 0x17BC
    CreatureAttitudeToPlayer_field_0x1da4 field_0x1da4;  // 0x1DA4
};
static_assert(sizeof(CreatureAttitudeToPlayer) == 0x1DB4, "CreatureAttitudeToPlayer size mismatch");
