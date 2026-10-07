// test_level — Land 1 through the native level loader, headless: the towns,
// their abodes and housed villagers come out linked, and the world survives
// simulation turns. Needs game_data/ (Land1.txt, info.dat); skips without it.
#include <black/Abode.h>
#include <black/BigForest.h>
#include <black/BuildingSite.h>
#include <black/Field.h>
#include <black/Fire.h>
#include <black/Forest.h>
#include <black/PlannedMultiMapFixed.h>
#include <black/SpellCast.h>
#include <black/FishFarm.h>
#include <black/InfoDat.h>
#include <black/LevelLoader.h>
#include <black/Terrain.h>
#include <black/Town.h>
#include <black/Villager.h>
#include "lnd_loader.h"
#include "miracles.h"
#include <black/Gesture.h>

#include <cmath>
#include <black/Creature.h>
#include <black/CreatureBrain.h>
#include <black/CreaturePhysical.h>
#include <black/LandFeatures.h>
#include <black/EntityFactory.h>
#include <black/FishFarm.h>
#include <black/CreatureMindFile.h>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <vector>
#include <cstring>
#include <string>

extern uint32_t g_game_turn;  // LevelLoader.cpp
static int g_fail = 0;
#define CHECK(cond, msg) do { if (!(cond)) { printf("FAIL: %s\n", msg); ++g_fail; } \
                              else printf("ok  : %s\n", msg); } while (0)

