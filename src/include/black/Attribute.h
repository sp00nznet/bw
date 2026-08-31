#pragma once
// Attribute — how the creature turns the world into something it can reason about.
//
// A creature decides what to do by walking a decision tree, and a decision tree
// can only branch on small integers. An Attribute is the adapter: hand it a
// game object and it produces a bucket index — "is it alive", "how big is that
// town", "what is that creature carrying". Twenty-four of them exist, and the
// set of them is the creature's entire vocabulary for describing the world.
//
// Recovered from runblack_decrypted.exe (v1.0) via tools/decomp: all 24 share a
// 13-slot vtable, four slots of which are constant returns, so the names, ids,
// bucket counts and the concrete/abstract split came out mechanically
// (work/parse_attributes.py -> work/decomp/attributes.json). Every id below
// cross-checks against chlasm's ATTRIBUTE_TYPE enum from bw1-decomp (CC0).
//
// Size correction: the vendor header has Attribute at 0x8. The binary disagrees
// — it deletes these with `operator delete(this, 12)` and every Evaluate writes
// its result to `this[2]`, i.e. offset 8. So the real size is 0xC and there is a
// value field the vendor layout was missing.

#include "Base.h"

#include <cstdint>

struct Creature;
struct GameThingWithPos;

// From chlasm/CreatureEnum.h (bw1-decomp, CC0); confirmed against vtable slot 11
// of each class in the binary.
enum ATTRIBUTE_TYPE : uint32_t {
    ATTRIBUTE_TYPE_ALLEGIANCE                  = 0,
    ATTRIBUTE_TYPE_ORIGIN                      = 1,
    ATTRIBUTE_TYPE_ANIMATE                     = 2,
    ATTRIBUTE_TYPE_PLAYER_NUMBER               = 3,
    ATTRIBUTE_TYPE_HARDER_THAN_ME              = 4,
    ATTRIBUTE_TYPE_CREATURE_TYPE               = 5,
    ATTRIBUTE_TYPE_TYPE                        = 6,
    ATTRIBUTE_TYPE_LIFE                        = 7,
    ATTRIBUTE_TYPE_TRIBE                       = 8,
    ATTRIBUTE_TYPE_RELIGIOUS_BELIEF_IN_YOU     = 9,
    ATTRIBUTE_TYPE_TOWN_NEEDS_MOST             = 10,
    ATTRIBUTE_TYPE_TOWN_SIZE                   = 11,
    ATTRIBUTE_TYPE_CREATURE_DOMINANT_DESIRE    = 12,
    ATTRIBUTE_TYPE_CREATURE_HEIGHT             = 13,
    ATTRIBUTE_TYPE_CREATURE_SPELL_KNOWLEDGE    = 14,
    ATTRIBUTE_TYPE_CREATURE_CARRYING           = 15,
    ATTRIBUTE_TYPE_FOREST_SIZE                 = 16,
    ATTRIBUTE_TYPE_VILLAGER_JOB                = 17,
    ATTRIBUTE_TYPE_SEX                         = 18,
    ATTRIBUTE_TYPE_MOBILE_OBJECT_TYPE          = 19,
    ATTRIBUTE_TYPE_ABODE_TYPE                  = 20,
    ATTRIBUTE_TYPE_ABODE_BEING_BUILT           = 21,
    ATTRIBUTE_TYPE_ABODE_ON_FIRE               = 22,
    ATTRIBUTE_TYPE_ERROR                       = 23,
    _ATTRIBUTE_TYPE_COUNT                      = 23,
};

// Facts the attributes need that live in subsystems core does not model yet:
// the info blocks (species, abode and mobile-object types, villager sex/job),
// town internals (population, tribe, desires, belief), forest contents, and the
// creature's own mental state. The host supplies them; unsupplied, the
// attribute reports its zero bucket rather than inventing a value.
//
// The rest of the twenty-four need nothing beyond GameThing's own virtuals and
// are wired straight through.
struct AttributeWorld {
    uint32_t (*creature_type)(const Creature* c) = nullptr;
    uint32_t (*creature_dominant_desire)(const Creature* c) = nullptr;
    uint32_t (*creature_spell_knowledge)(const Creature* c) = nullptr;
    // What the creature is holding, as an object type. 29 means empty-handed,
    // which is the constant the binary uses rather than a sentinel.
    uint32_t (*creature_carrying)(const Creature* c) = nullptr;
    // Trees plus saplings in a forest.
    uint32_t (*forest_size)(const GameThingWithPos* forest) = nullptr;
    // Abodes plus villagers in a town.
    uint32_t (*town_population)(const GameThingWithPos* town) = nullptr;
    uint32_t (*town_tribe)(const GameThingWithPos* town) = nullptr;
    uint32_t (*town_needs_most)(const GameThingWithPos* town) = nullptr;
    // How strongly a town believes in the observing creature's god, 0..1.
    float (*town_belief_in)(const GameThingWithPos* town, const Creature* c) = nullptr;
    uint32_t (*villager_job)(const GameThingWithPos* v) = nullptr;
    uint32_t (*villager_sex)(const GameThingWithPos* v) = nullptr;
    uint32_t (*mobile_object_type)(const GameThingWithPos* o) = nullptr;
    uint32_t (*abode_type)(const GameThingWithPos* a) = nullptr;
    uint32_t (*origin)(const GameThingWithPos* o) = nullptr;
};
void SetAttributeWorld(const AttributeWorld& w);
const AttributeWorld& GetAttributeWorld();

