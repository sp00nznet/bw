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
#include <black/LandFeatures.h>
#include <black/Map.h>
#include <black/Living.h>
#include <black/Flock.h>
#include <black/FireFly.h>
#include <black/GClimate.h>
#include <black/GStream.h>
#include <black/Mist.h>
#include <black/Arena.h>
#include <black/PlannedAbode.h>
#include <black/PlannedTownCitadelHeart.h>
#include <black/Player.h>
#include <black/MultiMapFixed.h>
#include <black/Object.h>
#include <black/Terrain.h>
#include <black/Town.h>
#include <black/TownCentre.h>
#include <black/Villager.h>
#include <black/Tree.h>
#include <black/OneOffSpellSeed.h>
#include <black/SpellDispenser.h>
#include <black/CitadelHeart.h>
#include <black/MobileStatic.h>
#include <black/WorshipSite.h>

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
    // A record by the name at `off`, ignoring case (sub_734DE0): seeds by
    // +24 (sub_6C1AF0), magic by its effect record's +52 (sub_5B8C40).
    int ByName(infodat::Section sec, uint32_t n, int off, const std::string& name) {
        for (uint32_t i = 0; i < n; ++i)
            if (const auto* e = static_cast<const char*>(infodat::Element(sec, i)); e && _stricmp(name.c_str(), e + off) == 0) return static_cast<int>(i);
        return -1;
    }

    // case 10 / 12 (CREATE_TOWN_SPELL, CREATE_TOWN_CENTRE_SPELL_ICON):
    // (town, seed) -- the seed's base magic held (+292, sub_6D0200).
    // case 11 (CREATE_NEW_TOWN_SPELL): (town, magic) -- it and its seed's base.
    // ponytail: case 10's town centre icon (sub_6D6180) comes through the
    // worship site's icons instead (Town::AddMagicTypesHeld).
    bool CreateTownSpell(const Args& a, bool by_magic) {
        if (a.size() < 2) return false;
        Town* town = FindTown(w, static_cast<uint32_t>(a[0].n));
        if (!town) return false;
        if (!by_magic) {
            const int seed = ByName(infodat::DETAIL_SPELL_SEEDS, 30, 24, a[1].s);
            if (seed < 0) return false;
            town->AddMagicTypesHeld(static_cast<MAGIC_TYPE>(SeedBase(seed)));
            return true;
        }
        const int m = ByName(infodat::DETAIL_MAGIC_EFFECT_INFO, 42, 52, a[1].s);
        if (m <= 0 || m >= 42) return false;
        town->AddMagicTypesHeld(static_cast<MAGIC_TYPE>(m));
        const int base = SeedBase(SeedOfMagic(m));
        if (!town->IsMagicTypeHeld(static_cast<MAGIC_TYPE>(base))) town->AddMagicTypesHeld(static_cast<MAGIC_TYPE>(base));
        return true;
    }

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
        if (cmd == "SET_TOWN_INFLUENCE_MULTIPLIER" && !a.empty()) { g_town_influence_multiplier = a[0].f; return true; }      // case 96
        if (cmd == "SET_PLAYER_INFLUENCE_MULTIPLIER" && !a.empty()) { g_player_influence_multiplier = a[0].f; return true; }  // case 97
        if (cmd == "CREATE_DRINK_WAYPOINT") {  // case 95 (sub_6FDE10)
            float x, z;
            if (a.empty() || !ParsePos(a[0].s, x, z)) return false;
            land::DrinkWaypoints().push_back(MapCoordsFromMetres(x, z, GetTerrainHeightAt(x, z)));
            return true;
        }
        if (cmd == "CREATE_TOWN_SPELL" || cmd == "CREATE_TOWN_CENTRE_SPELL_ICON") return CreateTownSpell(a, false);
        if (cmd == "CREATE_NEW_TOWN_SPELL") return CreateTownSpell(a, true);
        if (cmd == "CREATE_VILLAGER_POS") return CreateVillagerPos(a);
        if (cmd == "CREATE_NEW_TOWN_FIELD")
            return CreateTownStructure(ENTITY_CAT_FIELD, cmd, a, a.size() > 3 ? a[3].f : 0.0f);
        if (cmd == "CREATE_TOWN_FISH_FARM")
            return CreateTownStructure(ENTITY_CAT_FISH_FARM, cmd, a, 0.0f);
        // case 28: (forest, pos, type, flag, angle, scale, scale2)
        // The forest is the one with that id on the game's list, if any.
        // ponytail: the tree is not put on the forest's own tree lists.
        if (cmd == "CREATE_NEW_TREE") {
            if (a.size() < 6 || !ParsePos(a[1].s, x, z)) return false;
            Object* o = Make(ENTITY_CAT_TREE, cmd, x, z, a[4].f, a[5].f, a[2].n);
            if (!o) return false;
            for (Forest* f : w.forests)
                if (f->id == static_cast<uint32_t>(a[0].n)) { static_cast<Tree*>(o)->forest = f; break; }
            return true;
        }
        // case 84: (pos, magic name) -> sub_6C0D30: a one-off seed of the
        // magic's seed and power-up, strength 1.
        if (cmd == "CREATE_ONE_SHOT_SPELL_PU") {
            if (a.size() < 2 || !ParsePos(a[0].s, x, z)) return false;
            const int m = ByName(infodat::DETAIL_MAGIC_EFFECT_INFO, 42, 52, a[1].s);
            const int s = m > 0 && m < 42 ? SeedOfMagic(m) : -1;
            if (s < 0 || s > 29) return false;
            OneOffSpellSeed* o = CreateOneOffSpellSeed(MapCoordsFromMetres(x, z, GetTerrainHeightAt(x, z)), s, SeedPowerUp(s, m), 1.0f);
            if (o) w.objects.push_back({o, cmd, a[1].s, s});
            return o != nullptr;
        }
        // case 90: (town, pos, abode name, magic name, angle, scale, recharge)
        // -> sub_6B9840: a SpellDispenser abode of the town (by id, else the
        // nearest), giving that magic; made active (it dispenses at once),
        // then the recharge is the level's, and 0 leaves it inactive.
        // ponytail: vslot 581 after creation is not called.
        if (cmd == "CREATE_SPELL_DISPENSER") {
            if (a.size() < 7 || !ParsePos(a[1].s, x, z)) return false;
            Town* town = FindTown(w, static_cast<uint32_t>(a[0].n));
            if (!town) {
                float best = 0.0f;
                for (Town* c : w.towns) {
                    const float d = std::hypot(MetresOf(c->coords.x) - x, MetresOf(c->coords.z) - z);
                    if (!town || d < best) { town = c; best = d; }
                }
            }
            const int m = ByName(infodat::DETAIL_MAGIC_EFFECT_INFO, 42, 52, a[3].s);
            Object* o = Make(ENTITY_CAT_ABODE, cmd, x, z, a[4].f, a[5].f, -1, a[2].s);
            auto* d = o && o->IsSpellDispenser() ? static_cast<SpellDispenser*>(o) : nullptr;
            if (!d || !town) return false;
            d->JoinTown(town);
            d->magic = m < 0 ? 42u : static_cast<uint32_t>(m);
            d->SetActive(true);
            d->recharge = static_cast<uint32_t>(std::lround(a[6].f));
            if (!d->recharge) d->SetActive(false);
            return true;
        }
        // case 19: (pos, heart type, player, angle*1000, scale*1000) -> sub_44EAF0:
        // a new citadel for the player and its heart, whole (scale 1; the
        // fifth argument is not read).
        // ponytail: the land check (sub_5BFD80) and the players' refresh
        // afterwards (sub_59BBC0) are not translated.
        if (cmd == "CREATE_CITADEL") {
            const int p = a.size() >= 5 ? PlayerIndex(a[2].s) : -1;
            const void* info = a.size() >= 5 ? infodat::Element(infodat::DETAIL_CITADEL_HEART_INFO, static_cast<uint32_t>(a[1].n)) : nullptr;
            if (p < 0 || !info || !ParsePos(a[0].s, x, z)) return false;
            const MapCoords at = MapCoordsFromMetres(x, z, GetTerrainHeightAt(x, z));
            Citadel* c = NewCitadel(PlayerAt(static_cast<uint32_t>(p)), at);
            NewCitadelHeart(at, static_cast<GObjectInfo*>(const_cast<void*>(info)), c, a[3].n * 0.001f, 1.0f, 1.0f, nullptr);
            return true;
        }
        // case 22: (pos, type, player, tribe, ...) -> sub_4504D0 on the player's
        // citadel (which needs its heart). Only the tribe is used: the
        // citadel's site for it (sub_44EAD0) takes the player's town of that
        // tribe (sub_705750) and, when the town is building it (sub_6CFDF0),
        // is finished (vslot 576) and the building site goes (sub_6CEC00);
        // with no such town it is finished anyway.
        if (cmd == "CREATE_WORSHIP_SITE") {
            const int p = a.size() >= 4 ? PlayerIndex(a[2].s) : -1;
            const int tribe = a.size() >= 4 ? TribeIndex(a[3].s) : -1;
            GPlayer* player = p >= 0 ? PlayerAt(static_cast<uint32_t>(p)) : nullptr;
            Citadel* c = player ? player->citadel : nullptr;
            if (!c || !c->heart || tribe < 0) return false;
            WorshipSite* site = c->FindOrCreateWorshipSite(
                static_cast<const GTribeInfo*>(infodat::Element(infodat::DETAIL_TRIBE_INFO, static_cast<uint32_t>(tribe))));
            if (!site) return false;
            Town* town = player->towns.first;
            while (town && town->tribe_type != static_cast<uint32_t>(tribe)) town = town->next;
            if (!town) { site->BuildBy(1.0f); return true; }
            if (!site->towns.Has(town)) site->AddTown(town);
            if (town->SiteFor(site)) {
                site->BuildBy(1.0f);
                town->RemoveBuildingSite(site);
            }
            return true;
        }
        // case 26: (id, pos) -> sub_50E200: a Forest container on the game's
        // list; id 0 takes the next number (dword_B17458).
        if (cmd == "CREATE_FOREST") {
            if (a.size() < 2 || !ParsePos(a[1].s, x, z)) return false;
            static uint32_t next_id = 0;
            auto* f = new Forest();
            f->coords = MapCoordsFromMetres(x, z, GetTerrainHeightAt(x, z));
            f->big_forest = nullptr;
            f->field_0x3c = 0;
            const uint32_t id = static_cast<uint32_t>(a[0].n);
            f->id = id ? id : next_id;
            if (!id || next_id < id) next_id = f->id + 1;
            w.forests.push_back(f);
            return true;
        }
        // case 4: (town, player, cap) -> sub_4316D0, the belief's +0x68 cap
        // for that player; the current belief is left alone.
        if (cmd == "SET_TOWN_BELIEF_CAP") {
            Town* t = a.size() >= 3 ? FindTown(w, static_cast<uint32_t>(a[0].n)) : nullptr;
            const int p = a.size() >= 3 ? PlayerIndex(a[1].s) : -1;
            if (!t || p < 0) return false;
            t->belief.belief_in_player_max[p] = a[2].f;
            return true;
        }
        // case 6: (town, pos) -> town +0xF08.
        if (cmd == "SET_TOWN_CONGREGATION_POS") {
            Town* t = a.size() >= 2 ? FindTown(w, static_cast<uint32_t>(a[0].n)) : nullptr;
            if (!t || !ParsePos(a[1].s, x, z)) return false;
            t->congregation_pos = MapCoordsFromMetres(x, z, GetTerrainHeightAt(x, z));
            return true;
        }
        // case 86: (town, desire name, boost) -> the town desire's boost
        // (+0x108 = desire +0xD4). The names are v1.0's table at 0xCC3F60
        // (set at 0x6D6F06 and around); entries 14..16 have none.
        if (cmd == "TOWN_DESIRE_BOOST") {
            static const char* const kNames[] = {"Food", "Wood", "Playtime", "Protection", "Mercy", "Abodes",
                "Civic_Buildings", "Supply_Worship", "For_Children", "To_Build", "For_Rain", "For_Sun",
                "Repair_Town", "Suppy_Workshop"};
            Town* t = a.size() >= 3 ? FindTown(w, static_cast<uint32_t>(a[0].n)) : nullptr;
            int d = -1;
            for (int i = 0; i < 14 && a.size() >= 3; ++i) if (a[1].s == kNames[i]) { d = i; break; }
            if (!t || d < 0) return false;
            t->desire.boost[d] = a[2].f;
            return true;
        }
        // case 16: (town, pos, villager type, age) -> sub_6DFF00, then the town
        // (by id, else the nearest, sub_525710) takes it in (sub_6CD8E0).
        if (cmd == "CREATE_TOWN_VILLAGER") {
            if (a.size() < 4 || !ParsePos(a[1].s, x, z)) return false;
            auto* v = static_cast<Villager*>(Make(ENTITY_CAT_VILLAGER, cmd, x, z, 0.0f, 1.0f, -1, a[2].s));
            if (!v) return false;
            v->Construct(static_cast<uint32_t>(a[3].n), false);
            Town* t = FindTown(w, static_cast<uint32_t>(a[0].n));
            if (!t) {
                float best = 0.0f;
                for (Town* c : w.towns) {
                    const float d = std::hypot(MetresOf(c->coords.x - v->coords.x), MetresOf(c->coords.z - v->coords.z));
                    if (!t || d < best) { t = c; best = d; }
                }
            }
            if (t) t->AddVillagerToTown(v);
            return true;
        }
        // case 77: (player, on) -> sub_5F9550 on the player's computer player
        // (+0x15C): its +440 and, when on, the player's type 2. We make no
        // computer player, so as in v1.0 without one, nothing changes.
        if (cmd == "TOGGLE_COMPUTER_PLAYER") return a.size() >= 2 && PlayerIndex(a[0].s) >= 0;
        // case 93: (index, value) -> sub_5A2440.
        if (cmd == "SET_GLOBAL_LAND_BALANCE") {
            if (a.size() < 2 || a[0].n < 0 || a[0].n >= 16) return false;
            g_land_balance[a[0].n] = a[1].f;
            return true;
        }
        // case 102: (day, night, dusk) -> sub_529470.
        if (cmd == "SET_NIGHTTIME") {
            if (a.size() < 3) return false;
            SetNighttime(a[0].f, a[1].f, a[2].f);
            return true;
        }
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
        // case 38: (pos, pot type, ?, amount). No pot when the amount is not
        // positive -- Land 1's four all give 0.
        // ponytail: a pot that would be made (sub_616C40) is not translated.
        if (cmd == "CREATE_POT") return a.size() >= 4 && ParsePos(a[0].s, x, z);
        // case 73: (pos, f1, angle, scale) -> sub_432250. f1 is passed and not used.
        if (cmd == "CREATE_BONFIRE")
            return a.size() >= 4 && ParsePos(a[0].s, x, z) && Make(ENTITY_CAT_BONFIRE, cmd, x, z, a[2].f, a[3].f, 8);
        // case 43: (pos, player, tree type, scale, x, y, z angles) -> sub_4EE200.
        // ponytail: the player (sub_5F89B0) is not kept on it.
        if (cmd == "CREATE_DEAD_TREE") {
            if (a.size() < 7 || !ParsePos(a[0].s, x, z)) return false;
            Object* o = Make(ENTITY_CAT_DEAD_TREE, cmd, x, z, 0.0f, a[3].f, a[2].n);
            if (o) static_cast<MobileStatic*>(o)->SetXYZAnglesAndScale(a[4].f, a[5].f, a[6].f, a[3].f);  // vslot 326
            return o != nullptr;
        }
        // case 80: (pos, type) -> sub_6CA4E0, none within 0.5 m of a lantern.
        if (cmd == "CREATE_STREET_LANTERN") {
            if (a.size() < 2 || !ParsePos(a[0].s, x, z)) return false;
            for (const Spawned& s : w.objects)
                if (s.command == "CREATE_STREET_LANTERN" && std::hypot(MetresOf(s.obj->coords.x) - x, MetresOf(s.obj->coords.z) - z) < 0.5f) return true;
            return Make(ENTITY_CAT_STREET_LANTERN, cmd, x, z, 0.0f, 1.0f, a[1].n) != nullptr;
        }
        // case 87: (pos, name, angle*1000, scale*1000) -> sub_41CB70.
        if (cmd == "CREATE_ANIMATED_STATIC")
            return a.size() >= 4 && ParsePos(a[0].s, x, z) &&
                   Make(ENTITY_CAT_ANIMATED_STATIC, cmd, x, z, a[2].n * 0.001f, a[3].n * 0.001f, -1, a[1].s);
        // case 0: (pos, height, colour, scale, f) -> sub_5C1AE0; the height is
        // above the land (v1.0's y), so ours is the land's plus it.
        if (cmd == "CREATE_MIST")
            return a.size() >= 5 && ParsePos(a[0].s, x, z) &&
                   CreateMist(MapCoordsFromMetres(x, z, GetTerrainHeightAt(x, z) + a[1].f), a[3].f, static_cast<uint32_t>(a[2].n), a[4].f);
        // case 69: (pos, radius) -> sub_41F040.
        if (cmd == "CREATE_ARENA")
            return a.size() >= 2 && ParsePos(a[0].s, x, z) &&
                   CreateArena(MapCoordsFromMetres(x, z, GetTerrainHeightAt(x, z)), a[1].f);
        // case 66: (id) -> sub_6C9B30. case 67: (id, pos) -> sub_6C9C00 on each
        // stream of that id, the point at the land's height.
        if (cmd == "CREATE_STREAM") return !a.empty() && CreateStream(a[0].n);
        if (cmd == "CREATE_STREAM_POINT") {
            if (a.size() < 2 || !ParsePos(a[1].s, x, z)) return false;
            for (GStream* s = FirstStream(); s; s = s->next)
                if (s->id == a[0].n) s->AddPoint(x, GetTerrainHeightAt(x, z), z);
            return true;
        }
        // case 88: (magic name, odds) -> sub_501E50; an unknown name is 42, ignored.
        if (cmd == "FIRE_FLY_SPELL_REWARD_PROB") {
            if (a.size() < 2) return false;
            const int m = ByName(infodat::DETAIL_MAGIC_EFFECT_INFO, 42, 52, a[0].s);
            SetFireFlyRewardProb(m < 0 ? 42u : static_cast<uint32_t>(m), a[1].f);
            return true;
        }
        // case 60: (id, climate type, pos, radius, radius) -> sub_6FE4B0.
        if (cmd == "CREATE_WEATHER_CLIMATE") {
            if (a.size() < 5 || !ParsePos(a[2].s, x, z)) return false;
            return CreateClimate(MapCoordsFromMetres(x, z), a[1].n, a[3].f, a[4].f, a[0].n) != nullptr;
        }
        // cases 61..63: (id, ...) -> sub_7002F0 / sub_700380 / sub_7003C0, on the
        // climate of that id (sub_7002A0), id 0 the default.
        if (cmd == "CREATE_WEATHER_CLIMATE_RAIN" || cmd == "CREATE_WEATHER_CLIMATE_TEMP" || cmd == "CREATE_WEATHER_CLIMATE_WIND") {
            if (a.empty()) return false;
            GClimate* c = FindClimate(a[0].n);
            if (!c) return true;  // no climate of that id: nothing
            if (cmd == "CREATE_WEATHER_CLIMATE_RAIN" && a.size() >= 5)
                c->rain = {a[1].f, a[2].n, a[3].n, static_cast<uint8_t>(a[4].n)};
            else if (cmd == "CREATE_WEATHER_CLIMATE_TEMP" && a.size() >= 3)
                c->temp[0] = a[1].f, c->temp[1] = a[2].f;
            else if (cmd == "CREATE_WEATHER_CLIMATE_WIND" && a.size() >= 4)
                c->wind[0] = a[1].f, c->wind[1] = a[2].f, c->wind[2] = a[3].f;
            else return false;
            return true;
        }
        // case 49 (version 2.1 on): (id, pos, centre, radius, radius 2, town)
        // -> sub_5058F0, which flocks at pos; then the domain centre and radii
        // (a radius of 0 is 80). The town lists it (+0xF00).
        if (cmd == "CREATE_FLOCK") {
            float cx, cz;
            if (a.size() < 6 || !ParsePos(a[1].s, x, z) || !ParsePos(a[2].s, cx, cz)) return false;
            auto* f = new Flock();
            f->Init(MapCoordsFromMetres(x, z, GetTerrainHeightAt(x, z)), static_cast<uint32_t>(a[0].n));
            if (Town* t = FindTown(w, static_cast<uint32_t>(a[5].n))) {
                f->town = t;
                t->flocks = new Town::FlockLink{t->flocks, f};
                ++t->flock_count;
            }
            f->SetDomainCentrePos(MapCoordsFromMetres(cx, cz, GetTerrainHeightAt(cx, cz)));
            f->domain_radius = static_cast<uint16_t>(a[3].n ? a[3].n : 80);
            f->radius_b = static_cast<uint16_t>(a[4].n);
            w.flocks.push_back(f);
            return true;
        }
        // case 25: (pos, type, flock, town, age) -> sub_416240. In a flock an
        // age of 0 is 5..24; the animal joins it (sub_505B20).
        // ponytail: the town (sub_414480) and sub_416240's vslot-744 leader
        // test are not translated.
        if (cmd == "CREATE_NEW_ANIMAL") {
            if (a.size() < 5 || !ParsePos(a[0].s, x, z)) return false;
            Flock* flock = nullptr;
            for (Flock* f : w.flocks) if (f->id == static_cast<uint32_t>(a[2].n)) { flock = f; break; }
            Object* o = Make(ENTITY_CAT_ANIMAL, cmd, x, z, 0.0f, 1.0f, a[1].n);
            if (!o) return false;
            auto* l = static_cast<Living*>(o);
            uint32_t age = static_cast<uint32_t>(a[4].n);
            if (flock && !age) age = lh::Random(20) + 5;
            l->SetAge(age);
            if (flock) {
                flock->AddMember(l);
                if (flock->max_count < static_cast<uint32_t>(flock->count)) flock->max_count = flock->count;
            }
            return true;
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
    g_town_influence_multiplier = g_player_influence_multiplier = 1.0f;
    land::DrinkWaypoints().clear();
    ResetClimates();
    ResetStreams();
    ResetMists();
    ResetArenas();
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
