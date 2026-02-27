#pragma once
// CreatureBeliefs — aggregate container for all creature beliefs
// Struct layout from bw1-decomp (CreatureMentalBeliefs.h)
//
// Size: 0x270 bytes (inherits 0x8 from Base)
// Contains two CreatureBeliefList instances and one AllocatedBeliefList,
// plus additional data for the creature's mental model of the world.

#include "Base.h"
#include "CreatureBeliefList.h"
#include "AllocatedBeliefList.h"

struct CreatureBeliefs : public Base {
    // === Non-virtual methods ===
    void Initialise();  // 0x004dced0

    // === Fields ===
    CreatureBeliefList    lists[2];         // 0x08 — two belief lists (0x28 bytes total)
    AllocatedBeliefList   allocated_list;   // 0x30
    uint8_t               field_0x48[0x228]; // 0x48-0x26F
};
static_assert(sizeof(CreatureBeliefs) == 0x270, "CreatureBeliefs size mismatch");
