// test_mind — the CreatureMind file reader.
//
// Two halves. The first builds a mind in memory and reads it back, so the
// grammar is exercised on every machine. The second reads the minds Black &
// White actually ships, when they are present, and checks the thing that makes
// this parse trustworthy rather than merely plausible: each desire's sources
// must be the ones named for that desire in a completely separate enum. The
// parser knows nothing about either enum, so that alignment cannot come from a
// wrong offset.

#include <black/CreatureMindFile.h>

#include <cstdio>
#include <cstring>
#include <string>
#include <vector>

using namespace creature;

static int g_fail = 0;
#define CHECK(cond, msg) do { if (!(cond)) { printf("FAIL: %s\n", msg); ++g_fail; } \
                              else printf("ok  : %s\n", msg); } while (0)

// --- a synthetic mind, built to the recovered grammar ----------------------
namespace {

struct Builder {
    std::vector<uint8_t> d;
    void U32(uint32_t v) { for (int i = 0; i < 4; ++i) d.push_back(uint8_t(v >> (8 * i))); }
    void F32(float f) { uint32_t u; std::memcpy(&u, &f, 4); U32(u); }
    void U16(uint16_t v) { d.push_back(uint8_t(v)); d.push_back(uint8_t(v >> 8)); }
    void Name(const char* s) {
        const uint32_t n = uint32_t(std::strlen(s));
        U32(n);
        for (uint32_t i = 0; i < n; ++i) U16(uint8_t(s[i]));
    }
};

std::vector<uint8_t> BuildMind(uint32_t version, const char* name,
                               uint32_t sources_per_desire) {
    Builder b;
    b.U32(version);
    // A prologue the reader has to skip past to find the name. Non-zero so a
    // lazy "assume offset 4" implementation would not pass.
    for (int i = 0; i < 8; ++i) b.U32(0xDEADBEEF);
    b.Name(name);
    for (int i = 0; i < 6; ++i) b.U32(0);
    if (version >= 0x11) b.U32(0);
    b.U32(kNumCreatureDesires);
    for (uint32_t i = 0; i < kNumCreatureDesires; ++i) {
        b.U32(i % 2);                       // active flag alternates
        b.F32(0.1f * float(i));
        b.F32(2.0f);
        b.F32(10.0f + float(i));
        b.U32(sources_per_desire);
        for (uint32_t s = 0; s < sources_per_desire; ++s) {
            b.F32(0.5f);
            b.F32(0.25f * float(s + 1));
            b.U32(s);                        // source type
        }
    }
    return b.d;
}

}  // namespace

