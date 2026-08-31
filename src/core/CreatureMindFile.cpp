// CreatureMindFile — translated from runblack_decrypted.exe (v1.0).
// Grammar: work/decomp/mind_format.txt. Trail: work/decomp/creature_data.md.

#include "black/CreatureMindFile.h"

#include <cstdio>
#include <cstring>

namespace creature {

namespace {

// The stream primitives, minus the buffering. The original reads the file in
// 1024-byte chunks (cursor at +0x50C, buffer at +0x10C, refilled by
// sub_6AB2E0); from a whole file in memory that is just a cursor.
struct Reader {
    const uint8_t* d;
    size_t         n;
    size_t         p = 0;
    bool           bad = false;

    bool Want(size_t k) {
        if (bad || p + k > n) { bad = true; return false; }
        return true;
    }
    uint32_t U32() {                       // sub_6AB530
        if (!Want(4)) return 0;
        uint32_t v;
        std::memcpy(&v, d + p, 4);
        p += 4;
        return v;
    }
    uint16_t U16() {                       // sub_6AB4F0
        if (!Want(2)) return 0;
        uint16_t v;
        std::memcpy(&v, d + p, 2);
        p += 2;
        return v;
    }
    float F32() {
        const uint32_t u = U32();
        float f;
        std::memcpy(&f, &u, 4);
        return f;
    }
};

// The loader's prologue is version-dependent and not fully recovered, so the
// name is located by its own shape instead of a fixed offset: a plausible
// length followed by that many ASCII-range wide characters. Both shipped
// layouts (36 for version 25, 40 for version 30) fall out of this, and a wrong
// hit cannot survive the desire-count check that follows.
bool FindName(const uint8_t* d, size_t n, size_t& out_off) {
    const size_t limit = n < 512 ? n : 512;
    for (size_t off = 0; off + 4 < limit; ++off) {
        uint32_t len;
        std::memcpy(&len, d + off, 4);
        if (len < 1 || len > 32 || off + 4 + len * 2 > n) continue;
        bool ascii = true;
        for (uint32_t i = 0; i < len && ascii; ++i) {
            const uint8_t lo = d[off + 4 + i * 2];
            const uint8_t hi = d[off + 4 + i * 2 + 1];
            if (hi != 0 || lo < 32 || lo >= 127) ascii = false;
        }
        if (ascii) { out_off = off; return true; }
    }
    return false;
}

}  // namespace

bool IsSupportedMindVersion(uint32_t version) {
    // The name field arrives at version 0x18; below that the file has no name
    // and no desire block in this shape. The shipped saved minds are 25 and 30.
    return version >= 0x18;
}

bool LoadCreatureMind(const uint8_t* data, size_t size, CreatureMind& out) {
    out = CreatureMind();
    out.total_bytes = size;
    if (!data || size < 8) return false;

    std::memcpy(&out.version, data, 4);
    if (!IsSupportedMindVersion(out.version)) return false;

    size_t name_off = 0;
    if (!FindName(data, size, name_off)) return false;

    Reader r{data, size, name_off};

    const uint32_t name_len = r.U32();
    out.name.reserve(name_len);
    for (uint32_t i = 0; i < name_len; ++i) {
        const uint16_t wc = r.U16();
        out.name.push_back(wc < 0x80 ? static_cast<char>(wc) : '?');
    }

    // sub_4C95D0: six words, then one more from version 0x11.
    for (int i = 0; i < 6; ++i) r.U32();
    if (out.version >= 0x11) r.U32();

    const uint32_t desire_count = r.U32();
    if (r.bad || desire_count != kNumCreatureDesires) return false;

    for (uint32_t i = 0; i < desire_count; ++i) {
        MindDesire& d = out.desires[i];
        d.active = r.U32() != 0;
        d.params[0] = r.F32();
        d.params[1] = r.F32();
        d.params[2] = r.F32();

        // Retained for completeness; neither gate fires for the shipped files.
        if (out.version < 7) r.U32();
        if (out.version >= 6 && out.version < 0xA) r.U32();

        if (out.version >= 9) {
            const uint32_t source_count = r.U32();
            // A misread offset shows up here first: the count is small in every
            // real file, so an absurd one means the cursor is wrong and the
            // parse must stop rather than allocate on garbage.
            if (r.bad || source_count > 64) return false;
            d.sources.resize(source_count);
            for (uint32_t s = 0; s < source_count; ++s) {
                d.sources[s].value = r.F32();
                d.sources[s].strength = r.F32();
                d.sources[s].type = static_cast<CREATURE_DESIRE_SOURCE>(r.U32());
            }
            if (out.version < 0xF) r.U32();
        }
        if (r.bad) return false;
    }

    out.parsed_bytes = r.p;
    return true;
}

bool LoadCreatureMindFile(const char* path, CreatureMind& out) {
    out = CreatureMind();
    if (!path) return false;
    std::FILE* f = std::fopen(path, "rb");
    if (!f) return false;
    std::fseek(f, 0, SEEK_END);
    const long len = std::ftell(f);
    std::fseek(f, 0, SEEK_SET);
    if (len <= 0) { std::fclose(f); return false; }

    std::vector<uint8_t> buf(static_cast<size_t>(len));
    const size_t got = std::fread(buf.data(), 1, buf.size(), f);
    std::fclose(f);
    if (got != buf.size()) return false;
    return LoadCreatureMind(buf.data(), buf.size(), out);
}

}  // namespace creature

