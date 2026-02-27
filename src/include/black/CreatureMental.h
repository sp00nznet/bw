#pragma once
// CreatureMental — the creature's entire mental model (AI brain)
// Struct layout from bw1-decomp (CreatureMental.h)
//
// Size: 0x20D40 bytes (inherits 0x8 from Base) — ~135 KB per creature!
// Aggregates all AI subsystems: desires, agenda, beliefs, decision trees,
// learning, attitude, vision, exploration, and debug state.

#include "Base.h"
#include "CreatureDesires.h"
#include "CreatureAgenda.h"
#include "CreatureBeliefs.h"
#include "DecisionTree.h"
#include "CreatureActionOpinions.h"
#include "CreatureLearning.h"
#include "CreatureAttitudeToPlayer.h"
#include "CreatureActionsKnownAbout.h"
#include "CreatureInnatePersonality.h"
#include "CreatureVisionState.h"
#include "CreatureExplorationMap.h"
#include "CreaturePreviousActions.h"
#include "CreatureLookState.h"
#include "CreatureFaceState.h"
#include "CreatureObjectsInspected.h"
#include "CreatureMentalDebug.h"
#include "types.h"

struct Creature;
struct GameThingWithPos;

struct CreatureMental : public Base {
    // === Non-virtual methods ===
    void* AddBeliefAboutObject(Creature* creature,
                               GameThingWithPos* object);  // 0x004d7bd0

    // === Fields ===
    CreatureDesires             desires;                     // 0x08
    CreatureAgenda              agenda;                      // 0x710
    CreatureBeliefs             beliefs;                     // 0x2208
    DecisionTreeCollection      decision_tree_collection;    // 0x2478
    CreatureActionOpinions      action_opinions;             // 0x25B8
    CreatureLearning            learning;                    // 0x2AD8
    CreatureAttitudeToPlayer    attitude_to_player;          // 0x18C40
    uint32_t                    field_0x1a9f4;               // 0x1A9F4
    uint32_t                    field_0x1a9f8;               // 0x1A9F8
    CreatureActionsKnownAbout   actions_known_about;         // 0x1A9FC
    CreatureInnatePersonality   innate_personality;          // 0x1AA14
    CreatureVisionState         vision_state;                // 0x1AA38
    CreatureExplorationMap      exploration_map;             // 0x1AA80
    uint8_t                     field_0x1ca98[0x400];        // 0x1CA98
    CreaturePreviousActions     previous_actions;            // 0x1CE98
    CreatureLookState           look_state;                  // 0x1D3C0
    uint8_t                     field_0x1d3f8[0x14];         // 0x1D3F8
    CreatureFaceState           face_state;                  // 0x1D40C
    CreatureObjectsInspected    objects_inspected;           // 0x1D418
    uint32_t                    field_0x1d480;               // 0x1D480
    uint32_t                    field_0x1d484;               // 0x1D484
    uint32_t                    field_0x1d488;               // 0x1D488
    MapCoords                   field_0x1d48c[0x1E][0x28];   // 0x1D48C
    CreatureMentalDebug         debug;                       // 0x20CCC
    Creature*                   creature;                    // 0x20D18
    int                         field_0x20d1c;               // 0x20D1C
    uint32_t                    field_0x20d20;               // 0x20D20
    uint32_t                    field_0x20d24;               // 0x20D24
    uint32_t                    field_0x20d28;               // 0x20D28
    uint32_t                    field_0x20d2c;               // 0x20D2C
    uint32_t                    field_0x20d30;               // 0x20D30
    uint32_t                    field_0x20d34;               // 0x20D34
    uint32_t                    field_0x20d38;               // 0x20D38
    uint32_t                    field_0x20d3c;               // 0x20D3C
};
static_assert(sizeof(CreatureMental) == 0x20D40, "CreatureMental size mismatch");