int main() {
    // --- synthetic round trip ----------------------------------------------
    CreatureMind m;

    std::vector<uint8_t> good = BuildMind(25, "Testy", 2);
    CHECK(LoadCreatureMind(good.data(), good.size(), m), "a well-formed mind parses");
    CHECK(m.version == 25, "version comes off the front of the file");
    CHECK(m.name == "Testy", "the name is found past a non-trivial prologue");
    CHECK(m.desires[0].active == false && m.desires[1].active == true,
          "the per-desire active flag round trips");
    CHECK(m.desires[3].sources.size() == 2, "each desire keeps its sources");
    CHECK(m.desires[3].sources[1].type == 1, "and their types");
    CHECK(m.parsed_bytes == good.size(),
          "the parse consumes the file exactly -- the check that catches a "
          "drifting cursor");

    // A version-30 file has the same desire block; only the prologue differs.
    std::vector<uint8_t> v30 = BuildMind(30, "Richard", 1);
    CHECK(LoadCreatureMind(v30.data(), v30.size(), m), "a version-30 mind parses too");
    CHECK(m.name == "Richard" && m.version == 30, "with its own name and version");

    // --- rejection ----------------------------------------------------------
    CHECK(!IsSupportedMindVersion(17), "version 17 is not this format");
    CHECK(IsSupportedMindVersion(25) && IsSupportedMindVersion(30),
          "25 and 30 are");

    std::vector<uint8_t> old = BuildMind(17, "Old", 1);
    CHECK(!LoadCreatureMind(old.data(), old.size(), m),
          "and a version-17 file is refused rather than misread");

    CHECK(!LoadCreatureMind(nullptr, 0, m), "no data is refused");
    std::vector<uint8_t> tiny = {1, 2, 3};
    CHECK(!LoadCreatureMind(tiny.data(), tiny.size(), m), "a stub file is refused");

    // Truncation must fail, not return a half-filled mind as success.
    std::vector<uint8_t> cut = BuildMind(25, "Cut", 2);
    cut.resize(cut.size() / 2);
    CHECK(!LoadCreatureMind(cut.data(), cut.size(), m), "a truncated mind is refused");

    // An absurd source count is how a drifting cursor shows up first.
    std::vector<uint8_t> bad = BuildMind(25, "Bad", 2);
    for (size_t i = 0; i + 4 <= bad.size(); ++i) {
        uint32_t v;
        std::memcpy(&v, &bad[i], 4);
        if (v == 2) { const uint32_t huge = 100000; std::memcpy(&bad[i], &huge, 4); break; }
    }
    CHECK(!LoadCreatureMind(bad.data(), bad.size(), m),
          "an implausible source count stops the parse instead of allocating on it");

    // --- the minds the game ships -------------------------------------------
    struct Shipped { const char* file; uint32_t version; const char* name; };
    const Shipped kShipped[] = {
        {"KhazarCreature", 25, "Matey"},
        {"LethysCreature", 25, "Matey"},
        {"NemesisCreature", 25, "Matey"},
        {"ComputerControlledCreature", 30, "Richard"},
    };

    // The working directory depends on how the test is launched, so try the
    // plausible roots rather than assuming one.
    const char* kRoots[] = {
        "game_data/CreatureMind/",
        "../game_data/CreatureMind/",
        "../../game_data/CreatureMind/",
        "../../../game_data/CreatureMind/",
        "../../../../game_data/CreatureMind/",
    };

    int found = 0;
    for (const Shipped& s : kShipped) {
        CreatureMind real;
        bool got = false;
        for (const char* root : kRoots) {
            if (LoadCreatureMindFile((std::string(root) + s.file).c_str(), real)) {
                got = true;
                break;
            }
        }
        if (!got) continue;
        ++found;
        CHECK(real.version == s.version, s.file);
        CHECK(real.name == s.name, "  and its creature is named as expected");

        int active = 0, sources = 0;
        for (const MindDesire& d : real.desires) {
            if (d.active) ++active;
            sources += int(d.sources.size());
        }
        CHECK(active > 0 && active < int(kNumCreatureDesires),
              "  some desires are active and some are not");
        CHECK(sources == 58, "  58 desire sources, as every shipped mind has");

        // The load-bearing check. Nothing in the parser knows the desire order
        // or the source names; if the offsets were wrong these would not line up.
        CHECK(real.desires[0].sources.size() == 2 &&
              real.desires[0].sources[0].type == IMPRESS_FROM_WATCHING_PLAYER &&
              real.desires[0].sources[1].type ==
                  IMPRESS_FROM_SEEING_OBJECTS_WHICH_DESERVE_IT,
              "  desire 0 (TO_IMPRESS) draws on exactly the IMPRESS_* sources");
        CHECK(real.desires[1].sources.size() == 4 &&
              real.desires[1].sources[0].type == COMPASSION_FROM_WATCHING_PLAYER &&
              real.desires[1].sources[3].type == COMPASSION_INNATE_NICENESS,
              "  desire 1 (COMPASSION) draws on the COMPASSION_* sources");
        CHECK(real.desires[2].sources.size() == 3 &&
              real.desires[2].sources[0].type == ANGER_FROM_WATCHING_PLAYER,
              "  desire 2 (ANGER) draws on the ANGER_* sources");

        bool in_range = true;
        for (const MindDesire& d : real.desires)
            for (const MindDesireSource& src : d.sources)
                if (!(src.strength >= 0.0f && src.strength <= 1.0f)) in_range = false;
        CHECK(in_range, "  every source strength lands on [0, 1]");

        CHECK(real.parsed_bytes > 0 && real.parsed_bytes < real.total_bytes,
              "  the desire block is a prefix of the file, rest still unread");
    }

    if (!found) {
        printf("note: game_data/CreatureMind not reachable from here; the shipped-mind\n"
               "      checks were skipped. The synthetic ones above still ran.\n");
    } else {
        printf("      read %d shipped minds\n", found);
    }

    printf(g_fail ? "\n%d FAILURE(S)\n" : "\nALL PASS\n", g_fail);
    return g_fail ? 1 : 0;
}
