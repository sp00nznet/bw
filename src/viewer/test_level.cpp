// test_level — Land 1 through the native level loader, headless: the towns,
// their abodes and housed villagers come out linked, and the world survives
// simulation turns. Needs game_data/ (Land1.txt, info.dat); skips without it.
#include <black/Abode.h>
#include <black/FishFarm.h>
#include <black/InfoDat.h>
#include <black/LevelLoader.h>
#include <black/Terrain.h>
#include <black/Town.h>
#include <black/Villager.h>
#include "lnd_loader.h"

#include <cmath>
#include <cstdio>
#include <map>
#include <vector>
#include <cstring>
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
    std::snprintf(msg, sizeof msg, "villagers housed (their named home, or another in its town when that is full): %d of 55", housed);
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

    // v1.0 Town::Process: influence restarts from TownInfo (+120) each turn and,
    // on turns divisible by TownInfo +76, gains each abode's influence
    // ((occupants + 1) x built x scale x life x info influence).
    Town* village = level::FindTown(w, 0);
    float base = village->TownInfoInfluence(), sum = 0;
    for (Abode* a = reinterpret_cast<Abode*>(village->abode_list.head); a; a = a->next) sum += a->GetInfluence();
    std::snprintf(msg, sizeof msg, "village influence: TownInfo %.1f, abodes add %.1f, now %.1f",
                  base, sum, village->influence);
    {
        static const char* kNames[17] = {"Food", "Wood", "Playtime", "Protection", "Mercy", "Abodes",
            "Civic_Buildings", "Supply_Worship", "For_Children", "To_Build", "For_Rain", "For_Sun",
            "Repair_Town", "Suppy_Workshop", "For_Wonder", "Relaxation", "Sleep"};
        bool in_range = true, sorted = true;
        for (int k = 0; k < 17; ++k) {
            const float d = village->desire.desire[k];
            in_range &= d >= -1.0f && d <= 1.0f;
            printf("      desire %-16s raw %6.3f -> %6.3f\n", kNames[k], village->desire.raw[k], d);
        }
        for (int k = 1; k < 17; ++k) sorted &= village->desire.sorts[k - 1].field_0x4 >= village->desire.sorts[k].field_0x4;
        Object* pit = reinterpret_cast<Object*>(village->storage_pit_list);
        float per_villager = 0, need_k = 0;
        std::memcpy(&per_villager, reinterpret_cast<const char*>(village) + 0x6EC, 4);
        if (village->info) std::memcpy(&need_k, reinterpret_cast<const char*>(village->info) + 220, 4);
        printf("      store: %s, food %u, wood %u; food needed %.1f (TownInfo +220 %.2f x %.1f); adults %d room %u\n",
               pit ? "yes" : "none", pit ? pit->GetResource(static_cast<RESOURCE_TYPE>(0)) : 0,
               pit ? pit->GetResource(static_cast<RESOURCE_TYPE>(1)) : 0, need_k * per_villager, need_k, per_villager,
               village->stats.num_adults, village->stats.field_0x34);
        CHECK(pit != nullptr, "the village's storage pit is its store (Town::SetStoragePit, sub_6D16B0)");
        CHECK(in_range, "the village's 17 desires are in [-1, 1] (TownDesire::Process, sub_6D7950)");
        CHECK(sorted, "the desire ranking is sorted, highest first (sub_6D7E80)");
    }
    CHECK(sum > 0 &&(village->influence == base || std::fabs(village->influence - (base + sum)) < 0.01f * (base + sum)), msg);
    CHECK(true, "100 simulation turns over towns and objects");

    // The villager state machine (VillagerStates.cpp): from Created, villagers
    // decide, walk home and go inside, or idle around town.
    {
        std::vector<std::pair<Villager*, MapCoords>> start;
        for (auto& s : w.objects)
            if (s.command == "CREATE_VILLAGER_POS") start.push_back({static_cast<Villager*>(s.obj), s.obj->coords});
        std::map<int, int> visited;
        std::map<Villager*, bool> got_home;
        Object* pit = reinterpret_cast<Object*>(level::FindTown(w, 0)->storage_pit_list);
        const uint32_t pit_food0 = pit ? pit->GetResource(static_cast<RESOURCE_TYPE>(0)) : 0;
        float food0 = 0, life0 = 0;
        for (auto& p : start) { food0 += p.first->food; life0 += p.first->life; }
        for (int turn = 0; turn < 2000; ++turn) {
            level::Process(w);
            for (auto& p : start) {
                ++visited[p.first->action.top_state];
                if (p.first->field_0xe0 & 4) got_home[p.first] = true;
            }
        }
        std::map<int, int> states;
        int moved = 0, inside = 0, created = 0;
        for (auto& p : start) {
            Villager* v = p.first;
            ++states[v->action.top_state];
            moved += v->coords.x != p.second.x || v->coords.z != p.second.z;
            inside += (v->field_0xe0 & 4) != 0;
            created += v->action.top_state == VILLAGER_STATE_CREATED;
        }
        printf("      after 2000 more turns: %d of %zu moved, %d inside their home; states:", moved, start.size(), inside);
        for (auto& kv : states) printf(" %d x%d", kv.first, kv.second);
        printf("\n      states visited (villager-turns):");
        for (auto& kv : visited) printf(" %d:%d", kv.first, kv.second);
        printf("\n      %zu villagers got home at least once\n", got_home.size());
        inside = static_cast<int>(got_home.size());

        // The upkeep (sub_6E05D0): food drains, hunger sends villagers to the
        // store (33/34) and to eat (117/118); food comes out of the pit.
        float food1 = 0, life1 = 0;
        int dead = 0;
        for (auto& p : start) {
            food1 += p.first->food; life1 += p.first->life;
            dead += p.first->action.top_state == VILLAGER_STATE_DYING || p.first->action.top_state == VILLAGER_STATE_DEAD;
        }
        const uint32_t pit_food1 = pit ? pit->GetResource(static_cast<RESOURCE_TYPE>(0)) : 0;
        const int n = static_cast<int>(start.size());
        printf("      mean food %.3f -> %.3f, mean life %.3f -> %.3f, %d dead; village store food %u -> %u\n",
               food0 / n, food1 / n, life0 / n, life1 / n, dead, pit_food0, pit_food1);
        std::snprintf(msg, sizeof msg, "villagers eat: %d villager-turns at the store, %d eating; store food %u -> %u",
                      visited[VILLAGER_STATE_ARRIVES_AT_STORAGE_PIT_FOR_FOOD],
                      visited[VILLAGER_STATE_EAT_FOOD] + visited[VILLAGER_STATE_EAT_FOOD_AT_HOME], pit_food0, pit_food1);
        CHECK(visited[VILLAGER_STATE_EAT_FOOD] + visited[VILLAGER_STATE_EAT_FOOD_AT_HOME] > 0 && pit_food1 < pit_food0, msg);
        CHECK(food1 != food0, "food drains (sub_6EACC0)");

        // The food job (sub_6E9100): empty the village's store and the Food
        // desire rises; villagers go fishing at the town's farms (55/56) and
        // bring the catch back (31/32).
        Town* village = level::FindTown(w, 0);
        uint32_t farms = 0;
        for (Town* t : w.towns) farms += t->fish_farms.count;
        if (pit) pit->RemoveResource(static_cast<RESOURCE_TYPE>(0), pit->GetResource(static_cast<RESOURCE_TYPE>(0)), nullptr, nullptr);
        std::map<int, int> job;
        uint32_t most_fishers = 0;
        for (int turn = 0; turn < 3000; ++turn) {
            level::Process(w);
            for (auto& p : start) ++job[p.first->action.top_state];
            for (LHNode* n = village->fish_farms.head; n; n = n->next) {
                const uint32_t c = static_cast<FishFarm*>(n->obj)->villagers.count;
                if (c > most_fishers) most_fishers = c;
            }
        }
        const uint32_t pit_food2 = pit ? pit->GetResource(static_cast<RESOURCE_TYPE>(0)) : 0;
        printf("      %u fish farms (village %u); store emptied: Food desire %.3f; villager-turns fishing %d, at the store %d;"
               " most fishermen at one farm %u; store food now %u\n",
               farms, village->fish_farms.count, village->desire.desire[0],
               job[VILLAGER_STATE_FISHING], job[VILLAGER_STATE_ARRIVES_AT_STORAGE_PIT_FOR_DROP_OFF], most_fishers, pit_food2);
        CHECK(farms == 13, "13 fish farms on their towns' lists (sub_502970)");
        std::snprintf(msg, sizeof msg, "with the store empty, villagers fish (%d villager-turns) and land the catch in the store (%u food)",
                      job[VILLAGER_STATE_FISHING], pit_food2);
        CHECK(job[VILLAGER_STATE_FISHING] > 0 && pit_food2 > 0, msg);
        CHECK(created == 0, "no villager is still in Created (85) after its timer");
        CHECK(moved > 0 && inside > 0, "villagers walk, and some reach home and go inside");
    }

    printf(g_fail ? "\n%d FAILED\n" : "\nall passed\n", g_fail);
    return g_fail ? 1 : 0;
}
