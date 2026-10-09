// LevelLoader — land scripts into a bw_core world. Each handler follows its
// case in the original dispatcher (sub_6AD5E0); docs/level-loader.md has the
// table of commands, what they create, and where this departs from it.
#include <black/LevelLoader.h>

#include <black/Abode.h>
#include <black/EntityFactory.h>
#include <black/BigForest.h>
#include <black/Citadel.h>
#include <black/Creature.h>
#include <black/Field.h>
#include <black/Fire.h>
#include <black/SpellCast.h>
#include <black/Forest.h>
#include <black/FishFarm.h>
#include <black/InfoDat.h>
#include <black/LHRandom.h>
#include <black/Map.h>
#include <black/Living.h>
#include <black/PlannedAbode.h>
#include <black/PlannedTownCitadelHeart.h>
#include <black/Player.h>
#include <black/MultiMapFixed.h>
#include <black/Object.h>
#include <black/Terrain.h>
#include <black/Town.h>
#include <black/TownCentre.h>
#include <black/Villager.h>

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>

uint32_t g_game_turn = 0;  // the turn counter (game +2104060); level::Process advances it
namespace lh { uint32_t g_random_seed = 0; }  // game +2104056; ponytail: the start value is set by the game at runtime, not recovered

namespace level {
namespace {

// One argument as the original's parser stores it: every position has a
// string, an int and a float slot (a2 + 2048*k, +24576 + 4k, +24624 + 4k), and
// the handler reads whichever its command's signature says.
struct Arg {
    std::string s;
    int32_t n = 0;
    float f = 0;
};
using Args = std::vector<Arg>;

// "1865.61,2641.24" -> world x, z (sub_6B0630 reads the same text).
bool ParsePos(const std::string& s, float& x, float& z) {
    return std::sscanf(s.c_str(), "%f,%f", &x, &z) == 2;
}

bool ParseLine(const char* line, std::string& name, Args& args) {
    while (*line == ' ' || *line == '\t') ++line;
    const char* p = line;
    while ((*p >= 'A' && *p <= 'Z') || (*p >= '0' && *p <= '9') || *p == '_') ++p;
    if (p == line || *p != '(') return false;
    name.assign(line, p);
    args.clear();
    ++p;
    std::string tok;
    bool quoted = false, in_quotes = false;
    for (;; ++p) {
        const char c = *p;
        if (!c || c == '\r' || c == '\n') return false;  // unterminated: not a command
        if (c == '"') { in_quotes = !in_quotes; quoted = true; continue; }
        if (!in_quotes && (c == ',' || c == ')')) {
            if (!tok.empty() || quoted || c == ',') {
                Arg a;
                size_t b = tok.find_first_not_of(" \t"), e = tok.find_last_not_of(" \t");
                a.s = b == std::string::npos ? "" : tok.substr(b, e - b + 1);
                if (!quoted) { a.n = std::atoi(a.s.c_str()); a.f = static_cast<float>(std::atof(a.s.c_str())); }
                args.push_back(a);
            }
            tok.clear(); quoted = false;
            if (c == ')') return true;
            continue;
        }
        tok += c;
    }
}

// TRIBE_TYPE and PLAYER_NAME by their script spellings.
int TribeIndex(const std::string& s) {
    static const char* const k[] = {"CELTIC", "AFRICAN", "AZTEC", "JAPANESE", "INDIAN",
                                    "EGYPTIAN", "GREEK", "NORSE", "TIBETAN"};
    for (int i = 0; i < 9; ++i) if (s == k[i]) return i;
    return -1;
}
int PlayerIndex(const std::string& s) {
    static const char* const k[] = {"PLAYER_ONE", "PLAYER_TWO", "PLAYER_THREE", "PLAYER_FOUR",
                                    "PLAYER_FIVE", "PLAYER_SIX", "PLAYER_SEVEN", "NEUTRAL"};
    for (int i = 0; i < 8; ++i) if (s == k[i]) return i;
    return 7;
}

float WorldX(const Town* t) { return MetresOf(t->coords.x); }
float WorldZ(const Town* t) { return MetresOf(t->coords.z); }

// sub_5256C0, then sub_525710: the town with this id, else the nearest one.
Town* TownFor(const World& w, int32_t id, float x, float z) {
    if (Town* t = FindTown(w, static_cast<uint32_t>(id))) return t;
    Town* best = nullptr;
    float best_d = 0;
    for (Town* t : w.towns) {
        const float dx = WorldX(t) - x, dz = WorldZ(t) - z, d = dx * dx + dz * dz;
        if (!best || d < best_d) { best = t; best_d = d; }
    }
    return best;
}

struct Loader {
    World& w;

