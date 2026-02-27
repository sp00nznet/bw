#pragma once
// Attribute — base class for decision tree attribute evaluators
// Struct layout from bw1-decomp (CreatureMentalAttributeTest.h)
//
// Size: 0x8 bytes (Base only)
// 23 subclasses exist, all identical 0x8-byte layout.

#include "Base.h"

struct Attribute : public Base {
};
static_assert(sizeof(Attribute) == 0x8, "Attribute size mismatch");

// === Attribute subclasses (all 0x8 bytes, no additional fields) ===

struct AttributeAbodeBeingBuilt : public Attribute {};
static_assert(sizeof(AttributeAbodeBeingBuilt) == 0x8, "AttributeAbodeBeingBuilt size mismatch");

struct AttributeAbodeType : public Attribute {};
static_assert(sizeof(AttributeAbodeType) == 0x8, "AttributeAbodeType size mismatch");

struct AttributeAllegiance : public Attribute {};
static_assert(sizeof(AttributeAllegiance) == 0x8, "AttributeAllegiance size mismatch");

struct AttributeAnimate : public Attribute {};
static_assert(sizeof(AttributeAnimate) == 0x8, "AttributeAnimate size mismatch");

struct AttributeCreatureDominantDesire : public Attribute {};
static_assert(sizeof(AttributeCreatureDominantDesire) == 0x8, "AttributeCreatureDominantDesire size mismatch");

struct AttributeCreatureHeight : public Attribute {};
static_assert(sizeof(AttributeCreatureHeight) == 0x8, "AttributeCreatureHeight size mismatch");

struct AttributeCreatureSpellKnowledge : public Attribute {};
static_assert(sizeof(AttributeCreatureSpellKnowledge) == 0x8, "AttributeCreatureSpellKnowledge size mismatch");

struct AttributeCreatureType : public Attribute {};
static_assert(sizeof(AttributeCreatureType) == 0x8, "AttributeCreatureType size mismatch");

struct AttributeCreatureWhatHeIsCarrying : public Attribute {};
static_assert(sizeof(AttributeCreatureWhatHeIsCarrying) == 0x8, "AttributeCreatureWhatHeIsCarrying size mismatch");

struct AttributeForestSize : public Attribute {};
static_assert(sizeof(AttributeForestSize) == 0x8, "AttributeForestSize size mismatch");

struct AttributeIsHarderThanMe : public Attribute {};
static_assert(sizeof(AttributeIsHarderThanMe) == 0x8, "AttributeIsHarderThanMe size mismatch");

struct AttributeLife : public Attribute {};
static_assert(sizeof(AttributeLife) == 0x8, "AttributeLife size mismatch");

struct AttributeMobileObjectType : public Attribute {};
static_assert(sizeof(AttributeMobileObjectType) == 0x8, "AttributeMobileObjectType size mismatch");

struct AttributeOnFire : public Attribute {};
static_assert(sizeof(AttributeOnFire) == 0x8, "AttributeOnFire size mismatch");

struct AttributeOrigin : public Attribute {};
static_assert(sizeof(AttributeOrigin) == 0x8, "AttributeOrigin size mismatch");

struct AttributePlayerNumber : public Attribute {};
static_assert(sizeof(AttributePlayerNumber) == 0x8, "AttributePlayerNumber size mismatch");

struct AttributeSex : public Attribute {};
static_assert(sizeof(AttributeSex) == 0x8, "AttributeSex size mismatch");

struct AttributeTownReligiousBeliefInYou : public Attribute {};
static_assert(sizeof(AttributeTownReligiousBeliefInYou) == 0x8, "AttributeTownReligiousBeliefInYou size mismatch");

struct AttributeTownSize : public Attribute {};
static_assert(sizeof(AttributeTownSize) == 0x8, "AttributeTownSize size mismatch");

struct AttributeTribe : public Attribute {};
static_assert(sizeof(AttributeTribe) == 0x8, "AttributeTribe size mismatch");

struct AttributeType : public Attribute {};
static_assert(sizeof(AttributeType) == 0x8, "AttributeType size mismatch");

struct AttributeVillagerJob : public Attribute {};
static_assert(sizeof(AttributeVillagerJob) == 0x8, "AttributeVillagerJob size mismatch");

struct AttributeWhatTownNeedsMost : public Attribute {};
static_assert(sizeof(AttributeWhatTownNeedsMost) == 0x8, "AttributeWhatTownNeedsMost size mismatch");
