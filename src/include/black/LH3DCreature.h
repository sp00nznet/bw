#pragma once
// LH3DCreature — 3D creature rendering model (extends Morphable)
// Struct layout from bw1-decomp
// Size: 0x57B8 bytes
//
// Contains the Morphable base (0x4834 bytes) plus creature-specific
// rendering state: speed modifiers, animation states, body part data.

#include "Morphable.h"

struct Creature;
struct RPFollow;

struct LH3DCreature {
    Morphable super;                           // 0x0000
    Creature* creature;                        // 0x4834
    float     field_0x4838;                    // 0x4838
    float     required_speed;                  // 0x483C
    float     field_0x4840;                    // 0x4840
    uint32_t  field_0x4844;                    // 0x4844
    float     speed_modifier_0x4848;           // 0x4848
    uint8_t   field_0x484c[0x10];              // 0x484C
    uint32_t  field_0x485c;                    // 0x485C
    uint32_t  field_0x4860;                    // 0x4860
    uint32_t  field_0x4864;                    // 0x4864
    uint32_t  field_0x4868;                    // 0x4868
    uint32_t  field_0x486c;                    // 0x486C
    // Remaining creature morph/rendering state
    uint8_t   field_0x4870[0x57B8 - 0x4870];  // 0x4870
};
static_assert(sizeof(LH3DCreature) == 0x57B8, "LH3DCreature size mismatch");