    Object* Make(EntityCategory cat, const std::string& cmd, float x, float z,
                 float angle, float scale, int index, const std::string& name = "") {
        EntityCreateParams p;
        p.world_x = x; p.world_z = z; p.angle = angle; p.scale = scale; p.mesh_id = -1;
        p.type_enum = index >= 0 ? static_cast<uint32_t>(index) : kNoInfo;
        p.type_name = name.c_str();
        Object* o = EntityFactory::CreateEntity(cat, p);
        if (o) w.objects.push_back({o, cmd, name, index});
        return o;
    }

    // case 2: sub_6CD070(pos, &TownInfo, player, tribe, 0, id)
    bool CreateTown(const Args& a) {
        float x, z;
        if (a.size() < 5 || !ParsePos(a[1].s, x, z)) return false;
        Town* t = new Town();
        const int tribe = TribeIndex(a[4].s);
        // The loader passes no name (sub_6CD070's a6 is 0 here).
        const int player = PlayerIndex(a[2].s);
        t->Construct(MapCoordsFromMetres(x, z), infodat::Element(infodat::DETAIL_TOWN_INFO, 0),
                     PlayerAt(static_cast<uint32_t>(player)), static_cast<uint8_t>(player),
                     static_cast<TRIBE_TYPE>(tribe < 0 ? 0 : tribe), nullptr,
                     static_cast<uint32_t>(a[0].n));
        w.towns.push_back(t);
        return true;
    }

    // case 3: sub_6CEC50(player, belief)
    bool SetTownBelief(const Args& a) {
        Town* t = a.size() >= 3 ? FindTown(w, static_cast<uint32_t>(a[0].n)) : nullptr;
        if (!t) return false;
        t->belief.SetBelief(static_cast<uint8_t>(PlayerIndex(a[1].s)), a[2].f);
        return true;
    }

    // case 5: town + 0x5F4 = 1 (AddVillagerToTown then refuses everyone)
    bool SetTownUninhabitable(const Args& a) {
        Town* t = a.empty() ? nullptr : FindTown(w, static_cast<uint32_t>(a[0].n));
        if (!t) return false;
        t->field_0x5f4 = 1;
        return true;
    }

    // cases 7 and 9: sub_401BA0(pos, info, town, angle, scale, food, wood, ...)
    bool CreateAbode(const std::string& cmd, const Args& a, bool town_centre) {
        float x, z;
        if (a.size() < 5 || !ParsePos(a[1].s, x, z)) return false;
        Town* town = TownFor(w, a[0].n, x, z);
        if (!town) return false;  // the original returns without creating it too
        Object* o = Make(ENTITY_CAT_ABODE, cmd, x, z, a[3].n * 0.001f, a[4].n * 0.001f, -1, a[2].s);
        Abode* abode = o ? o->CastAbode() : nullptr;
        if (!abode) return false;
        if (!town_centre && a.size() >= 7) {  // sub_401EB0: vtable +156 (AddResource) with food, then wood
            abode->AddResource(static_cast<RESOURCE_TYPE>(0), static_cast<uint32_t>(a[5].n), nullptr, false, abode->coords, 0);
            abode->AddResource(static_cast<RESOURCE_TYPE>(1), static_cast<uint32_t>(a[6].n), nullptr, false, abode->coords, 0);
        }
        abode->JoinTown(town);  // sub_401220's town half: list, index, drinking water
        // sub_401EB0 (after the resources below): a built abode is counted in its town.
        // case 9: the first town centre created becomes the town's (v1.0 town + 0x99C;
        // our header names that slot town_centre at 0x9A4).
        if (abode->IsBuilt()) abode->Activate();
        if (town_centre && !town->town_centre)
            town->town_centre = static_cast<TownCentre*>(abode);
        return true;
    }

