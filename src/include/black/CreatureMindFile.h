#pragma once
// CreatureMindFile — reader for the minds Black & White ships.
//
// `game_data/CreatureMind/` contains pre-trained creatures, dated 21 Feb 2001.
// This reads them: the creature's name; for each of the 40 desires whether it
// is active, its three tuning floats and the sources that feed it; its learning
// episodes; and the abilities and spells it knows. docs/creature-chooser.md.
//
// Recovered from runblack_decrypted.exe (v1.0). The loader is sub_4C7CF0, which
// reads through a 1024-byte buffered stream with three primitives (1, 2 and 4
// bytes -- sub_6AB4B0 / sub_6AB4F0 / sub_6AB530), and the top-level
// deserializer is sub_4C95D0. The whole format is version-gated on one global,
// so every field carries the revision that introduced it. The extracted grammar
// is work/decomp/mind_format.txt; the trail is work/decomp/creature_data.md.
//
// Why this is trustworthy rather than a plausible parse: the file gives no
// indication of which desire is which, yet reading it against the grammar makes
// desire 0's sources come out as exactly IMPRESS_FROM_WATCHING_PLAYER and
// IMPRESS_FROM_SEEING_OBJECTS_WHICH_DESERVE_IT, desire 1's as the four
// COMPASSION_* ones, desire 2's as the ANGER_* ones, and so on for all 40. The
// desire order and the source names come from two separate enums in
// bw1-decomp; nothing in the parser knows about either. That alignment is not
// something a wrong offset produces.

#include "CreatureDesireEnums.h"

#include <cstddef>
#include <cstdint>
#include <string>
#include <vector>

namespace creature {

enum : uint32_t { kNumCreatureDesires = 40 };

// One thing that feeds a desire. Laid out in the original as
// CreatureDesireSource (0x10): two floats, then the source type.
struct MindDesireSource {
    float                  value = 0.0f;     // +0x00
    float                  strength = 0.0f;  // +0x04: the threshold sub_4C04E0's sigmoid measures past
    CREATURE_DESIRE_SOURCE type = static_cast<CREATURE_DESIRE_SOURCE>(0);  // +0x0C
};

struct MindDesire {
    // The first field per desire is 0 or 1 across every shipped mind and gates
    // whether the creature has the desire at all.
    bool  active = false;
    // The desire's value, its maximum and its cycle time in seconds -- the
    // CreatureDesires fields at +0x148, +0x468 and +0x1E8. Identified by
    // matching info.dat: hunger's maximum is 2 and its cycle 20 there, 2.0 and
    // 23.6 in Khazar's mind; curiosity's cycle is 5 there, 5.3 in his.
    float params[3] = {0.0f, 0.0f, 0.0f};
    std::vector<MindDesireSource> sources;
};

// One remembered experience (sub_4CA390): a CreatureLearningEpisode (20 bytes)
// holding a CreatureLearningContext (24 bytes) with the belief it was about.
struct MindEpisode {
    uint32_t lead = 0;                     // read and dropped by the loader; 2 in every shipped file
    uint32_t context[2] = {0, 0};          // CreatureLearningContext +12, +16
    uint32_t belief_type = 0;              // sub_4B8FF0's type: 0 town, 3 abode, 6 villager, 8 creature...
    uint32_t belief_words[2] = {0, 0};     // the belief's +36, +40 (sub_4C9ED0)
    std::vector<uint32_t> attributes;      // each attribute's value (+8), in the belief's order
    float    weight = 0.0f;                // episode +12: how good it was
};

// One of a desire's two learned trees (sub_4CA2E0). The loader rebuilds the
// tree from the episodes (sub_4B78E0); at most 16 are kept.
struct MindTree {
    uint32_t head[3] = {0, 0, 0};          // +0, then +4 twice (the second read wins)
    std::vector<MindEpisode> episodes;
};

struct CreatureMind {
    uint32_t   version = 0;
    std::string name;                 // UTF-8, converted from the file's UTF-16
    MindDesire desires[kNumCreatureDesires];

    // sub_4CA1E0: per desire, two trees (mental slots i and i+40).
    MindTree learning[kNumCreatureDesires][2];
    // sub_4CA260 (version 0xC on): one word per action of that build (313 at
    // version 25, 322 at 30). All zero in the shipped minds.
    std::vector<uint32_t> action_words;
    // sub_4C9D70: the CreatureActionKnownAbout lists sub_4C3F50 searches --
    // abilities (kind 0) and magic types (kind 1).
    std::vector<uint32_t> known_abilities;
    std::vector<uint32_t> known_spells;

    // Then the creature's development stage (creature+0x1268, 0..13) and its
    // saved body (sub_4CA040, CreaturePhysical): see CreatureBody.
    uint32_t stage = 0;
    bool     has_body = false;
    struct Body {
        uint32_t turn = 0, age = 0;
        float reserve = 0, reserve_max = 0, energy = 0, poo = 0, exhaustion = 0, dehydration = 0;
    } body;

    // Byte offset the parse finished at, and the file size it was read from.
    // What follows the body (sub_4D0310, sub_5E6A60, ...) is not yet read.
    size_t parsed_bytes = 0;
    size_t total_bytes = 0;
};

// Parse a mind from memory. Returns false and leaves `out` partially filled if
// the data does not match the grammar -- a short buffer, an implausible desire
// or source count, or a version this reader does not handle.
//
// Only the creature-mind format is handled (the version-25 and version-30 files
// in the shipped set). The version-17 files in the same directory are a
// different format entirely: the mind loader (sub_4C9170) reads a species index
// below 17 as the second word, and theirs is a float. They need separate work.
bool LoadCreatureMind(const uint8_t* data, size_t size, CreatureMind& out);

// Convenience wrapper that reads the file first. Returns false if it cannot be
// opened or does not parse.
bool LoadCreatureMindFile(const char* path, CreatureMind& out);

// Whether this reader understands a file's version word, without parsing it.
bool IsSupportedMindVersion(uint32_t version);

}  // namespace creature