// The enum name tables live here rather than in the generated header so the
// generated file stays pure data.
namespace {
struct NameEntry { uint32_t value; const char* name; };

const NameEntry kDesireNames[] = {
#define BW_D(x) { x, #x }
    BW_D(CREATURE_DESIRE_TO_IMPRESS), BW_D(CREATURE_DESIRE_COMPASSION),
    BW_D(CREATURE_DESIRE_ANGER), BW_D(CREATURE_DESIRE_TO_PLAY),
    BW_D(CREATURE_DESIRE_HUNGER), BW_D(CREATURE_DESIRE_FEAR),
    BW_D(CREATURE_DESIRE_CURIOSITY), BW_D(CREATURE_DESIRE_TO_POO),
    BW_D(CREATURE_DESIRE_TIREDNESS), BW_D(CREATURE_DESIRE_WANDERLUST),
    BW_D(CREATURE_DESIRE_TO_PUKE), BW_D(CREATURE_DESIRE_TO_BUILD_HOME),
    BW_D(CREATURE_DESIRE_FOR_WATER), BW_D(CREATURE_DESIRE_TO_RESTORE_HEALTH),
    BW_D(CREATURE_DESIRE_TO_BE_FRIENDS), BW_D(CREATURE_DESIRE_TO_REST),
    BW_D(CREATURE_DESIRE_TO_OBEY_PLAYER), BW_D(CREATURE_DESIRE_ILLNESS),
    BW_D(CREATURE_DESIRE_SADNESS), BW_D(CREATURE_DESIRE_TO_STEAL),
#undef BW_D
};
}  // namespace

const char* GetCreatureDesireName(uint32_t desire) {
    for (const NameEntry& e : kDesireNames)
        if (e.value == desire) return e.name;
    return nullptr;
}

const char* GetCreatureDesireSourceName(uint32_t source) {
    // Only the ones the shipped minds actually reference are named; the rest
    // would be transcription for its own sake.
    switch (source) {
        case IMPRESS_FROM_WATCHING_PLAYER: return "IMPRESS_FROM_WATCHING_PLAYER";
        case IMPRESS_FROM_SEEING_OBJECTS_WHICH_DESERVE_IT:
            return "IMPRESS_FROM_SEEING_OBJECTS_WHICH_DESERVE_IT";
        case COMPASSION_FROM_WATCHING_PLAYER: return "COMPASSION_FROM_WATCHING_PLAYER";
        case COMPASSION_FROM_SEEING_OBJECTS_WHICH_DESERVE_IT:
            return "COMPASSION_FROM_SEEING_OBJECTS_WHICH_DESERVE_IT";
        case COMPASSION_FROM_BEING_CONTENT: return "COMPASSION_FROM_BEING_CONTENT";
        case COMPASSION_INNATE_NICENESS: return "COMPASSION_INNATE_NICENESS";
        case ANGER_FROM_WATCHING_PLAYER: return "ANGER_FROM_WATCHING_PLAYER";
        case ANGER_FROM_SEEING_OBJECTS_WHICH_DESERVE_IT:
            return "ANGER_FROM_SEEING_OBJECTS_WHICH_DESERVE_IT";
        case ANGER_FROM_BEING_DAMAGED: return "ANGER_FROM_BEING_DAMAGED";
        default: return nullptr;
    }
}