    // case 8: (town, pos, abode, angle x 1000, scale x 1000, ...). A plan the
    // town may build later: sub_403D60 -> PlannedAbode (sub_403B80 /
    // sub_5F6940) at the tail of the town's planned list (sub_6CFFB0).
    // ponytail: a planned town centre (+288 == 0x404, sub_6D65A0) is kept as
    // a plain planned abode.
    bool CreatePlannedAbode(const Args& a) {
        float x, z;
        if (a.size() < 5 || !ParsePos(a[1].s, x, z)) return false;
        Town* town = FindTown(w, static_cast<uint32_t>(a[0].n));
        const int i = infodat::FindAbode(a[2].s.c_str());
        if (!town || i < 0) return false;
        auto* p = new PlannedAbode();
        p->coords = MapCoordsFromMetres(x, z, GetTerrainHeightAt(x, z));
        p->info = static_cast<GObjectInfo*>(const_cast<void*>(infodat::Element(infodat::DETAIL_ABODE_INFO, static_cast<uint32_t>(i))));
        p->field_0x28 = a[3].n * 0.001f;
        p->scale = a[4].n * 0.001f;
        p->creation_turn = static_cast<int>(g_game_turn);
        p->town = town;
        town->AddPlanned(p);
        w.planned.push_back(p);
        return true;
    }

    // case 20: (town, pos, heart, player, angle x 1000, scale x 1000). The
    // town by id only (sub_5256C0) and a player that exists (sub_5F89B0), then
    // a PlannedTownCitadelHeart (sub_4530C0) on the town's planned list, its
    // record CITADEL_HEART_INFO[heart]. BUILD_BUILDING starts it.
    // ponytail: the plan's position kept at 0xB7FAE0 is not read by anything
    // found, so it is not kept.
    bool CreatePlannedCitadel(const Args& a) {
        float x, z;
        if (a.size() < 6 || !ParsePos(a[1].s, x, z)) return false;
        Town* town = FindTown(w, static_cast<uint32_t>(a[0].n));
        const void* info = infodat::Element(infodat::DETAIL_CITADEL_HEART_INFO, static_cast<uint32_t>(a[2].n));
        if (!town || !info || PlayerIndex(a[3].s) < 0) return false;
        auto* p = new PlannedTownCitadelHeart();
        p->coords = MapCoordsFromMetres(x, z, GetTerrainHeightAt(x, z));
        p->info = static_cast<GObjectInfo*>(const_cast<void*>(info));
        p->field_0x28 = a[4].n * 0.001f;
        p->scale = a[5].n * 0.001f;
        p->creation_turn = static_cast<int>(g_game_turn);
        p->town = town;
        town->AddPlanned(p);
        return true;
    }

    // case 18: the villager, then its home is the abode whose cell holds the
    // home position (the original walks every town's abode list comparing
    // the integer parts of x and z), unless that abode is already full.
    bool CreateVillagerPos(const Args& a) {
        float x, z, hx, hz;
        if (a.size() < 4 || !ParsePos(a[0].s, x, z) || !ParsePos(a[1].s, hx, hz)) return false;
        Object* o = Make(ENTITY_CAT_VILLAGER, "CREATE_VILLAGER_POS", x, z, 0.0f, 1.0f, -1, a[2].s);
        Villager* v = static_cast<Villager*>(o);
        if (!v) return false;
        v->Construct(static_cast<uint32_t>(a[3].n), false);  // sub_6DFF00 -> sub_6DFC80
        // The abode in the home's cell (the high words of the map coords), from
        // every town. A full one (villager list +0xA4 == maxAdults +0x174) is
        // no home, but its town still takes the villager.
        const MapCoords home_pos = MapCoordsFromMetres(hx, hz);
        const int32_t cx = home_pos.x >> 16, cz = home_pos.z >> 16;
        Abode* home = nullptr;
        Town* town = nullptr;
        for (Town* t : w.towns) {
            for (Abode* ab = reinterpret_cast<Abode*>(t->abode_list.head); ab && !town; ab = ab->next) {
                if ((ab->coords.x >> 16) != cx || (ab->coords.z >> 16) != cz) continue;
                town = ab->GetTown();
                int32_t max_adults = 0;
                if (ab->info) std::memcpy(&max_adults, reinterpret_cast<const char*>(ab->info) + 0x174, 4);
                home = static_cast<int32_t>(ab->villagers.count) == max_adults ? nullptr : ab;
            }
            if (town) break;
        }
        if (home) home->AddVillagerToAbode(v);                            // sub_402DE0
        else if (!town) {}                                                // the game-wide homeless list
        else if (Abode* other = town->FindAbodeWithSpaceInTown(v, 0.0f))  // sub_6CE7D0
            other->AddVillagerToAbode(v);
        else town->AddVillagerToTown(v);                                  // sub_6CD8E0: homeless there
        return true;
    }