struct Attribute : public Base {
    // The 13-slot vtable, in the binary's order. Slots 0-6 are the Base
    // interface; the six below are what makes an attribute an attribute.
    virtual const char*    GetName() const;                    // slot 7
    virtual uint32_t       GetNumValues() const;               // slot 8
    virtual const char*    GetValueName(uint32_t index) const;  // slot 9
    virtual uint32_t       Evaluate(GameThingWithPos* obj,
                                    Creature* observer);        // slot 10
    virtual ATTRIBUTE_TYPE GetAttributeType() const;           // slot 11
    // Slot 12 separates the eleven abstract entries from the thirteen the
    // decision trees actually branch on.
    virtual bool           IsConcrete() const;                 // slot 12

    uint32_t value = 0;  // 0x08 — the bucket the last Evaluate produced

protected:
    // Every Evaluate ends the same way: store the feature, then clamp it down
    // to the last bucket. The original clamps only the top end (the value is
    // unsigned), so an out-of-range feature saturates rather than wrapping.
    uint32_t Store(uint32_t v);
};
static_assert(sizeof(Attribute) == 0xC, "Attribute size mismatch");

// --- concrete attributes (slot 12 returns true) ---------------------------

#define BW_ATTRIBUTE(Name)                                                 \
    struct Name : public Attribute {                                       \
        const char*    GetName() const override;                           \
        uint32_t       GetNumValues() const override;                      \
        uint32_t       Evaluate(GameThingWithPos* obj, Creature* o) override; \
        ATTRIBUTE_TYPE GetAttributeType() const override;                  \
        bool           IsConcrete() const override;                        \
    };                                                                     \
    static_assert(sizeof(Name) == 0xC, #Name " size mismatch")

BW_ATTRIBUTE(AttributeAllegiance);                 // 3 buckets
BW_ATTRIBUTE(AttributeIsHarderThanMe);             // 2
BW_ATTRIBUTE(AttributeCreatureType);               // 17
BW_ATTRIBUTE(AttributeLife);                       // 2
BW_ATTRIBUTE(AttributeTownReligiousBeliefInYou);   // 4
BW_ATTRIBUTE(AttributeWhatTownNeedsMost);          // 17
BW_ATTRIBUTE(AttributeCreatureDominantDesire);     // 41
BW_ATTRIBUTE(AttributeCreatureHeight);             // 4
BW_ATTRIBUTE(AttributeCreatureSpellKnowledge);     // 43
BW_ATTRIBUTE(AttributeCreatureWhatHeIsCarrying);   // 45
BW_ATTRIBUTE(AttributeForestSize);                 // 3
BW_ATTRIBUTE(AttributeAbodeBeingBuilt);            // 2
BW_ATTRIBUTE(AttributeOnFire);                     // 2

// --- attributes the trees do not branch on (slot 12 returns false) --------
// They still evaluate, and the debug UI still lists them; the binary just does
// not offer them as decision-tree inputs.

BW_ATTRIBUTE(AttributeOrigin);                     // 3
BW_ATTRIBUTE(AttributeAnimate);                    // 2
BW_ATTRIBUTE(AttributePlayerNumber);               // 8
BW_ATTRIBUTE(AttributeType);                       // 24
BW_ATTRIBUTE(AttributeTribe);                      // 9
BW_ATTRIBUTE(AttributeTownSize);                   // 3
BW_ATTRIBUTE(AttributeVillagerJob);                // 17
BW_ATTRIBUTE(AttributeSex);                        // 2
BW_ATTRIBUTE(AttributeMobileObjectType);           // 32
BW_ATTRIBUTE(AttributeAbodeType);                  // 24

#undef BW_ATTRIBUTE

// The full set, indexed by ATTRIBUTE_TYPE. Returns nullptr for
// ATTRIBUTE_TYPE_ERROR, which is the abstract base's own id.
Attribute* GetAttribute(ATTRIBUTE_TYPE type);