int main() {
    std::setvbuf(stdout, nullptr, _IONBF, 0);  // unbuffered, so a hang shows where it is
    const char* roots[] = {"game_data/", "../game_data/", "../../game_data/", "../../../game_data/"};
    std::string root;
    for (const char* r : roots)
        if (infodat::Load((std::string(r) + "info.dat").c_str())) { root = r; break; }
    if (root.empty()) { printf("note: game_data not reachable; skipped\n"); return 0; }

    // The real landscape, for the drinking-water search (cell flags).
    static bw::Landscape land;
    if (bw::LoadLND(root + "Land1.lnd", land)) {
        g_cell_flags_func = [](uint32_t cx, uint32_t cz) { return bw::LandscapeCellFlags(land, cx, cz); };
        g_cell_altitude_func = [](uint32_t cx, uint32_t cz) { return bw::LandscapeCellAltitude(land, cx, cz); };
    }

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
    char msg[320];
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

        // Villagers build it (the Abodes / To_Build handlers, states 39-41):
        // wood from the store to the site's pile, and the pile into the hut.
        if (hut) {
            uint32_t most_builders = 0, most_pile = 0, stats_before = t4->stats.field_0x44;
            int turn = 0;
            for (; turn < 20000 && !hut->IsBuilt(); ++turn) {
                level::Process(w);
                if (site->builders > most_builders) most_builders = site->builders;
                if (site->pile_wood > most_pile) most_pile = site->pile_wood;
            }
            Object* pit4 = reinterpret_cast<Object*>(t4->storage_pit_list);
            std::snprintf(msg, sizeof msg, "town 4 builds the hut: %.0f%% after %d turns; up to %u builders, %u wood on the pile;"
                          " Abodes desire %.2f, To_Build %.2f; store wood %u; abodes counted %u -> %u",
                          hut->percent_built * 100.0f, turn, most_builders, most_pile, t4->desire.desire[5], t4->desire.desire[9],
                          pit4 ? pit4->GetResource(static_cast<RESOURCE_TYPE>(1)) : 0, stats_before, t4->stats.field_0x44);
            CHECK(most_builders > 0 && hut->percent_built > 0.0f, msg);
        }
    }

    // A resource miracle's drops (SpellResource vslot 331 -> sub_618E10):
    // food (magic 15) and wood (magic 21) cast on the village's storage pit
    // go into it.
    {
        Town* v0 = level::FindTown(w, 0);
        Object* pit = reinterpret_cast<Object*>(v0->storage_pit_list);
        const spell::Drop f1 = spell::ResourceDrop(15, true), f2 = spell::ResourceDrop(15, false);
        const spell::Drop w1 = spell::ResourceDrop(21, true), w2 = spell::ResourceDrop(21, false);
        const uint32_t food0 = pit->GetResource(static_cast<RESOURCE_TYPE>(0)), wood0 = pit->GetResource(static_cast<RESOURCE_TYPE>(1));
        const uint32_t left_f = spell::DropResource(f1.resource, f1.amount, pit->coords, {pit});
        const uint32_t left_w = spell::DropResource(w1.resource, w1.amount, pit->coords, {pit});
        std::snprintf(msg, sizeof msg, "food miracle drops %u then %u (resource %d), wood %u then %u (resource %d); on the pit: food %u -> %u, wood %u -> %u",
                      f1.amount, f2.amount, f1.resource, w1.amount, w2.amount, w1.resource, food0,
                      pit->GetResource(static_cast<RESOURCE_TYPE>(0)), wood0, pit->GetResource(static_cast<RESOURCE_TYPE>(1)));
        CHECK(f1.resource == 0 && w1.resource == 1 && f1.amount > 0 && w1.amount > 0 && !left_f && !left_w &&
              pit->GetResource(static_cast<RESOURCE_TYPE>(0)) == food0 + f1.amount &&
              pit->GetResource(static_cast<RESOURCE_TYPE>(1)) == wood0 + w1.amount, msg);
        pit->RemoveResource(static_cast<RESOURCE_TYPE>(0), f1.amount, nullptr, nullptr);  // leave the rest of the test as it was
        pit->RemoveResource(static_cast<RESOURCE_TYPE>(1), w1.amount, nullptr, nullptr);
    }

    // The viewer's hand (viewer/miracles.cpp): a spiral, then Food's gesture
    // (1, 3), drawn as mouse strokes from the templates, then a click on the
    // village's storage pit casts it there.
    {
        Town* v0 = level::FindTown(w, 0);
        Object* pit = reinterpret_cast<Object*>(v0->storage_pit_list);
        gesture::Templates t;
        const bool ok = miracles::Init(root) && t.Load(root + "Gestures.jty");
        auto draw = [&](int id) {
            for (const gesture::Data& d : t.all) {
                if (d.id != id) continue;
                miracles::StrokeBegin();
                for (int i = 0; i + 1 < d.count; ++i) {
                    const float ax = 100 + d.pts[i].x * 200, ay = 100 + d.pts[i].y * 200;
                    const float bx = 100 + d.pts[i + 1].x * 200, by = 100 + d.pts[i + 1].y * 200;
                    const float len = std::sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay));
                    const int steps = len > 20 ? static_cast<int>(len / 20) : 1;
                    for (int s = 0; s < steps; ++s) miracles::StrokePoint(ax + (bx - ax) * s / steps, ay + (by - ay) * s / steps);
                }
                miracles::StrokePoint(100 + d.pts[d.count - 1].x * 200, 100 + d.pts[d.count - 1].y * 200);
                miracles::StrokeEnd(640.0f / 480.0f);
                // Some curved drawings do not survive this coarse sampling;
                // try the gesture's next drawing.
                if (miracles::Status().rfind("not recognised", 0) != 0) return;
            }
        };
        draw(1);
        draw(3);
        const bool holding = miracles::Holding();
        const uint32_t food0 = pit->GetResource(static_cast<RESOURCE_TYPE>(0));
        const std::string r = miracles::Cast(w, MetresOf(pit->coords.x), MetresOf(pit->coords.z));
        const uint32_t food1 = pit->GetResource(static_cast<RESOURCE_TYPE>(0));
        std::snprintf(msg, sizeof msg, "the hand draws spiral + Food and casts on the pit: %s; food %u -> %u", r.c_str(), food0, food1);
        CHECK(ok && holding && food1 > food0, msg);
        pit->RemoveResource(static_cast<RESOURCE_TYPE>(0), food1 - food0, nullptr, nullptr);

        // Heal (spiral + 13) on a hurt villager: the effect (DETAIL_MAGIC_EFFECT_INFO,
        // heal [3] = 1 over 2 m) through vslot 371 raises its life.
        Villager* hurt = nullptr;
        for (auto& s : w.objects) if (s.command == "CREATE_VILLAGER_POS") { hurt = static_cast<Villager*>(s.obj); break; }
        hurt->SetLife(0.3f);
        draw(1);
        draw(13);
        const std::string rh = miracles::Cast(w, MetresOf(hurt->coords.x), MetresOf(hurt->coords.z));
        std::snprintf(msg, sizeof msg, "the hand draws spiral + Heal and casts on a hurt villager: %s; its life 0.30 -> %.2f", rh.c_str(), hurt->GetLife());
        CHECK(hurt->GetLife() > 0.3f, msg);

        // Water (spiral + 20) on an unplanted field plants it full (sub_4FF8D0).
        Field* bare = static_cast<Field*>(v0->field_list.head->obj);
        const int crops0 = bare->field_0xcc;
        draw(1);
        draw(20);
        const std::string rw = miracles::Cast(w, MetresOf(bare->coords.x), MetresOf(bare->coords.z));
        const int active = spell::ActiveCount();
        int turns = 0;
        for (; spell::ActiveCount() && turns < 200; ++turns) level::Process(w);
        std::snprintf(msg, sizeof msg, "the hand draws spiral + Water and casts on a field: %s, %d spell(s) for %d turns; crops %d -> %d",
                      rw.c_str(), active, turns, crops0, bare->field_0xcc);
        CHECK(active == 1 && turns >= 59 && turns <= 61 && crops0 == 0 && bare->field_0xcc > 30, msg);  // 6 s at 10 turns a second
        bare->field_0xcc = 0;  // leave the rest of the test as it was

        // Fire (Fire.cpp, sub_6C52A0): heat a hut past its ignition point; it
        // burns, losing life, and heats its neighbours; Water's effect
        // (value [0] = -4000) puts it out.
        Abode* hut = nullptr;
        for (Abode* a = reinterpret_cast<Abode*>(v0->abode_list.head); a; a = a->next)
            if (a != reinterpret_cast<Abode*>(v0->storage_pit_list) && a != reinterpret_cast<Abode*>(v0->town_centre)) { hut = a; break; }
        const float life0 = hut->GetLife();
        // One hit of heat 1000 warms a hut (capacity 2000) by only 5 degrees
        // (10 x 1000 / 2000); a fire spell's particles keep hitting. Here, a
        // hit a turn for 40 turns.
        for (int turn = 0; turn < 40; ++turn) { fire::AddHeat(hut, 1000.0f, nullptr); level::Process(w); }
        const float t0 = fire::Temperature(hut);
        int most = 0;
        for (int turn = 0; turn < 100; ++turn) { level::Process(w); most = std::max(most, fire::Count()); }
        const float t1 = fire::Temperature(hut), life1 = hut->GetLife();
        draw(1);
        draw(20);
        // Water rains on it for 60 turns, a drop a turn within 0.3-4.5 m; a
        // drop that lands on the hut cools it by about 21 degrees.
        miracles::Cast(w, MetresOf(hut->coords.x), MetresOf(hut->coords.z));
        for (int turn = 0; turn < 120; ++turn) level::Process(w);
        std::snprintf(msg, sizeof msg, "a hut set alight burns (%.0f -> %.0f degrees, ignition %.0f; life %.2f -> %.2f; up to %d fires), and Water puts it out (now %.0f degrees, %d fires)",
                      t0, t1, fire::Ignition(hut), life0, life1, most, fire::Temperature(hut), fire::Count());
        CHECK(t0 >= fire::Ignition(hut) && life1 < life0 && fire::Temperature(hut) < fire::Ignition(hut), msg);
        fire::Clear();
        hut->SetLife(life0);
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
        uint32_t most_fishers = 0, landed = 0;
        for (int turn = 0; turn < 3000; ++turn) {
            const uint32_t before = pit ? pit->GetResource(static_cast<RESOURCE_TYPE>(0)) : 0;
            level::Process(w);
            const uint32_t after = pit ? pit->GetResource(static_cast<RESOURCE_TYPE>(0)) : 0;
            if (after > before) landed += after - before;  // what came in (villagers also eat from it)
            for (auto& p : start) ++job[p.first->action.top_state];
            for (LHNode* n = village->fish_farms.head; n; n = n->next) {
                const uint32_t c = static_cast<FishFarm*>(n->obj)->villagers.count;
                if (c > most_fishers) most_fishers = c;
            }
        }
        const uint32_t pit_food2 = pit ? pit->GetResource(static_cast<RESOURCE_TYPE>(0)) : 0;
        printf("      %u fish farms (village %u); store emptied: Food desire %.3f; villager-turns fishing %d, at the store %d;"
               " most fishermen at one farm %u; food landed %u, store now %u\n",
               farms, village->fish_farms.count, village->desire.desire[0],
               job[VILLAGER_STATE_FISHING], job[VILLAGER_STATE_ARRIVES_AT_STORAGE_PIT_FOR_DROP_OFF], most_fishers, landed, pit_food2);
        CHECK(farms == 13, "13 fish farms on their towns' lists (sub_502970)");
        std::snprintf(msg, sizeof msg, "with the store empty, villagers fish (%d villager-turns) and land the catch in the store (%u food)",
                      job[VILLAGER_STATE_FISHING], landed);
        CHECK(job[VILLAGER_STATE_FISHING] > 0 && landed > 0, msg);

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

    {
        // A creature in the world. Khazar's shipped mind, hungry and curious,
        // placed beside a village: the agenda (sub_4D0630) over what it can see,
        // with the objects' own predicates and his opinion trees. His innate
        // lesson rates villagers +0.6 for hunger, but whether he can eat one is
        // CanCreatureEatMe (sub_4C5EA0), which needs it to fit in his hand: his
        // reach is measured off his 3D object's meshes (sub_4CE650), which core
        // does not load -- so the villager is out, and with a fish farm in reach
        // he goes fishing (FishAndEat, 155). The next block gives him a hand.
        Villager* near = nullptr;
        for (const level::Spawned& s : w.objects)
            if (auto* v = dynamic_cast<Villager*>(s.obj); v && !v->IsDead()) { near = v; break; }
        creature::CreatureMind khazar;
        const bool mind_ok = creature::LoadCreatureMindFile((root + "CreatureMind/KhazarCreature").c_str(), khazar);
        EntityCreateParams cp{};
        cp.world_x = MetresOf(near ? near->coords.x : 0) + 20.0f;
        cp.world_z = MetresOf(near ? near->coords.z : 0);
        cp.scale = 5.0f;
        auto* khazar_body = static_cast<Creature*>(EntityFactory::CreateCreature(cp));
        creature::CreatureBrain brain;
        const bool ok = near && mind_ok && khazar_body && brain.Init(khazar_body, khazar);
        CHECK(ok, "Khazar's mind drives a creature placed 20 m from a villager");
        if (ok) {
            // His mind drives all forty desires now (sub_4BE5B0), fed by his body
            // (sub_4CF980). He is fed (energy 0.997 in the mind); starve him to
            // 0.4 and hunger rises on its own as HUNGER_FROM_ENERGY passes its
            // threshold.
            brain.body.energy = 0.4f;
            // The game's camera (sub_467190 with no player), 40 m east of him.
            brain.camera = MapCoords(khazar_body->coords.x + static_cast<int32_t>(40 * kMapUnitsPerMetre), khazar_body->coords.z, 0.0f);
            int pointed = 0;
            uint32_t camera_done = 0;
            float energy_before = 0.0f, energy_after = 0.0f, hunger_before = 0.0f;
            int turn = 0, fish_start = -1, fish_turns = 0;
            float sun_heading = 0.0f, sun_want = 0.0f;
            bool looked = false;
            std::string log;
            uint32_t done = 0;
            for (; turn < 4000 && brain.last_desire != 4; ++turn) {
                level::Process(w);
                std::vector<Object*> seen;
                for (const level::Spawned& s : w.objects) seen.push_back(s.obj);
                const float energy = brain.body.energy;
                const uint32_t meals = brain.body.meals;
                hunger_before = brain.desires.value[4];
                if (brain.Action() != 155) fish_start = -1;
                else if (fish_start < 0) fish_start = turn;
                const uint32_t before_tick = brain.completed;
                brain.Tick(seen);
                if (brain.Action() == 168 && brain.subactions.count && brain.hand.anim == 1000) ++pointed;
                if (brain.completed != before_tick && brain.last_action == 168) ++camera_done;
                if (brain.body.meals != meals) energy_before = energy, energy_after = brain.body.energy;
                if (brain.completed != done && fish_start >= 0) fish_turns = turn - fish_start + 1;
                if (brain.completed != done && brain.last_action == 193 && !looked) {
                    looked = true;
                    sun_heading = khazar_body->GetYAngle();
                    sun_want = std::atan2(-50000.0f - MetresOf(khazar_body->coords.x), -50000.0f - MetresOf(khazar_body->coords.z));
                }
                if (brain.completed != done) {
                    done = brain.completed;
                    if (log.size() < 120) log += " " + std::to_string(brain.last_action) + "/" + std::to_string(brain.last_desire);
                }
                if (std::getenv("BRAIN_TRACE") && turn % 200 == 0)
                    printf("      t%4d energy %.3f hunger %.3f action %u desire %u done %u\n", turn, brain.body.energy,
                           brain.desires.value[4], brain.Action(), brain.Desire(), brain.completed);
            }
            const bool at_farm = dynamic_cast<FishFarm*>(brain.last_target) != nullptr;
            std::snprintf(msg, sizeof msg,
                          "starved, he lives by his desires (%s) and on turn %d fishes at %s: energy %.3f -> %.3f, hunger %.2f -> %.3f",
                          log.c_str(), turn, at_farm ? "a fish farm" : "?", energy_before, energy_after, hunger_before,
                          brain.desires.value[4]);
            // One fish (POT_INFO_FISH, food 20) over min(growth 0.32, 0.8) x 1000
            // (sub_4DF5A0); its digestion takes as much off hunger, clamped to [0, 1]
            // (sub_4DF830; this desire's maximum is above 1),
            // and FishAndEat's record then scales it by 0.01 (sub_4BE680).
            const float fish = 20.0f / (std::min(brain.body.growth, 0.8f) * brain.body_info.digest);
            CHECK(brain.last_desire == 4 && brain.last_action == 155 && at_farm &&
                      std::fabs(energy_after - (energy_before + fish)) < 2e-4f &&
                      std::fabs(brain.desires.value[4] - std::clamp(hunger_before - fish, 0.0f, 1.0f) * 0.01f) < 1e-4f, msg);
            // The action is its four sub-actions (sub_4932E0), run one step at a
            // time (sub_4DE180): the walk, the fish, the pickup clip, the eating clip.
            const creature::SubActionAgenda& sa = brain.subactions;
            std::snprintf(msg, sizeof msg, "FishAndEat runs as sub-actions over %d turns (%u stopped), the hand empty after",
                          fish_turns, brain.stopped);
            CHECK(fish_turns > 32 && !brain.hand.holding && !brain.hand.Busy() && sa.count == 0, msg);
            // LookAtSun (sub_499520) turns him toward (-50000, -50000) m (sub_4E0980).
            std::snprintf(msg, sizeof msg, "LookAtSun turns him to face its point: heading %.3f, wanted %.3f", sun_heading, sun_want);
            CHECK(looked && std::fabs(std::remainder(sun_heading - sun_want, 6.2831855f)) <= 0.3927f, msg);
            // PointAtCamera (sub_4976C0) points at the camera for max(1 s, 10 turns) (sub_4E5520).
            std::snprintf(msg, sizeof msg, "PointAtCamera points at the camera: %u done, %d turns pointing", camera_done, pointed);
            CHECK(camera_done > 0 && pointed >= 10 * static_cast<int>(camera_done), msg);
        }
    }

    {
        // The same, with a 3D object whose hand reaches 5 m (sub_46E600) and a
        // 1 m radius. Core does not load the creature's meshes, so these stand
        // in for what sub_4CE650 measures; with them a villager fits in his
        // hand (sub_4C4E00), and CanCreatureEatMe (sub_4C5EA0) lets him eat it.
        Villager* prey = nullptr;
        for (const level::Spawned& s : w.objects)
            if (auto* v = dynamic_cast<Villager*>(s.obj); v && !v->IsDead() && v->IsObjectInMap_0()) { prey = v; break; }
        creature::CreatureMind khazar;
        const bool mind_ok = creature::LoadCreatureMindFile((root + "CreatureMind/KhazarCreature").c_str(), khazar);
        EntityCreateParams cp{};
        cp.world_x = MetresOf(prey ? prey->coords.x : 0) + 20.0f;
        cp.world_z = MetresOf(prey ? prey->coords.z : 0);
        cp.scale = 5.0f;
        auto* body = static_cast<Creature*>(EntityFactory::CreateCreature(cp));
        char* c3d = static_cast<char*>(std::calloc(1, 0x57B8));  // LH3DCreature
        auto put = [&](size_t off, float v) { std::memcpy(c3d + off, &v, sizeof v); };
        put(0x90, 1.0f);    // size_1: weight (8.33)^3 x 100
        put(0x94, 1.0f);    // size_2
        put(0x5228, 1.0f);  // radius
        for (int i = 0; i < 4; ++i) put(0x49C8 + 12 * i, 3.0f), put(0x49C8 + 12 * i + 8, 4.0f);  // the hand at (3, 0, 4)
        if (body && body->physical) body->physical->creature_3d = reinterpret_cast<LH3DCreature*>(c3d);
        creature::CreatureBrain brain;
        const bool ok = prey && mind_ok && body && body->physical && brain.Init(body, khazar);
        std::snprintf(msg, sizeof msg, "a 3D hand reaching %.2f m (sub_46E600), and a villager of weight %.3f fits in it (CanCreatureEatMe)",
                      body ? body->HandReach() : 0.0f, prey ? prey->GetWeight() : 0.0f);
        CHECK(ok && std::fabs(body->HandReach() - 5.0f) < 1e-4f && prey->CanCreatureEatMe(body), msg);
        if (ok) {
            brain.body.energy = 0.4f;
            std::string log;
            uint32_t done = 0;
            int turn = 0, picked = -1, eaten = -1, sat = -1, drank = -1;
            float sat_water = 1e9f, thirst = 1.0f;
            // Metres from him to the nearest water cell within 60 m.
            auto to_water = [&] {
                float best = 1e9f;
                const int cx = body->coords.x.split.map, cz = body->coords.z.split.map;
                for (int x = cx - 6; x <= cx + 6; ++x)
                    for (int z = cz - 6; z <= cz + 6; ++z) {
                        const int32_t f = x >= 0 && z >= 0 ? g_cell_flags_func(x, z) : -1;
                        if (f < 0 || !(f & 0x10)) continue;
                        const float dx = MetresOf(body->coords.x) - x * 10.0f, dz = MetresOf(body->coords.z) - z * 10.0f;
                        best = std::min(best, std::sqrt(dx * dx + dz * dz));
                    }
                return best;
            };
            float hunger_before = 0.0f, hunger_after = 0.0f, energy_before = 0.0f, energy_after = 0.0f;
            Object* victim = nullptr;
            for (; turn < 8000 && (eaten < 0 || sat < 0 || drank < 0); ++turn) {
                level::Process(w);
                std::vector<Object*> seen;
                for (const level::Spawned& s : w.objects) seen.push_back(s.obj);
                const float h = brain.desires.value[4], energy = brain.body.energy;
                const uint32_t meals = brain.body.meals;
                brain.Tick(seen);
                if (brain.body.meals != meals) energy_before = energy, energy_after = brain.body.energy;
                if (brain.Action() == 11 && brain.hand.holding && picked < 0) picked = turn, victim = brain.hand.held.object;
                if (brain.completed != done) {
                    done = brain.completed;
                    if (log.size() < 120) log += " " + std::to_string(brain.last_action) + "/" + std::to_string(brain.last_desire);
                    if (brain.last_action == 11 && eaten < 0) eaten = turn, hunger_before = h, hunger_after = brain.desires.value[4];
                    if (brain.last_action == 218 && sat < 0) sat = turn, sat_water = to_water();
                    if (brain.last_action == 55 && drank < 0) drank = turn, thirst = brain.body.dehydration;
                }
            }
            auto* v = dynamic_cast<Villager*>(victim);
            std::snprintf(msg, sizeof msg, "he lives by his desires (%s); EatAlive picks up a villager on turn %d and eats it on turn %d: hunger %.3f -> %.3f",
                          log.c_str(), picked, eaten, hunger_before, hunger_after);
            CHECK(eaten > picked && picked > 0 && v && v->IsDead() && hunger_after < hunger_before && !brain.hand.holding, msg);
            // The meal is the villager's GetFoodValue(3) (sub_401740: info +104),
            // eaten when the clip starts (sub_4DF5A0), as with the fish.
            float food = 0.0f;
            if (v && v->info) std::memcpy(&food, reinterpret_cast<const char*>(v->info) + 104, 4);
            std::snprintf(msg, sizeof msg, "the villager is a meal of %.1f (GetFoodValue %.1f): energy %.3f -> %.3f",
                          food, v ? v->GetFoodValue(static_cast<FOOD_TYPE>(3)) : 0.0f, energy_before, energy_after);
            CHECK(v && food > 0.0f && v->GetFoodValue(static_cast<FOOD_TYPE>(3)) == food && energy_after > energy_before, msg);
            // SitDownOnBeach (sub_494450) rests by the nearest water block's
            // first water cell; DrinkFromTheSea (sub_4895E0) ends in Drink
            // (sub_4E4110), which slakes his thirst.
            std::snprintf(msg, sizeof msg, "he sits down by the water on turn %d, %.1f m from it (height %.0f), and drinks on turn %d: dehydration %.3f",
                          sat, sat_water, body->GetHeight(), drank, thirst);
            CHECK(sat > 0 && sat_water <= body->GetHeight() + 10.0f && drank > 0 && thirst < 1e-3f, msg);

            // Two handlers his desires do not pick here, run directly: the plan
            // is set, its handler queues the sub-actions (sub_4B6CA0), and the
            // runner steps them once a turn (sub_4DE180).
            auto run = [&](uint32_t action, auto&& each_turn) {
                brain.agenda.plans.current_action = action;
                brain.agenda.plans.current_desire = 38;
                const uint32_t before = brain.completed, stops = brain.stopped;
                if (!brain.StartAction(action)) return -1;
                for (int t = 0; t < 3000; ++t) {
                    level::Process(w);
                    brain.RunSubActions();
                    each_turn();
                    if (brain.completed != before) return t + 1;
                    if (brain.stopped != stops) return -1;
                }
                return -1;
            };
            auto metres = [](const MapCoords& a, const MapCoords& b) {
                const float dx = MetresOf(a.x) - MetresOf(b.x), dz = MetresOf(a.z) - MetresOf(b.z);
                return std::sqrt(dx * dx + dz * dz);
            };
            // GoToHillAndWalkAlongRidge (sub_485B50): to the nearest hill's top,
            // then eight points 15 m round it.
            MapCoords top;
            const bool hill = land::Features().Find(land::kHill, body->coords, &top, false, true);
            float nearest_top = 1e9f;
            const int ridge = run(27, [&] { nearest_top = std::min(nearest_top, metres(body->coords, top)); });
            const MapCoords last = MapCoordsFromMetres(MetresOf(top.x) + 15.0f * std::cos(7 * 0.785398163f),
                                                       MetresOf(top.z) + 15.0f * std::sin(7 * 0.785398163f));
            std::snprintf(msg, sizeof msg, "GoToHillAndWalkAlongRidge climbs the nearest hill (cell %u, %u) to %.1f m of its top and walks round it in %d turns, ending %.1f m from the last point",
                          top.x.split.map, top.z.split.map, nearest_top, ridge, metres(body->coords, last));
            CHECK(hill && ridge > 0 && nearest_top <= 3.0f * body->GetHeight() + 1.0f &&
                      metres(body->coords, last) <= 2.0f * body->GetHeight() + 1.0f, msg);
            // TakeFishFromSeaToHome (sub_4A23B0): fish at the nearest farm, carry
            // it home, and put it down there (Discard, clip 97).
            body->field_0x1200 = MapCoordsFromMetres(MetresOf(body->coords.x) + 30.0f, MetresOf(body->coords.z));
            bool carried = false;
            const int home = run(259, [&] { carried |= brain.hand.holding && brain.hand.held.value == 20.0f; });
            std::snprintf(msg, sizeof msg, "TakeFishFromSeaToHome fishes, carries the fish home and puts it down in %d turns, %.1f m from home",
                          home, metres(body->coords, body->field_0x1200));
            CHECK(home > 0 && carried && !brain.hand.holding && brain.discarded.value == 20.0f &&
                      metres(body->coords, body->field_0x1200) <= body->GetHeight() + 1.0f, msg);
        }
    }

    if (g_cell_flags_func && g_cell_altitude_func) {
        // The creature's feature map (sub_4C1610) over Land 1: per 8 x 8-cell
        // block, its highest cell and which of the terrain tests it passes.
        const land::FeatureMap& fm = land::Features();
        int count[land::kNumFeatures] = {}, bad_hills = 0;
        for (int bx = 0; bx < 64; ++bx)
            for (int bz = 0; bz < 64; ++bz) {
                for (int f = 0; f < land::kNumFeatures; ++f) count[f] += fm.Has(static_cast<land::Feature>(f), bx, bz);
                if (!fm.Has(land::kHill, bx, bz)) continue;
                const float h = fm.regions[bx][bz].height;
                if (h <= fm.max_height * 0.5f) ++bad_hills;
                const int nb[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
                for (const auto& d : nb)
                    if (bx + d[0] >= 0 && bx + d[0] < 64 && bz + d[1] >= 0 && bz + d[1] < 64 && fm.regions[bx + d[0]][bz + d[1]].height > h) ++bad_hills;
            }
        std::snprintf(msg, sizeof msg, "the feature map: highest %.1f m; blocks with coast %d, water %d, hill %d, land %d (of 4096)",
                      fm.max_height, count[land::kCoast], count[land::kWater], count[land::kHill], count[land::kLand]);
        CHECK(count[land::kCoast] > 0 && count[land::kWater] > 0 && count[land::kHill] > 0 && count[land::kLand] > 0 &&
                  count[land::kWater] + count[land::kLand] >= 4096 && bad_hills == 0, msg);
        // The search (sub_4C1480) from the map's centre lands on a water cell.
        MapCoords from(256 << 16, 256 << 16, 0.0f), out;
        const bool found = fm.Find(land::kWater, from, &out, true, true);
        const int32_t f = found ? g_cell_flags_func(out.x.split.map, out.z.split.map) : 0;
        std::snprintf(msg, sizeof msg, "the nearest water from the map's centre is cell (%u, %u), flags 0x%X",
                      out.x.split.map, out.z.split.map, f);
        CHECK(found && (f < 0 || (f & 0x10)), msg);
    }

    printf(g_fail ? "\n%d FAILED\n" : "\nall passed\n", g_fail);
    return g_fail ? 1 : 0;
}