    // cases 76/89 and 29/32: a field or fish farm owned by a town.
    bool CreateTownStructure(EntityCategory cat, const std::string& cmd, const Args& a, float angle) {
        float x, z;
        if (a.size() < 3 || !ParsePos(a[1].s, x, z)) return false;
        Town* town = FindTown(w, static_cast<uint32_t>(a[0].n));
        if (!town) return false;
        if (cat == ENTITY_CAT_FISH_FARM) {
            // sub_502C80: the farm sits at its cell's centre.
            const MapCoords c = MapCoordsFromMetres(x, z);
            x = MetresOf((c.x & ~0xFFFF) | 0x8000);
            z = MetresOf((c.z & ~0xFFFF) | 0x8000);
        }
        Object* o = Make(cat, cmd, x, z, angle, 1.0f, a[2].n);
        if (!o) return false;
        if (cat == ENTITY_CAT_FISH_FARM) {
            // sub_502970: the nearest town (sub_6CE6D0, any player, no range
            // limit) wins over the script's; the farm goes on its list.
            auto* farm = static_cast<FishFarm*>(o);
            Town* best = town;
            float best_d = 3.4e38f;
            for (Town* t : w.towns) {
                const float dx = MetresOf(t->coords.x - o->coords.x), dz = MetresOf(t->coords.z - o->coords.z);
                if (dx * dx + dz * dz < best_d) { best_d = dx * dx + dz * dz; best = t; }
            }
            farm->town = best;
            best->fish_farms.Add(farm);
            return true;
        }
        if (cat == ENTITY_CAT_FIELD) {
            // sub_4FEB10: a field is given its town and goes on the town's
            // field list -- not the abode list (sub_401BA0 returns before
            // sub_402B80 for fields) -- and grows on one turn in ten.
            auto* field = static_cast<Field*>(o);
            field->town = town;
            field->stagger = static_cast<int>(lh::Random(10));
            town->field_list.Add(field);
            return true;
        }
        town->AddStructureToTown(static_cast<MultiMapFixed*>(o));
        return true;
    }

