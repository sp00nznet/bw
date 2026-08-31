#pragma once
// CreatureMindFile — reader for the minds Black & White ships.
//
// `game_data/CreatureMind/` contains pre-trained creatures, dated 21 Feb 2001.
// This reads them: the creature's name, and for each of the 40 desires whether
// it is active, its three tuning floats, and the list of sources that feed it.
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
    float                  strength = 0.0f;  // +0x04
    CREATURE_DESIRE_SOURCE type = static_cast<CREATURE_DESIRE_SOURCE>(0);  // +0x0C
};

struct MindDesire {
    // The first field per desire is 0 or 1 across every shipped mind and gates
    // whether the creature has the desire at all.
    bool  active = false;
    // Three floats whose roles are not established. Their ranges across the
    // shipped files are roughly [0, 0.3], [0.3, 2.0] and [1, 24]; naming them
    // beyond that would be invention, so they are left as read.
    float params[3] = {0.0f, 0.0f, 0.0f};
    std::vector<MindDesireSource> sources;
};

struct CreatureMind {
    uint32_t   version = 0;
    std::string name;                 // UTF-8, converted from the file's UTF-16
    MindDesire desires[kNumCreatureDesires];

    // Byte offset the parse finished at, and the file size it was read from --
    // the gap is the part of the mind (learning episodes, beliefs, attitude)
    // this reader does not yet cover.
    size_t parsed_bytes = 0;
    size_t total_bytes = 0;
};

// Parse a mind from memory. Returns false and leaves `out` partially filled if
// the data does not match the grammar -- a short buffer, an implausible desire
// or source count, or a version this reader does not handle.
//
// Only the creature-mind format is handled (the version-25 and version-30 files
// in the shipped set). The version-17 files in the same directory are a
// different format entirely: no name, no desire count, just arrays of floats.
// They are behaviour profiles, not saved creatures, and need separate work.
bool LoadCreatureMind(const uint8_t* data, size_t size, CreatureMind& out);

// Convenience wrapper that reads the file first. Returns false if it cannot be
// opened or does not parse.
bool LoadCreatureMindFile(const char* path, CreatureMind& out);

// Whether this reader understands a file's version word, without parsing it.
bool IsSupportedMindVersion(uint32_t version);

}  // namespace creature
