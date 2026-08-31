#pragma once
// CreatureBeliefAttributes — what the creature notices about a thing.
//
// A creature does not perceive objects directly; it holds *beliefs* about them,
// and each kind of belief describes its subject with a fixed, ordered list of
// attributes. That list is the feature vector its decision trees branch on, so
// it is also the limit of what the creature can ever learn to distinguish: a
// creature can learn "burning houses are interesting" because OnFire is in the
// abode vector, and can never learn anything about a forest being on fire,
// because it is not in the forest one.
//
// Recovered from runblack_decrypted.exe (v1.0). The vtable walk cannot reach
// this — the builders are non-virtual — so they were found by following data
// references from the Attribute vtables back to the functions that construct
// them (tools/decomp `xrefs`). The original file is C:\dev\black\
// CreatureMentalBeliefs.cpp, named in the allocator's debug arguments.
//
// Every belief starts with the same seven attributes from the base builder
// (sub_4BBC20), then its own subclass adds up to four more. Order is the vector
// index and is preserved exactly.

#include "Attribute.h"

#include <cstdint>

struct Creature;
struct GameThingWithPos;

// The belief subclasses that exist in the binary. CreatureBeliefSmall and the
// plain CreatureBelief carry the common seven and nothing else, as do the
// citadel, context and flock beliefs.
enum CREATURE_BELIEF_KIND : uint32_t {
    CREATURE_BELIEF_BASE     = 0,  // CreatureBelief / CreatureBeliefSmall
    CREATURE_BELIEF_ABODE    = 1,
    CREATURE_BELIEF_CITADEL  = 2,
    CREATURE_BELIEF_CONTEXT  = 3,
    CREATURE_BELIEF_CREATURE = 4,
    CREATURE_BELIEF_FLOCK    = 5,
    CREATURE_BELIEF_FOREST   = 6,
    CREATURE_BELIEF_TOWN     = 7,
    CREATURE_BELIEF_VILLAGER = 8,
    _CREATURE_BELIEF_KIND_COUNT,
};

// Seven common plus at most four specific.
enum : uint32_t { kMaxBeliefAttributes = 11 };

// The ordered attribute list for a kind of belief. `count` receives its length;
// the pointer is to static storage and outlives the caller.
const ATTRIBUTE_TYPE* GetBeliefAttributes(CREATURE_BELIEF_KIND kind, uint32_t& count);

// Human-readable name of a belief kind, for debug output.
const char* GetBeliefKindName(CREATURE_BELIEF_KIND kind);

// Run every attribute for `kind` over `obj` and write the buckets to `out`.
// Returns how many were written, which is min(count, capacity). This is the
// feature vector a decision tree indexes into.
uint32_t DescribeObject(CREATURE_BELIEF_KIND kind,
                        GameThingWithPos* obj,
                        Creature* observer,
                        uint8_t* out,
                        uint32_t capacity);
