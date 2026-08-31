// test_mind — the CreatureMind file reader.
//
// Two halves. The first builds a mind in memory and reads it back, so the
// grammar is exercised on every machine. The second reads the minds Black &
// White actually ships, when they are present, and checks the thing that makes
// this parse trustworthy rather than merely plausible: each desire's sources
// must be the ones named for that desire in a completely separate enum. The
// parser knows nothing about either enum, so that alignment cannot come from a
// wrong offset.

#include <black/CreatureActionNames.h>
#include <black/CreatureDesire.h>
#include <black/CreatureMindFile.h>

#include <cstdio>
#include <cmath>
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

    // --- the desire model, fed from a real mind -----------------------------
    {
        CreatureMind seeded;
        std::vector<uint8_t> synth = BuildMind(25, "Modelled", 2);
        CHECK(LoadCreatureMind(synth.data(), synth.size(), seeded),
              "a mind for the desire model parses");

        DesireModel model;
        model.InitFromMind(seeded);
        int act = 0, srcs = 0;
        for (uint32_t i = 0; i < kNumCreatureDesires; ++i) {
            if (model.active[i]) ++act;
            srcs += int(model.source_count[i]);
        }
        CHECK(act == 20, "the model takes its active desires from the mind");
        CHECK(srcs == 80, "and its sources: two per desire across all forty");

        DesireTuning tuning[kNumCreatureDesires];
        for (DesireTuning& t : tuning) {
            t.rate = 1.0f;            // no decay by default
            t.min_value = 0.0f;
            t.max_value = 10.0f;
            t.slow_max = 10.0f;
        }
        SourceBounds bounds[64];
        for (SourceBounds& b : bounds) { b.min_value = 0.0f; b.max_value = 1.0f; b.decay = 0.0f; }

        // Nothing active has any value yet, so the dominant desire is whichever
        // active one comes first.
        CHECK(model.DominantDesire() == 1, "with no values the first active desire leads");

        model.desires[7].value = 5.0f;
        CHECK(model.DominantDesire() == 7, "the strongest active desire leads");
        model.active[7] = false;
        CHECK(model.DominantDesire() != 7, "an inactive desire never leads");
        model.active[7] = true;

        // A rate below 1 inflates: (1/0.5 - 1) * dt + 1 = 1 + dt.
        DesireModel m2;
        m2.InitFromMind(seeded);
        m2.desires[1].value = 1.0f;
        DesireTuning fast[kNumCreatureDesires];
        for (DesireTuning& t : fast) { t.rate = 0.5f; t.max_value = 100.0f; t.slow_max = 100.0f; }
        m2.UpdateDesire(1, fast[1], bounds, 64, 1.0f);
        CHECK(std::fabs(m2.desires[1].value - 2.0f) < 1e-5f,
              "a rate of 0.5 doubles the desire over one second");

        // The clamp holds on both sides.
        m2.desires[1].value = 1000.0f;
        m2.UpdateDesire(1, tuning[1], bounds, 64, 1.0f);
        CHECK(m2.desires[1].value == 10.0f, "the value is clamped to the tuning maximum");

        // The coupling: desire 1 rising drags desire 3 with it, and pushes
        // desire 5 the other way. This is the bit that makes desires a system
        // rather than 40 independent numbers.
        DesireModel m3;
        m3.InitFromMind(seeded);
        for (uint32_t i = 0; i < kNumCreatureDesires; ++i) m3.active[i] = true;
        m3.desires[1].value = 1.0f;
        m3.desires[3].value = 1.0f;
        m3.desires[5].value = 1.0f;
        m3.desires[9].value = 1.0f;
        m3.dependency[1][3] = 1.0f;    // positive: amplify
        m3.dependency[1][5] = -1.0f;   // negative: damp
        m3.UpdateDesire(1, fast[1], bounds, 64, 1.0f);
        CHECK(std::fabs(m3.desires[3].value - 2.0f) < 1e-5f,
              "a positive dependency amplifies the other desire by the same factor");
        CHECK(std::fabs(m3.desires[5].value - 0.5f) < 1e-5f,
              "a negative one divides by it");
        CHECK(std::fabs(m3.desires[9].value - 1.0f) < 1e-5f,
              "and an uncoupled desire is untouched");

        // Sources decay at their own per-type rate, into their own bounds.
        DesireModel m4;
        m4.InitFromMind(seeded);
        m4.sources[1][0].value = 1.0f;
        SourceBounds decaying[64];
        for (SourceBounds& b : decaying) { b.min_value = 0.25f; b.max_value = 1.0f; b.decay = 0.5f; }
        m4.UpdateDesire(1, tuning[1], decaying, 64, 1.0f);
        CHECK(std::fabs(m4.sources[1][0].value - 0.5f) < 1e-5f, "a source decays by its rate");
        m4.UpdateDesire(1, tuning[1], decaying, 64, 10.0f);
        CHECK(std::fabs(m4.sources[1][0].value - 0.25f) < 1e-5f,
              "and stops at its own floor, not the desire's");

        // The bias is held within a fifth of the species target.
        DesireModel m5;
        m5.InitFromMind(seeded);
        DesireTuning drift[kNumCreatureDesires];
        for (DesireTuning& t : drift) {
            t.rate = 1.0f; t.max_value = 10.0f; t.slow_max = 10.0f;
            t.bias_gain = 100.0f; t.type_target = 1.0f;
        }
        m5.UpdateDesire(1, drift[1], bounds, 64, 1.0f);
        CHECK(std::fabs(m5.desires[1].bias - 1.2f) < 1e-5f,
              "the bias cannot drift more than 0.2 above its species target");
    }

    // --- plans ---------------------------------------------------------------
    {
        PlanState ps;
        bool owned = true;
        for (uint32_t i = 0; i < kNumCreatureDesires; ++i)
            if (ps.plans[i].desire != i) owned = false;
        CHECK(owned, "every plan slot is pre-assigned to its own desire at init");
        CHECK(ps.current_desire == kNumCreatureDesires, "and nothing is current yet");

        ActionPlan p;
        p.desire = CREATURE_DESIRE_TO_OBEY_PLAYER;   // 24
        p.action = 89;
        p.target[0] = 0x1234;
        ps.SetCurrent(p);
        CHECK(ps.current_desire == 24 && ps.current_action == 89,
              "installing a plan makes its desire and action current");
        CHECK(ps.For(24) && ps.For(24)->target[0] == 0x1234,
              "and the plan is stored in its own desire's slot");
        CHECK(ps.For(kNumCreatureDesires) == nullptr, "an out-of-range desire has no slot");

        ps.Init();
        CHECK(ps.current_desire == kNumCreatureDesires && ps.For(24)->action == 0,
              "re-init clears the current plan and the slots");
    }

    // --- action names --------------------------------------------------------
    {
        CHECK(CountNamedCreatureActions() == 95,
              "95 of the 328 action slots carry a name in this build");
        CHECK(GetCreatureActionName(236) && !std::strcmp(GetCreatureActionName(236), "Kick"),
              "action 236 is Kick");
        CHECK(GetCreatureActionName(327) && !std::strcmp(GetCreatureActionName(327), "WaterTree"),
              "action 327 is WaterTree");
        CHECK(GetCreatureActionName(100) == nullptr,
              "an unnamed slot reports nothing rather than a stale neighbour");
        CHECK(GetCreatureActionName(kNumCreatureActions) == nullptr,
              "and so does one past the end");

        // Every named action should sit in the contiguous 233..327 run the
        // initialiser writes; anything outside it means the decode drifted.
        bool in_run = true;
        int named = 0;
        for (uint32_t a = 0; a < kNumCreatureActions; ++a) {
            if (!GetCreatureActionName(a)) continue;
            ++named;
            if (a < 233) in_run = false;
        }
        CHECK(in_run && named == 95, "and they all fall in the range the initialiser writes");

        // 52 of the named actions also carry the address of the function that
        // implements them, which is the entry point for the next pass.
        int with_handler = 0;
        bool plausible = true;
        for (uint32_t a = 0; a < kNumCreatureActions; ++a) {
            const uint32_t h = GetCreatureActionHandlerAddress(a);
            if (!h) continue;
            ++with_handler;
            if (h < 0x400000 || h > 0x800000) plausible = false;
        }
        CHECK(with_handler == 52, "52 named actions carry a handler address");
        CHECK(plausible, "and every one lands inside the binary's code range");
        CHECK(GetCreatureActionHandlerAddress(236) == 0x4ab4f0,
              "Kick is implemented at 0x4AB4F0");
        CHECK(GetCreatureActionHandlerAddress(100) == 0,
              "an unnamed action has no handler");

        // A plan's action can be named, which is what makes agenda output readable.
        ActionPlan p;
        p.desire = CREATURE_DESIRE_HUNGER;
        p.action = 236;
        CHECK(GetCreatureActionName(p.action) != nullptr,
              "a plan's action resolves to a name");
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
