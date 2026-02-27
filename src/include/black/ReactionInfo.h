#pragma once
// ReactionInfo — reaction behaviour configuration
// Struct layout from bw1-decomp (ReactionInfo.h)
//
// Size: 0x64 bytes (extends GBaseInfo)

#include "GBaseInfo.h"

struct ReactionInfo {
    GBaseInfo super;                                          // 0x00
    uint32_t  priority;                                       // 0x10
    uint32_t  numGameTurnsForNormalThingsToReact;             // 0x14
    uint32_t  numGameTurnsForNormalThingsBeforeReactingAgain; // 0x18
    uint32_t  numGameTurnsForCreatureToReact;                 // 0x1C
    uint32_t  numGameTurnsForCreatureBeforeReactingAgain;     // 0x20
    uint32_t  whetherItImpresses;                             // 0x24
    uint32_t  whetherReactionFinishesIfInitiatorInHand;       // 0x28
    float     maxReactionDistance;                             // 0x2C
    float     howImportantIsDistance;                           // 0x30
    uint32_t  whetherReactionGrows;                            // 0x34
    float     reactionGrowthPerGameTurn;                       // 0x38
    float     stealthRandomChance;                             // 0x3C
    float     minDistanceToRunAwayFromObject;                  // 0x40
    float     maxDistanceToRunAwayFromObject;                  // 0x44
    float     defaultReactionImpressiveMultiplier;             // 0x48
    float     additionToTownBoredomMultipliers;                // 0x4C
    uint32_t  correspondingTownDesire;                         // 0x50
    uint32_t  correspondingTownDesireForAlignment;             // 0x54
    float     alignmentModifier;                               // 0x58
    uint32_t  alignmentForSFX;                                 // 0x5C
    uint32_t  missing4bytesfromwhere;                           // 0x60
};
static_assert(sizeof(ReactionInfo) == 0x64, "ReactionInfo size mismatch");
