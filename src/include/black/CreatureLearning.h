#pragma once
// CreatureLearning — creature learning subsystem
// Struct layout from bw1-decomp (CreatureLearning.h)
//
// Size: 0x16168 bytes (inherits 0x8 from Base)
// Contains embedded PreviousContextStack, PreviousActionContextStack,
// and CreaturePreviousLesson plus extensive learning state arrays.
// NUM_CREATURE_ACTIONS = 0x148 (328)

#include "Base.h"
#include "CreatureContext.h"
#include "CreatureActionContext.h"
#include "CreaturePreviousLesson.h"

struct Creature;

struct CreatureLearning : public Base {
    PreviousContextStack       previous_context_stack;         // 0x08
    PreviousActionContextStack previous_action_context_stack;  // 0x260
    CreaturePreviousLesson     previous_lesson;                // 0x14020
    uint32_t field_0x1522c;            // 0x1522C
    uint32_t field_0x15230[6];         // 0x15230
    uint32_t field_0x15248[6];         // 0x15248
    uint32_t field_0x15260[0x2A];      // 0x15260
    uint32_t field_0x15308[0x2A];      // 0x15308
    uint32_t field_0x153b0[0x148];     // 0x153B0 — NUM_CREATURE_ACTIONS
    uint32_t field_0x158d0[0x2D];      // 0x158D0
    uint32_t field_0x15984[0x2D];      // 0x15984
    uint32_t field_0x15a38[0x2D];      // 0x15A38
    uint32_t field_0x15aec;            // 0x15AEC
    uint32_t field_0x15af0;            // 0x15AF0
    uint32_t field_0x15af4;            // 0x15AF4
    uint32_t field_0x15af8[2][0x28];   // 0x15AF8
    uint32_t field_0x15c38;            // 0x15C38
    uint32_t field_0x15c3c;            // 0x15C3C
    uint32_t field_0x15c40[0x148];     // 0x15C40 — NUM_CREATURE_ACTIONS
    Creature* field_0x16160;           // 0x16160
    uint32_t field_0x16164;            // 0x16164
};
static_assert(sizeof(CreatureLearning) == 0x16168, "CreatureLearning size mismatch");
