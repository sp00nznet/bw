// CreatureBeliefAttributes — the creature's per-belief feature vectors.
//
// Translated from runblack_decrypted.exe (v1.0), original source
// C:\dev\black\CreatureMentalBeliefs.cpp. The builders are non-virtual, so they
// were located by following data references from the 24 Attribute vtables back
// to the code that constructs them:
//
//     sub_4BBC20   the common seven, installed at indices 0..6
//     sub_4BC1D0   abode      -> AbodeType, Life, OnFire, AbodeBeingBuilt
//     sub_4BC030   creature   -> DominantDesire, Height, SpellKnowledge, Carrying
//     sub_4BC0E0   forest     -> ForestSize
//     sub_4BBF80   town       -> ReligiousBeliefInYou, NeedsMost, TownSize, Tribe
//     sub_4BC120   villager   -> Sex, VillagerJob, Life, OnFire
//
// Each appears twice in the binary (a constructor and a rebuild path, e.g.
// sub_4BC1D0 / sub_4BCB00); both install the same attributes in the same order,
// which is how the ordering below was confirmed rather than assumed.
//
// Citadel, context and flock beliefs add nothing to the common seven.

#include "black/CreatureBeliefAttributes.h"

namespace {

// sub_4BBC20, indices 0..6, in the order it installs them.
const ATTRIBUTE_TYPE kCommon[] = {
    ATTRIBUTE_TYPE_ALLEGIANCE,       // 0
    ATTRIBUTE_TYPE_ORIGIN,           // 1
    ATTRIBUTE_TYPE_ANIMATE,          // 2
    ATTRIBUTE_TYPE_PLAYER_NUMBER,    // 3
    ATTRIBUTE_TYPE_HARDER_THAN_ME,   // 4
    ATTRIBUTE_TYPE_CREATURE_TYPE,    // 5
    ATTRIBUTE_TYPE_TYPE,             // 6
};
enum : uint32_t { kCommonCount = sizeof(kCommon) / sizeof(kCommon[0]) };

// Each kind's own attributes, installed at indices 7 upward.
const ATTRIBUTE_TYPE kAbode[] = {
    ATTRIBUTE_TYPE_ABODE_TYPE,
    ATTRIBUTE_TYPE_LIFE,
    ATTRIBUTE_TYPE_ABODE_ON_FIRE,
    ATTRIBUTE_TYPE_ABODE_BEING_BUILT,
};
const ATTRIBUTE_TYPE kCreature[] = {
    ATTRIBUTE_TYPE_CREATURE_DOMINANT_DESIRE,
    ATTRIBUTE_TYPE_CREATURE_HEIGHT,
    ATTRIBUTE_TYPE_CREATURE_SPELL_KNOWLEDGE,
    ATTRIBUTE_TYPE_CREATURE_CARRYING,
};
const ATTRIBUTE_TYPE kForest[] = {
    ATTRIBUTE_TYPE_FOREST_SIZE,
};
const ATTRIBUTE_TYPE kTown[] = {
    ATTRIBUTE_TYPE_RELIGIOUS_BELIEF_IN_YOU,
    ATTRIBUTE_TYPE_TOWN_NEEDS_MOST,
    ATTRIBUTE_TYPE_TOWN_SIZE,
    ATTRIBUTE_TYPE_TRIBE,
};
const ATTRIBUTE_TYPE kVillager[] = {
    ATTRIBUTE_TYPE_SEX,
    ATTRIBUTE_TYPE_VILLAGER_JOB,
    ATTRIBUTE_TYPE_LIFE,
    ATTRIBUTE_TYPE_ABODE_ON_FIRE,
};

struct KindEntry {
    const char*           name;
    const ATTRIBUTE_TYPE* own;
    uint32_t              own_count;
};

#define BW_KIND(arr) (arr), (sizeof(arr) / sizeof((arr)[0]))

const KindEntry kKinds[_CREATURE_BELIEF_KIND_COUNT] = {
    { "Base",     nullptr,        0 },
    { "Abode",    BW_KIND(kAbode) },
    { "Citadel",  nullptr,        0 },
    { "Context",  nullptr,        0 },
    { "Creature", BW_KIND(kCreature) },
    { "Flock",    nullptr,        0 },
    { "Forest",   BW_KIND(kForest) },
    { "Town",     BW_KIND(kTown) },
    { "Villager", BW_KIND(kVillager) },
};

#undef BW_KIND

// The full vector per kind, built once: the common seven then the kind's own.
struct Vectors {
    ATTRIBUTE_TYPE list[_CREATURE_BELIEF_KIND_COUNT][kMaxBeliefAttributes];
    uint32_t       count[_CREATURE_BELIEF_KIND_COUNT];

    Vectors() {
        for (uint32_t k = 0; k < _CREATURE_BELIEF_KIND_COUNT; ++k) {
            uint32_t n = 0;
            for (uint32_t i = 0; i < kCommonCount; ++i) list[k][n++] = kCommon[i];
            const KindEntry& e = kKinds[k];
            for (uint32_t i = 0; i < e.own_count && n < kMaxBeliefAttributes; ++i)
                list[k][n++] = e.own[i];
            count[k] = n;
        }
    }
};

const Vectors& Table() {
    static const Vectors v;
    return v;
}

}  // namespace

const ATTRIBUTE_TYPE* GetBeliefAttributes(CREATURE_BELIEF_KIND kind, uint32_t& count) {
    if (kind >= _CREATURE_BELIEF_KIND_COUNT) {
        count = 0;
        return nullptr;
    }
    count = Table().count[kind];
    return Table().list[kind];
}

const char* GetBeliefKindName(CREATURE_BELIEF_KIND kind) {
    return kind < _CREATURE_BELIEF_KIND_COUNT ? kKinds[kind].name : "?";
}

uint32_t DescribeObject(CREATURE_BELIEF_KIND kind, GameThingWithPos* obj,
                        Creature* observer, uint8_t* out, uint32_t capacity) {
    if (!out || !capacity) return 0;
    uint32_t count = 0;
    const ATTRIBUTE_TYPE* types = GetBeliefAttributes(kind, count);
    if (!types) return 0;
    if (count > capacity) count = capacity;
    for (uint32_t i = 0; i < count; ++i) {
        Attribute* a = GetAttribute(types[i]);
        // Buckets are small by construction -- the widest attribute has 45 --
        // so a byte per feature is the natural width for the vector.
        out[i] = a ? static_cast<uint8_t>(a->Evaluate(obj, observer)) : 0;
    }
    return count;
}
