#pragma once
// EffectValues — tracks applied spell/effect data
// Struct layout from bw1-decomp
//
// Size: 0x40 bytes (inherits 0x8 from Base)
// Used in PlayerTownInteract and various effect application systems.

#include "Base.h"
#include "types.h"

// Forward declarations
struct GameThing;
struct GPlayer;

// Forward-declare enum
enum EFFECT_TYPE : uint32_t;

// Effect values sub-struct — one float per effect type (EFFECT_TYPE_LAST = 7)
struct EffectNumbers {
    float values[7];  // 0x0
};
static_assert(sizeof(EffectNumbers) == 0x1C, "EffectNumbers size mismatch");

struct EffectValues : public Base {
    // === Fields ===
    EffectNumbers numbers;       // 0x08
    float         field_0x24;    // 0x24
    GameThing*    applied_by;    // 0x28
    MapCoords     coords;        // 0x2C
    uint32_t      field_0x38;    // 0x38
    GPlayer*      player;        // 0x3C
};
static_assert(sizeof(EffectValues) == 0x40, "EffectValues size mismatch");
