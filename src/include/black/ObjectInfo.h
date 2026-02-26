#pragma once
// GObjectInfo — type metadata shared by all instances of a given Object type
// Struct layout from bw1-decomp's ObjectInfo.h
//
// Size: 0x100 bytes (256 bytes)
// Each Object holds a const GObjectInfo* at offset 0x28.
// GObjectInfo inherits from GBaseInfo (0x10 bytes, linked-list node with vtable).
//
// Contains defence values, creature interaction flags, food/wood values,
// impressive values, help text enums, etc.

#include "types.h"

// Forward-declare enums used as fields (all uint32_t underlying type).
// Full definitions live in Object.h / GameThingWithPos.h.
enum ALIGNMENT_TYPE : uint32_t;
enum FOOD_TYPE : uint32_t;
enum HELP_TEXT : uint32_t;
enum IMMERSION_EFFECT_TYPE : uint32_t;
enum OBJECT_TYPE : uint32_t;
enum SOUND_COLLISION_TYPE : uint32_t;

// Object type enum (partial — values from bw1-decomp's chlasm/Enum.h)
enum OBJECT_TYPE : uint32_t {
    OBJECT_TYPE_INVALID = 0,
};

// Alignment type enum (partial)
enum ALIGNMENT_TYPE : uint32_t {
    ALIGNMENT_TYPE_NONE = 0,
};

struct GObjectInfo {
    // === GBaseInfo base class (0x00 - 0x0F) ===
    void*         vftable;          // 0x00 — GObjectInfoVftable*
    uint32_t      field_0x04;       // 0x04 — Base padding
    GObjectInfo*  next;             // 0x08 — linked list next (GBaseInfo)
    int32_t       index;            // 0x0C — info table index (GBaseInfo)

    // === GObjectInfo fields (0x10 - 0xFF) ===
    OBJECT_TYPE    type;                   // 0x10
    ALIGNMENT_TYPE alignmentType;          // 0x14
    char           debugString[0x30];      // 0x18 — human-readable type name
    SOUND_COLLISION_TYPE collideSound;     // 0x48
    IMMERSION_EFFECT_TYPE immersion;       // 0x4C
    HELP_TEXT      helpStartEnum;          // 0x50
    HELP_TEXT      helpEndEnum;            // 0x54
    uint32_t       helpMessage;            // 0x58
    uint32_t       helpCondition;          // 0x5C
    uint32_t       helpInHand;             // 0x60
    uint32_t       handCondition;          // 0x64
    float          foodValue;              // 0x68
    uint32_t       woodValue;              // 0x6C
    uint32_t       food_type;              // 0x70 — FOOD_TYPE bitmask

    // Defence effect base values
    float defenceEffectBurn;               // 0x74
    float defenceEffectCrush;              // 0x78
    float defenceEffectHit;                // 0x7C
    float defenceEffectHeal;               // 0x80
    float defenceEffectFlyAway;            // 0x84
    float defenceEffectAlignmentModification;  // 0x88
    float defenceEffectBeliefModification;     // 0x8C

    // Defence multipliers
    float defenceMultiplierBurn;           // 0x90
    float defenceMultiplierCrush;          // 0x94
    float defenceMultiplierHit;            // 0x98
    float defenceMultiplierHeal;           // 0x9C
    float defenceMultiplierFlyAway;        // 0xA0
    float defenceMultiplierAlignmentModification;  // 0xA4
    float defenceMultiplierBeliefModification;     // 0xA8

    // Physical properties
    float    weight;                       // 0xAC
    float    heat_capacity;                // 0xB0
    float    combustionTemperature;        // 0xB4
    float    burningPriority;              // 0xB8

    // Creature interaction flags
    uint32_t canCreatureUseForBuilding;    // 0xBC
    uint32_t canCreatureInteractWithMe;    // 0xC0
    uint32_t canCreatureAttackMe;          // 0xC4
    uint32_t canCreaturePlayWithMe;        // 0xC8
    uint32_t canCreatureInspectMe;         // 0xCC
    uint32_t canCreatureGiveMeToLiving;    // 0xD0
    uint32_t canCreatureBringMeBackToTheCitadel; // 0xD4

    // Villager interaction
    uint16_t villagerInteractState;            // 0xD8
    uint16_t villagerInteractStateForBuilding; // 0xDA
    float    field_0xdc;                       // 0xDC
    float    villagerInteractDesire;           // 0xE0

    // Value properties
    float    sacrificeValue;               // 0xE4
    float    impressiveValue;              // 0xE8
    float    aggressorValue;               // 0xEC
    float    villagerImpressiveValue;      // 0xF0
    float    artifactMultiplier;           // 0xF4
    float    drawImportance;               // 0xF8
    float    computer_attack_desire;       // 0xFC
};
static_assert(sizeof(GObjectInfo) == 0x100, "GObjectInfo size mismatch");
