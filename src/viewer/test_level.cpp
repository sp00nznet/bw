// test_level — Land 1 through the native level loader, headless: the towns,
// their abodes and housed villagers come out linked, and the world survives
// simulation turns. Needs game_data/ (Land1.txt, info.dat); skips without it.
#include <black/Abode.h>
#include <black/BigForest.h>
#include <black/BuildingSite.h>
#include <black/Field.h>
#include <black/Forest.h>
#include <black/PlannedMultiMapFixed.h>
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

extern uint32_t g_game_turn;  // LevelLoader.cpp
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

    // CREATE_PLANNED_ABODE x6: plans on their towns' lists (sub_6CFFB0),
    // scored by the planner (sub_6CD9F0).
    {
        uint32_t planned = 0;
        for (Town* t : w.towns) {
            planned += t->planned_list.count;
            for (auto* p = static_cast<PlannedMultiMapFixed*>(t->planned_list.head); p; p = p->next)
                printf("      town %u plans %s: want %.3f (base %.3f); room %u, homeless %u, people %d\n", t->field_0x5b4,
                       infodat::DebugName(infodat::DETAIL_ABODE_INFO, static_cast<uint32_t>((reinterpret_cast<const char*>(p->info) -
                           static_cast<const char*>(infodat::Element(infodat::DETAIL_ABODE_INFO, 0))) / 456)),
                       t->PlanScore(p->info, 0), *reinterpret_cast<const float*>(reinterpret_cast<const char*>(p->info) + 276),
                       t->stats.field_0x4c, reinterpret_cast<const uint32_t&>(t->homeless_list.last),
                       t->stats.num_adults + t->stats.num_children);
        }
        CHECK(planned == 6, "six planned abodes on their towns' lists");

        // The planner (sub_6CE790(2)) starts nothing while there is room to
        // spare. With town 4's spare room taken away it starts its best-wanted
        // hut: an abode with nothing built, on the town's abode list, with a
        // site on the town's site list.
        Town* t4 = level::FindTown(w, 4);
        CHECK(t4->PlanBuilding(2) == nullptr, "town 4 starts nothing while it has room (sub_6CD9F0 case 2)");
        const uint32_t room = t4->stats.field_0x4c, plans = t4->planned_list.count, abodes4 = t4->abode_list.count;
        t4->stats.field_0x4c = 0;
        BuildingSite* site = t4->PlanBuilding(2);
        t4->stats.field_0x4c = room;
        Abode* hut = site ? site->root_building->CastAbode() : nullptr;
        std::snprintf(msg, sizeof msg, "without spare room town 4 starts a hut: site %s, %.0f%% built, abodes %u -> %u, plans %u -> %u, sites %u",
                      site ? "yes" : "no", hut ? hut->percent_built * 100.0f : -1.0f, abodes4, t4->abode_list.count, plans,
                      t4->planned_list.count, t4->building_site_list.count);
        CHECK(hut && hut->percent_built == 0.0f && hut->GetTown() == t4 && t4->abode_list.count == abodes4 + 1 &&
              t4->planned_list.count == plans - 1 && t4->building_site_list.Has(site) && hut->building_site == site, msg);
    }

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

        // Farming (67-69, Field sub_4FF9C0): fields get planted, grow, and are
        // dug up. Their state over the same run:
        {
            uint32_t fields = 0, planted = 0, crops = 0;
            float most_growth = 0, food_in = 0;
            for (LHNode* n = village->field_list.head; n; n = n->next) {
                auto* f = static_cast<Field*>(n->obj);
                ++fields;
                planted += f->GetPercentFull() >= 1.0f;
                crops += f->field_0xcc;
                if (f->growth > most_growth) most_growth = f->growth;
                food_in += f->food;
            }
            const char* ft = reinterpret_cast<const char*>(static_cast<Field*>(village->field_list.head->obj)->type_info);
            auto F = [&](int off) { float x; std::memcpy(&x, ft + off, 4); return x; };
            int32_t most_farmers;
            std::memcpy(&most_farmers, ft + 308, 4);
            printf("      field type: crops %.0f, ripe %.1f, full %.1f, rates %.3f/%.3f, food %.1f, farmers %d\n",
                   F(296), F(288), F(292), F(312), F(316), F(304), most_farmers);
            printf("      village fields %u: %u fully planted, %u crops, most growth %.1f, food in fields %.1f;"
                   " villager-turns at the farm %d, planting %d, digging %d\n",
                   fields, planted, crops, most_growth, food_in, job[VILLAGER_STATE_FARMER_ARRIVES_AT_FARM],
                   job[VILLAGER_STATE_FARMER_PLANTS_CROP], job[VILLAGER_STATE_FARMER_DIGS_UP_CROP]);
            std::snprintf(msg, sizeof msg, "farmers plant the village's fields (%u crops) and the crops grow (to %.1f)", crops, most_growth);
            CHECK(job[VILLAGER_STATE_FARMER_PLANTS_CROP] > 0 && crops > 0 && most_growth > 0.0f, msg);

            // A crop is dug up only at full growth (+292, sub_4FFBD0); run on
            // until the first fields get there.
            int dug = 0;
            for (int turn = 0; turn < 6000 && !dug; ++turn) {
                level::Process(w);
                for (auto& p : start) dug += p.first->action.top_state == VILLAGER_STATE_FARMER_DIGS_UP_CROP;
            }
            for (int turn = 0; turn < 500; ++turn) {
                level::Process(w);
                for (auto& p : start) dug += p.first->action.top_state == VILLAGER_STATE_FARMER_DIGS_UP_CROP;
            }
            std::snprintf(msg, sizeof msg, "full-grown crops are dug up (%d villager-turns digging by game turn %u)", dug, g_game_turn);
            CHECK(dug > 0, msg);
        }
        // The wood job (sub_6EE260): with the store's wood gone, villagers take
        // wood from the town's big forests (53) and bring it back (31/32).
        {
            float wood0 = 0, wood1 = 0;
            for (Forest* f : w.forests) wood0 += f->big_forest->GetWoodValue();
            if (pit) pit->RemoveResource(static_cast<RESOURCE_TYPE>(1), pit->GetResource(static_cast<RESOURCE_TYPE>(1)), nullptr, nullptr);
            int at_forest = 0;
            for (int turn = 0; turn < 3000; ++turn) {
                level::Process(w);
                for (auto& p : start) at_forest += p.first->action.top_state == VILLAGER_STATE_ARRIVES_AT_BIG_FOREST;
            }
            for (Forest* f : w.forests) wood1 += f->big_forest->GetWoodValue();
            const uint32_t pit_wood = pit ? pit->GetResource(static_cast<RESOURCE_TYPE>(1)) : 0;
            printf("      %zu big forests, the village collects %u; Wood desire %.3f; forests' wood %.0f -> %.0f; store wood %u\n",
                   w.forests.size(), village->forests.count, village->desire.desire[1], wood0, wood1, pit_wood);
            CHECK(w.forests.size() == 3 && village->forests.count > 0, "three big forests (CREATE_NEW_BIG_FOREST), the village's in its list (sub_6D1750)");
            std::snprintf(msg, sizeof msg, "villagers fetch wood from the big forests (%d villager-turns there) into the store (%u)", at_forest, pit_wood);
            CHECK(at_forest > 0 && wood1 < wood0 && pit_wood > 0, msg);
        }
        CHECK(created == 0, "no villager is still in Created (85) after its timer");
        CHECK(moved > 0 && inside > 0, "villagers walk, and some reach home and go inside");
    }

    printf(g_fail ? "\n%d FAILED\n" : "\nall passed\n", g_fail);
    return g_fail ? 1 : 0;
}
