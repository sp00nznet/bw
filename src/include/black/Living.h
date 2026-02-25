#pragma once
// Living — animate entity that can move, react, and die
// Struct layout from bw1-decomp
//
// Size: 0xE0 bytes (inherits 0x8C from MobileWallHug)
// Vtable: 0xB40 bytes (extends MobileWallHug's 0x874 with 200+ methods)
//
// Living is the base for Villager, Animal, and Creature — entities that
// are "alive" in the game world with AI reactions, pathfinding, and animation.

#include "MobileWallHug.h"

// Forward declarations
struct DanceGroup;
struct DataForScriptRemind;
struct DataPath;
struct Flock;
struct GFootpathNode;
struct ReactionDoneWhen;

// Living action state (mini state machine)
struct LivingAction {
    uint8_t current_state;  // 0x0
    uint8_t prev_state;     // 0x1
    uint8_t dest_state;     // 0x2
    uint8_t field_0x3;      // 0x3
    uint8_t field_0x4;      // 0x4
    uint8_t field_0x5;      // 0x5
};
static_assert(sizeof(LivingAction) == 0x6, "LivingAction size mismatch");

struct Living : public MobileWallHug {
    // === New virtual methods (vtable 0x874-0xB3C) ===
    // ~180 new methods for AI, reactions, animation, etc.
    // Key method categories:
    //   - Movement: AmILikelyToMove, GetFinalDestPos, MoveByTeleport
    //   - State:    SetCurrentAndDestinationState, SetTopState
    //   - Reactions: StartReacting, StopReacting, SetupReactTo*
    //   - Animation: SetAnim, GetAnimId, CallEntryStateFunction
    //   - AI:       DecideWhatToDo
    //   - Props:    GetAge, SetAge, IsDead, IsChild
    //
    // Full vtable declarations deferred to avoid 200+ forward declarations
    // until needed for derived class overrides.

    // === Fields ===
    LivingAction action;                      // 0x8C — state machine
    uint16_t pad_0x92;                        // 0x92 — padding
    Reaction* reaction;                       // 0x94 — current reaction
    ReactionDoneWhen* reaction_done_when;     // 0x98
    int field_0x9c;                           // 0x9C
    int32_t birth_turn;                       // 0xA0 — game turn born
    Living* next;                             // 0xA4 — linked list
    uint32_t field_0xa8;                      // 0xA8
    DataPath* data_path;                      // 0xAC — pathfinding data
    DataForScriptRemind* data_for_script_remind; // 0xB0
    uint16_t status;                          // 0xB4 — status flags
    uint16_t pad_0xb6;                        // 0xB6 — padding
    Flock* flock;                             // 0xB8
    GameThingWithPos* field_0xbc;             // 0xBC
    uint32_t field_0xc0;                      // 0xC0
    uint32_t field_0xc4;                      // 0xC4
    GFootpath* living_footpath;               // 0xC8 — current footpath
    GFootpathNode* footpath_node;             // 0xCC — current node on path
    LH3DColor specular_color;                 // 0xD0
    uint32_t field_0xd4;                      // 0xD4
    DanceGroup* dance_group;                  // 0xD8
    uint8_t field_0xdc;                       // 0xDC
    uint8_t pad_0xdd[3];                      // 0xDD-0xDF — padding to 0xE0
};
static_assert(sizeof(Living) == 0xE0, "Living size mismatch");
