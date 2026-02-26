#pragma once
// GAbodeInfo — info for abode (habitable building) types
// Struct layout from bw1-decomp
//
// Size: 0x1C8 bytes (extends GMultiMapFixedInfo at 0x120)
// Contains building stats: villager capacity, food/wood, tribe type, etc.

#include "GMultiMapFixedInfo.h"

// Forward-declare enums
enum ABODE_TYPE : uint32_t;
enum ABODE_NUMBER : uint32_t;
enum TRIBE_TYPE : uint32_t;
enum DYK_CATEGORY : uint32_t;

struct GAbodeInfo : public GMultiMapFixedInfo {
    ABODE_TYPE   abodeType;           // 0x120
    ABODE_NUMBER abodeNumber;         // 0x124
    uint8_t      description[0x20];   // 0x128 — Name struct (0x20 bytes)
    uint32_t     field_0x148;         // 0x148
    uint32_t     field_0x14c;         // 0x14C
    uint32_t     field_0x150;         // 0x150
    uint32_t     field_0x154;         // 0x154
    TRIBE_TYPE   tribe_type;          // 0x158
    uint32_t     meshId;              // 0x15C
    uint32_t     canBePhysicallyDamaged; // 0x160
    float        startLife;           // 0x164
    uint32_t     startStrength;       // 0x168
    float        startDefence;        // 0x16C
    uint32_t     startInfluence;      // 0x170
    int32_t      maxVillagersInAbode; // 0x174
    int32_t      maxChildrenInAbode;  // 0x178
    uint32_t     startVillagersInAbode; // 0x17C
    uint32_t     startChildrenInAbode;  // 0x180
    uint32_t     startFood;           // 0x184
    uint32_t     startFoodRAnd;       // 0x188
    uint32_t     startWood;           // 0x18C
    uint32_t     startWoodRAnd;       // 0x190
    uint32_t     howLongRuinLastsFor; // 0x194
    uint32_t     potForResourceFood;  // 0x198
    uint32_t     potForResourceWood;  // 0x19C
    float        percentTooCrowded;   // 0x1A0
    int32_t      producesMobileObject; // 0x1A4
    float        maxNumMobileObjectsToProduce;          // 0x1A8
    float        timeEachMobileObjectTakesToProduce;    // 0x1AC
    float        emptyAbodeLifeReducer;                 // 0x1B0
    int32_t      populationWhenNeeded;                  // 0x1B4
    float        thresholdForStopBeingFunctional;       // 0x1B8
    int32_t      toolTipsForBuild;    // 0x1BC
    int32_t      didYouKnow;          // 0x1C0
    DYK_CATEGORY dykCategory;         // 0x1C4
};
static_assert(sizeof(GAbodeInfo) == 0x1C8, "GAbodeInfo size mismatch");
