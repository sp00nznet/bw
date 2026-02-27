#pragma once
// CreatureContext — creature execution context
// Struct layout from bw1-decomp (CreatureContext.h)
//
// Size: 0x70 bytes (inherits 0x8 from Base)
// Also defines PreviousContextStack (0x258).

#include "Base.h"
#include "CreaturePlan.h"
#include "CreatureActionContext.h"

// Forward-declare enum
enum CREATURE_DESIRE_SOURCE : uint32_t;

struct Creature;

struct CreatureContext : public Base {
    CreaturePlan                plan;          // 0x08
    uint8_t                     field_0x38[0xC]; // 0x38-0x43
    int                         field_0x44;    // 0x44
    uint8_t                     field_0x48[0xC]; // 0x48-0x53
    uint32_t                    field_0x54;    // 0x54
    CREATURE_DESIRE_SOURCE      desire_source; // 0x58
    CreatureActionContextStart  field_0x5c;    // 0x5C-0x6F
};
static_assert(sizeof(CreatureContext) == 0x70, "CreatureContext size mismatch");

struct PreviousContextStack {
    Creature*       creature;          // 0x00
    uint8_t         field_0x4[0x1C];   // 0x04-0x1F
    uint32_t        field_0x20;        // 0x20
    uint32_t        field_0x24;        // 0x24
    CreatureContext contexts[5];       // 0x28-0x257
};
static_assert(sizeof(PreviousContextStack) == 0x258, "PreviousContextStack size mismatch");
