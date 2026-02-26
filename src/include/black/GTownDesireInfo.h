#pragma once
// GTownDesireInfo — info for town desires/needs
// Struct layout from bw1-decomp
//
// Size: 0x90 bytes (extends GBaseInfo at 0x10)
// Contains desire configuration, prayer site associations,
// tribe multipliers, and help text references.

#include "GBaseInfo.h"

// Forward declarations
struct GPrayerIconInfo;

// Forward-declare enums
enum VILLAGER_BASIC_INFO : uint32_t;
enum MESH_LIST : uint32_t;
enum HELP_TEXT : uint32_t;

struct GTownDesireInfo : public GBaseInfo {
    GPrayerIconInfo*    associatedPrayerSite;                   // 0x10
    float               showsAfterPercent;                      // 0x14
    float               desireTriggersVillagerAction;           // 0x18
    float               desireTriggersVillagerEmergencyAction;  // 0x1C
    VILLAGER_BASIC_INFO associatedVillagerBirth[3];             // 0x20
    MESH_LIST           worshipSiteMesh;                        // 0x2C
    int32_t             worshipSiteSlot;                        // 0x30
    float               worshipSiteScale;                       // 0x34
    float               desireToBeliefScale;                    // 0x38
    float               desireAffectsBeliefAfter;               // 0x3C
    float               desireBuildWonderReducer;               // 0x40
    float               desireValueGreaterCausesDecayInBelief;  // 0x44
    float               desireToBeliefThresholdDecay;           // 0x48
    float               desireAffectsAlignmentAfter;            // 0x4C
    float               howImportantDesireIsToAlignment;        // 0x50
    uint32_t            maxTimeForAlignmentChange;              // 0x54
    float               tribeMultiplier[9];                     // 0x58
    HELP_TEXT           helpStartEnum;                          // 0x7C
    HELP_TEXT           helpEndEnum;                             // 0x80
    HELP_TEXT           helpStatEnum;                            // 0x84
    uint32_t            helpMessage;                             // 0x88
    uint32_t            helpCondition;                           // 0x8C
};
static_assert(sizeof(GTownDesireInfo) == 0x90, "GTownDesireInfo size mismatch");
