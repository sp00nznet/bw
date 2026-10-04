// test_infodat — the info.dat loader.
//
// Synthetic half (runs everywhere): records land at +16 of their elements in
// file order, the GBaseInfo header is linked and numbered, and a file whose
// size disagrees with the layout is refused rather than half-read.
//
// Real half (needs game_data/info.dat): the shipped file loads, and the record
// names at the first and last element of the big tables are the right ones.
// The layout came from the loader's code, not from this file, so names landing
// at the same offset in every record of every table is the proof the strides
// are right. See docs/info-dat.md.

#include <black/InfoDat.h>
#include <black/GBaseInfo.h>

#include <cstdio>
#include <cstring>
#include <string>
#include <vector>

using namespace infodat;

static int g_fail = 0;
#define CHECK(cond, msg) do { if (!(cond)) { printf("FAIL: %s\n", msg); ++g_fail; } \
                              else printf("ok  : %s\n", msg); } while (0)

static std::vector<uint8_t> Synthetic() {
    std::vector<uint8_t> d(0x2C + kPayloadBytes, 0);
    std::memcpy(d.data(), "LiOnHeAdInfo", 12);
    const uint32_t n = kPayloadBytes;
    std::memcpy(d.data() + 0x28, &n, 4);
    // Stamp each record's first byte with its section number.
    size_t off = 0x2C;
    for (int s = 0; s < SECTION_COUNT; ++s)
        for (uint32_t i = 0; i < kLayout[s].count; ++i, off += kLayout[s].record_bytes)
            d[off] = uint8_t(s);
    return d;
}

static void TestSynthetic() {
    std::vector<uint8_t> d = Synthetic();
    std::string err;
    CHECK(LoadFromMemory(d.data(), d.size(), &err), "synthetic file loads");
    bool placed = true;
    for (int s = 0; s < SECTION_COUNT; ++s) {
        const uint8_t* last = static_cast<const uint8_t*>(Element(Section(s), Count(Section(s)) - 1));
        if (!last || last[16] != uint8_t(s)) placed = false;
    }
    CHECK(placed, "every section's records land at +16 of its own elements");
    auto* a = Get<GBaseInfo>(DETAIL_ABODE_INFO, 0);
    auto* b = Get<GBaseInfo>(DETAIL_ABODE_INFO, 1);
    CHECK(a && b && b->next == a && b->index == a->index + 1, "header: linked and numbered in load order");
    CHECK(Element(DETAIL_ABODE_INFO, 147) == nullptr, "out of range is nullptr");

    d.push_back(0);
    CHECK(!LoadFromMemory(d.data(), d.size(), &err) && !Loaded(), "a file one byte long is refused");
    d.pop_back();
    d[0] = 'X';
    CHECK(!LoadFromMemory(d.data(), d.size(), &err), "bad magic is refused");
}

static void TestShipped() {
    const char* roots[] = {"game_data/", "../game_data/", "../../game_data/", "../../../game_data/"};
    std::string err;
    bool ok = false;
    for (const char* r : roots)
        if ((ok = Load((std::string(r) + "info.dat").c_str(), &err))) break;
    if (!ok) { printf("note: game_data/info.dat not reachable (%s); shipped checks skipped\n", err.c_str()); return; }
    CHECK(true, "shipped info.dat loads: 102 sections, 580710 payload bytes, EOF exact");

    struct { Section s; uint32_t i; const char* name; } anchors[] = {
        {DETAIL_ABODE_INFO, 0, "Celtic Hut"},           {DETAIL_ABODE_INFO, 146, "Bell Tower"},
        {DETAIL_VILLAGER_INFO, 0, "Celtic Housewife Female"}, {DETAIL_VILLAGER_INFO, 83, "SailorAccordian"},
        {DETAIL_CREATURE_INFO, 0, "Ape creature"},      {DETAIL_CREATURE_INFO, 16, "Gorilla creature"},
        {DETAIL_ANIMAL_INFO, 0, "Lion"},                {DETAIL_ANIMAL_INFO, 30, "Puzzle Pig"},
        {DETAIL_FEATURE_INFO, 75, "TombStone"},         {DETAIL_TREE_INFO, 0, "Beech Tree"},
        {DETAIL_MOBILE_STATIC_INFO, 60, "Meteor"},      {DETAIL_REWARD_INFO, 0, "Reward None"},
        {DETAIL_LEASH_SELECTOR_INFO, 0, "Leash Selector"},
    };
    for (auto& a : anchors) {
        char msg[160];
        std::snprintf(msg, sizeof msg, "%s[%u] is \"%s\" (got \"%s\")",
                      kLayout[a.s].name, a.i, a.name, DebugName(a.s, a.i));
        CHECK(std::strcmp(DebugName(a.s, a.i), a.name) == 0, msg);
    }
}

// Every type name the shipped level scripts use must resolve to a record --
// otherwise that object would silently run with no balance data.
static void TestScriptNames() {
    if (!Loaded()) return;
    const char* roots[] = {"game_data/", "../game_data/", "../../game_data/", "../../../game_data/"};
    struct { const char* fn; int quoted_arg; Section s; } kinds[] = {
        {"CREATE_ABODE(", 2, DETAIL_ABODE_INFO}, {"CREATE_PLANNED_ABODE(", 2, DETAIL_ABODE_INFO},
        {"CREATE_VILLAGER_POS(", 3, DETAIL_VILLAGER_INFO}, {"CREATE_NEW_FEATURE(", 2, DETAIL_FEATURE_INFO},
    };
    for (const char* r : roots) {
        int total = 0, resolved = 0;
        for (int land = 1; land <= 5; ++land) {
            FILE* f = std::fopen((std::string(r) + "Land" + std::to_string(land) + ".txt").c_str(), "rb");
            if (!f) continue;
            char line[1024];
            while (std::fgets(line, sizeof line, f))
                for (auto& k : kinds) {
                    const char* p = std::strstr(line, k.fn);
                    if (!p || (p > line && p[-1] != ' ' && p[-1] != '\t')) continue;
                    for (int q = 1; q < k.quoted_arg && p; ++q) p = std::strchr(p + 1, '"'), p = p ? std::strchr(p + 1, '"') : p;
                    if (!p || !(p = std::strchr(p + 1, '"'))) continue;
                    std::string name(p + 1, std::strcspn(p + 1, "\""));
                    ++total;
                    const int i = k.s == DETAIL_ABODE_INFO ? FindAbode(name.c_str()) : FindByName(k.s, name.c_str());
                    if (i >= 0) ++resolved; else printf("      unresolved %s\"%s\"\n", k.fn, name.c_str());
                }
            std::fclose(f);
        }
        if (!total) continue;  // this root has no Land files; try the next
        char msg[96];
        std::snprintf(msg, sizeof msg, "Land1-5 type names resolve to records: %d/%d", resolved, total);
        CHECK(resolved == total, msg);
        return;
    }
}

int main() {
    TestSynthetic();
    TestShipped();
    TestScriptNames();
    printf(g_fail ? "\n%d FAILED\n" : "\nall passed\n", g_fail);
    return g_fail ? 1 : 0;
}
