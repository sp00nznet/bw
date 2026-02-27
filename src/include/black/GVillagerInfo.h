#pragma once
// GVillagerInfo — info for villager types
// Struct layout from bw1-decomp (VillagerInfo.h)
//
// Size: 0x3A4 bytes (extends GLivingInfo)
// Also defines DiscipleInfo (0x1C) and AgeToScale (0x50)

#include "GLivingInfo.h"

// Forward-declare enums used by villager fields
enum TRIBE_TYPE : uint32_t;
enum SEX_TYPE : uint32_t;
enum VILLAGER_NUMBER : uint32_t;
enum MESH_LIST : uint32_t;
enum JOB_INFO : uint32_t;
enum ANIM_LIST : uint32_t;
enum TOWN_DESIRE_INFO : uint32_t;

struct DiscipleInfo {
    uint32_t         field_0x0;          // 0x00
    uint32_t         field_0x4;          // 0x04
    uint32_t         field_0x8;          // 0x08
    uint32_t         field_0xc;          // 0x0C
    uint32_t         field_0x10;         // 0x10
    TOWN_DESIRE_INFO desire_i_fulfil;    // 0x14
    uint32_t         field_0x18;         // 0x18
};
static_assert(sizeof(DiscipleInfo) == 0x1C, "DiscipleInfo size mismatch");

struct AgeToScale {
    float values[0x14];  // 0x00 — 20 float entries
};
static_assert(sizeof(AgeToScale) == 0x50, "AgeToScale size mismatch");

struct GVillagerInfo : public GLivingInfo {
    TRIBE_TYPE       tribeType;                  // 0x1F4
    SEX_TYPE         sex;                        // 0x1F8
    VILLAGER_NUMBER  villagerNumber;             // 0x1FC
    MESH_LIST        superMesh;                  // 0x200
    MESH_LIST        childMeshHigh;              // 0x204
    MESH_LIST        childMeshMedium;            // 0x208
    MESH_LIST        childMeshLow;               // 0x20C
    MESH_LIST        highDetail;                 // 0x210
    MESH_LIST        stdDetail;                  // 0x214
    MESH_LIST        lowDetail;                  // 0x218
    JOB_INFO         primaryJob;                 // 0x21C
    JOB_INFO         secondaryJob;               // 0x220
    float            jobEfficency;               // 0x224
    uint32_t         startHavingSexAge;          // 0x228
    uint32_t         stopHavingSexAge;           // 0x22C
    int32_t          wantSexSpring;              // 0x230
    int32_t          wantSexSummer;              // 0x234
    int32_t          wantSexAutumn;              // 0x238
    int32_t          wantSexWinter;              // 0x23C
    uint32_t         timePregnantFor;            // 0x240
    uint32_t         lookForJobDelay;            // 0x244
    uint32_t         waitAtHome;                 // 0x248
    uint32_t         restAtHomeTime;             // 0x24C
    float            restAtHomeRestoresLifeBy;   // 0x250
    float            pregnancyChance;            // 0x254
    uint32_t         inheritence;                // 0x258
    uint32_t         boyGirlChance;              // 0x25C
    float            aveageHeightOfAdult;        // 0x260
    uint32_t         maxFoodCarried;             // 0x264
    uint32_t         maxWoodCarried;             // 0x268
    uint32_t         minWoodToShowGraphic;       // 0x26C
    uint32_t         minFoodToShowGraphic;       // 0x270
    uint32_t         maxTraderFoodCarried;       // 0x274
    uint32_t         maxTraderWoodCarried;       // 0x278
    float            woodUsedPerBuildCycle;      // 0x27C
    float            repairAmount;               // 0x280
    uint32_t         jobSpeed;                   // 0x284
    float            percentLazy;                // 0x288
    float            chantLifeRate;              // 0x28C
    uint32_t         dyingTimeWithoutGraveyard;  // 0x290
    uint32_t         dyingTimeWithGraveyard;     // 0x294
    uint32_t         timeForFootballChance;      // 0x298
    uint32_t         footballWinGoalTime;        // 0x29C
    uint32_t         footballLostGoalTime;       // 0x2A0
    float            lookAheadDistance;          // 0x2A4
    uint32_t         scaredStiffTime;            // 0x2A8
    uint32_t         waitForDinner;              // 0x2AC
    uint32_t         housewifeGossipTime;        // 0x2B0
    uint32_t         housewifeWaits;             // 0x2B4
    float            foodNurishmentMultiplier;   // 0x2B8
    float            gameTurnReducesFoodInBellyBy; // 0x2BC
    float            hungryForFood;              // 0x2C0
    float            starvingForFood;            // 0x2C4
    float            happyWithFood;              // 0x2C8
    float            fullWithFood;               // 0x2CC
    float            hungerToLifeMultiplier;     // 0x2D0
    float            starvingToLifeMultiplier;   // 0x2D4
    uint32_t         foodReqiredForDinner;       // 0x2D8
    uint32_t         processChecksEvery;         // 0x2DC
    uint32_t         havingSexTime;              // 0x2E0
    uint32_t         dancingSpeed;               // 0x2E4
    AgeToScale       ageToScale;                 // 0x2E8
    ANIM_LIST        lAttractAnim[0x3];          // 0x338
    ANIM_LIST        lNeedAnim[0x3];             // 0x344
    float            maxDistCarryFoodPit;        // 0x350
    float            maxDistCarryWoodPit;        // 0x354
    uint32_t         allowFaceSubstitution;      // 0x358
    float            damageThresholdToGoHome;    // 0x35C
    float            damageThresholdToSleepUntil; // 0x360
    uint32_t         numGameTurnsAfterAggressionInterestedInShield; // 0x364
    float            pauseForASecondChance;      // 0x368
    float            baseForTownNeedsSpeedMod;   // 0x36C
    float            divisorForTownNeedsSpeedMod; // 0x370
    float            speedModWhenFullLoadOfWood; // 0x374
    float            speedModWhenFullLoadOfFood; // 0x378
    float            lifeWhenWalksWounded;       // 0x37C
    float            lifeWhenCrawlsWounded;      // 0x380
    uint32_t         amountOfWoodPerBuilderWanted; // 0x384
    uint32_t         keepMeshWhenChangeTown;     // 0x388
    float            ownDesireThreshold;         // 0x38C
    float            maxDistanceFromArtifactDanceCanBe; // 0x390
    uint16_t         initialChillOutTime;        // 0x394
    uint16_t         subsequentChillOutTime;     // 0x396
    uint16_t         timeToWaitForArtifactDance; // 0x398
    uint16_t         drowningTime;               // 0x39A
    float            foodPowerupIncrease;        // 0x39C
    float            missionaryImpressiveValue;  // 0x3A0
};
static_assert(sizeof(GVillagerInfo) == 0x3A4, "GVillagerInfo size mismatch");