    bool Dispatch(const std::string& cmd, const Args& a) {
        float x, z;
        if (cmd == "VERSION") return true;
        if (cmd == "LOAD_LANDSCAPE") { if (!a.empty()) w.landscape = a[0].s; return true; }
        if (cmd == "SET_LAND_NUMBER") { if (!a.empty()) w.land_number = a[0].n; return true; }
        if (cmd == "START_CAMERA_POS") return !a.empty() && ParsePos(a[0].s, w.camera_x, w.camera_z);
        if (cmd == "CREATE_TOWN") return CreateTown(a);
        if (cmd == "SET_TOWN_BELIEF") return SetTownBelief(a);
        if (cmd == "SET_TOWN_UNINHABITABLE") return SetTownUninhabitable(a);
        if (cmd == "CREATE_ABODE") return CreateAbode(cmd, a, false);
        if (cmd == "CREATE_TOWN_CENTRE") return CreateAbode(cmd, a, true);
        if (cmd == "CREATE_PLANNED_ABODE") return CreatePlannedAbode(a);
        if (cmd == "CREATE_PLANNED_CITADEL") return CreatePlannedCitadel(a);
        if (cmd == "CREATE_VILLAGER_POS") return CreateVillagerPos(a);
        if (cmd == "CREATE_NEW_TOWN_FIELD")
            return CreateTownStructure(ENTITY_CAT_FIELD, cmd, a, a.size() > 3 ? a[3].f : 0.0f);
        if (cmd == "CREATE_TOWN_FISH_FARM")
            return CreateTownStructure(ENTITY_CAT_FISH_FARM, cmd, a, 0.0f);
        // case 28: (forest, pos, type, flag, angle, scale, scale2)
        if (cmd == "CREATE_NEW_TREE")
            return a.size() >= 6 && ParsePos(a[1].s, x, z) &&
                   Make(ENTITY_CAT_TREE, cmd, x, z, a[4].f, a[5].f, a[2].n);
        // case 42: (pos, type, ...floats). ponytail: scale = arg2, angle = arg4,
        // as the viewer always read them; sub_5C3710's own use of the five
        // floats is not translated yet.
        if (cmd == "CREATE_MOBILE_STATIC")
            return a.size() >= 5 && ParsePos(a[0].s, x, z) &&
                   Make(ENTITY_CAT_MOBILE, cmd, x, z, a[4].f, a[2].f, a[1].n);
        // case 40: (pos, type, angle*1000, scale*1000)
        if (cmd == "CREATE_MOBILEOBJECT")
            return a.size() >= 4 && ParsePos(a[0].s, x, z) &&
                   Make(ENTITY_CAT_MOBILE_OBJECT, cmd, x, z, a[2].n * 0.001f, a[3].n * 0.001f, a[1].n);
        // case 75: (pos, name, angle*1000, scale*1000, by_index); by_index != 0
        // makes arg 1 a record number instead of a name.
        if (cmd == "CREATE_NEW_FEATURE") {
            if (a.size() < 5 || !ParsePos(a[0].s, x, z)) return false;
            const float angle = a[2].n * 0.001f, scale = a[3].n * 0.001f;
            return a[4].n ? Make(ENTITY_CAT_FEATURE, cmd, x, z, angle, scale, std::atoi(a[1].s.c_str()))
                          : Make(ENTITY_CAT_FEATURE, cmd, x, z, angle, scale, -1, a[1].s);
        }
        // case 58: (pos, type, ?, angle, scale) -> sub_431AA0
        if (cmd == "CREATE_NEW_BIG_FOREST") {
            if (a.size() < 5 || !ParsePos(a[0].s, x, z)) return false;
            Object* o = Make(ENTITY_CAT_BIG_FOREST, cmd, x, z, a[3].f, a[4].f, a[1].n);
            if (o) w.forests.push_back(static_cast<BigForest*>(o)->forest);
            return o != nullptr;
        }
        // case 25: (pos, type, flock, town, age)
        if (cmd == "CREATE_NEW_ANIMAL") {
            if (a.size() < 5 || !ParsePos(a[0].s, x, z)) return false;
            Object* o = Make(ENTITY_CAT_ANIMAL, cmd, x, z, 0.0f, 1.0f, a[1].n);
            if (o) static_cast<Living*>(o)->SetAge(static_cast<uint32_t>(a[4].n));
            return o != nullptr;
        }
        return false;
    }
};

} // namespace

Town* FindTown(const World& w, uint32_t id) {
    for (Town* t : w.towns) if (t->field_0x5b4 == id) return t;
    return nullptr;
}

bool Load(const char* path, World& out, std::string* err) {
    FILE* f = std::fopen(path, "rb");
    if (!f) { if (err) *err = std::string("cannot open ") + path; return false; }
    ResetMap();  // what is created goes into it (InsertMapObject)
    ResetPlayers();
    Loader L{out};
    char line[2048];
    std::string name;
    Args args;
    while (std::fgets(line, sizeof line, f)) {
        ++out.lines;
        if (!ParseLine(line, name, args)) continue;
        ++out.commands;
        if (L.Dispatch(name, args)) ++out.handled;
        else ++out.unhandled[name];
    }
    std::fclose(f);
    // sub_6B0490 -> sub_6D1710: once the land is built, every town collects
    // its forests.
    for (Town* t : out.towns) t->CollectForests(out.forests);
    return true;
}



void Process(World& w) {
    // Towns first (GPlayer::Process -> Town::Process); a town runs its own
    // abodes (sub_6D9120), so they are skipped in the object pass.
    for (Town* t : w.towns) t->Process();
    for (const Spawned& s : w.objects) {
        if (!s.obj || !s.obj->IsAvailable()) continue;
        if (Abode* a = s.obj->CastAbode()) if (a->GetTown() && !a->IsField_0()) continue;  // fields tick themselves
        // Living::ProcessAll (sub_5AB2E0): the previous position, then the
        // living's own tick (vslot 392; Villager::ProcessState).
        if (Villager* v = dynamic_cast<Villager*>(s.obj)) {
            v->obj_coords = v->coords;
            v->ProcessState();
            continue;
        }
        if (Creature* c = dynamic_cast<Creature*>(s.obj)) {
            c->obj_coords = c->coords;
            c->ProcessState();
            continue;
        }
        s.obj->Process();
    }
    // The magic pass (sub_6B7570): each player's citadel's worship
    // (sub_5F8410), then spells that last, then the fires (sub_6C6A30).
    for (uint32_t i = 0; i < 8; ++i)
        if (Citadel* c = PlayerAt(i)->citadel) c->ProcessWorship();
    if (spell::ActiveCount() || fire::Count()) {
        std::vector<Object*> all;
        all.reserve(w.objects.size());
        for (const Spawned& s : w.objects) if (s.obj) all.push_back(s.obj);
        spell::ProcessActive(all);
        fire::Process(all);
    }
    ++g_game_turn;
}

} // namespace level
