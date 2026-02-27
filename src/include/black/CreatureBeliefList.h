#pragma once
// CreatureBeliefList — list of creature beliefs about game objects
// Struct layout from bw1-decomp (CreatureMentalBeliefs.h)
//
// Size: 0x14 bytes (inherits 0x8 from Base)
// Manages a collection of CreatureBelief instances for a creature.

#include "Base.h"

struct Creature;
struct GameThingWithPos;

struct CreatureBeliefList : public Base {
    // === Non-virtual methods ===
    void* GetBeliefAboutObject(GameThingWithPos* object);          // 0x004dc810
    void* AddBeliefAboutObject(Creature* creature,
                               GameThingWithPos* object);          // 0x004dc860

    // === Fields ===
    uint32_t field_0x8;   // 0x08
    uint32_t field_0xc;   // 0x0C
    uint32_t field_0x10;  // 0x10
};
static_assert(sizeof(CreatureBeliefList) == 0x14, "CreatureBeliefList size mismatch");
