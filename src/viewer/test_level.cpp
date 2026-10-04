// test_level — Land 1 through the native level loader, headless: the towns,
// their abodes and housed villagers come out linked, and the world survives
// simulation turns. Needs game_data/ (Land1.txt, info.dat); skips without it.
#include <black/Abode.h>
#include <black/InfoDat.h>
#include <black/LevelLoader.h>
#include <black/Terrain.h>
#include <black/Town.h>
#include <black/Villager.h>
#include "lnd_loader.h"

#include <cstdio>
#include <string>

static int g_fail = 0;
#define CHECK(cond, msg) do { if (!(cond)) { printf("FAIL: %s\n", msg); ++g_fail; } \
                              else printf("ok  : %s\n", msg); } while (0)

int main() {
    const char* roots[] = {"game_data/", "../game_data/", "../../game_data/", "../../../game_data/"};
    std::string root;
    for (const char* r : roots)
        if (infodat::Load((std::string(r) + "info.dat").c_str())) { root = r; break; }
    if (root.empty()) { printf("note: game_data not reachable; skipped\n"); return 0; }

    // The real landscape, for the drinking-water search (cell flags).
    static bw::Landscape land;
    if (bw::LoadLND(root + "Land1.lnd", land))
        g_cell_flags_func = [](uint32_t cx, uint32_t cz) { return bw::LandscapeCellFlags(land, cx, cz); };

    // No meshes headless: a stand-in host that sizes every abode mesh at 6 m.
    g_mesh_radius_func = [](int32_t) { return 6.0f; };

    level::World w;
    std::string err;
    CHECK(level::Load((root + "Land1.txt").c_str(), w, &err), "Land1.txt loads");
    printf("      %d lines, %d commands, %d handled, %zu objects, %zu towns\n",
           w.lines, w.commands, w.handled, w.objects.size(), w.towns.size());
    for (auto& u : w.unhandled) printf("      not yet: %-32s x%d\n", u.first.c_str(), u.second);

    CHECK(w.towns.size() == 6, "six towns (CREATE_TOWN x6)");
    CHECK(w.landscape.find("Land1.lnd") != std::string::npos, "LOAD_LANDSCAPE recorded");

    int abodes = 0, housed = 0, with_info = 0;
    bool towns_own_their_abodes = true;
    for (Town* t : w.towns)
        for (Abode* a = reinterpret_cast<Abode*>(t->abode_list.head); a; a = a->next) {
            ++abodes;
            if (a->GetTown() != t) towns_own_their_abodes = false;
        }
    for (auto& s : w.objects) {
        with_info += s.obj->info != nullptr;
        if (s.command == "CREATE_VILLAGER_POS" && static_cast<Villager*>(s.obj)->GetHome()) ++housed;
    }
    char msg[128];
    std::snprintf(msg, sizeof msg, "abodes linked into their towns: %d", abodes);
    CHECK(abodes >= 36 && towns_own_their_abodes, msg);
    std::snprintf(msg, sizeof msg, "villagers housed at their CREATE_VILLAGER_POS home: %d of 55", housed);
    CHECK(housed > 0, msg);
    std::snprintf(msg, sizeof msg, "objects with an info record: %d of %zu", with_info, w.objects.size());
    CHECK(with_info == static_cast<int>(w.objects.size()), msg);

    // v1.0 AddStructureToTown keeps a count beside the list and recomputes the
    // town's bounds; GetRadius is half the larger side of that box.
    bool counts_match = true, radii_ok = true;
    for (Town* t : w.towns) {
        uint32_t n = 0;
        for (Abode* a = reinterpret_cast<Abode*>(t->abode_list.head); a; a = a->next) ++n;
        counts_match &= n == t->abode_list.count;
        const float r = t->GetRadius();
        printf("      town %u: %u abodes, radius %.1f m\n", t->field_0x5b4, n, r);
        if (n) radii_ok &= r > 0.0f;
        if (t->field_0x5b4 == 0) radii_ok &= r > 50.0f && r < 300.0f;  // the player's 34-abode village
    }
    CHECK(counts_match, "each town's abode count matches its list");

    // sub_401220 / sub_405680: index = count - 1 at joining; drinking water
    // within 200 m found on the landscape (bit 0 of +0x7C).
    int watered = 0, indexed = 0, total = 0;
    for (Town* t : w.towns) {
        for (Abode* a = reinterpret_cast<Abode*>(t->abode_list.head); a; a = a->next) {
            ++total;
            watered += a->field_0x7c & 1;
            indexed += a->index < t->abode_list.count;
        }
    }
    std::snprintf(msg, sizeof msg, "abodes with drinking water within 200 m: %d of %d", watered, total);
    CHECK(g_cell_flags_func == nullptr || watered > 0, msg);
    CHECK(indexed == total, "every abode's index is below its town's count");
    CHECK(radii_ok, "towns with abodes have a radius; the player village's is 50-300 m (town 1's 562 m is real: the script puts one of its huts 1.1 km away)");

    for (int turn = 0; turn < 100; ++turn) level::Process(w);
    CHECK(true, "100 simulation turns over towns and objects");

    printf(g_fail ? "\n%d FAILED\n" : "\nall passed\n", g_fail);
    return g_fail ? 1 : 0;
}
