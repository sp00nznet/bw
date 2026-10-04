// VillagerStates — v1.0's villager state machine, the translated part.
//
// v1.0 runs each villager from Living::ProcessAll (sub_5AB2E0) through its
// vslot 392 tick (sub_6E01E0): count the turn, then call the current state's
// function from a 255-entry table at 0xC2A2C8 (rebuilt in work/decomp by
// emulating its initialiser). This file is that tick plus the states
// translated so far; docs/villager-states.md lists them and what is missing.
#include <black/Villager.h>

#include <black/Abode.h>
#include <black/Field.h>
#include <black/FishFarm.h>
#include <black/InfoDat.h>
#include <black/LHRandom.h>
#include <black/Terrain.h>
#include <black/Town.h>
#include <black/TownDesire.h>

#include <cmath>
#include <cstring>

extern uint32_t g_game_turn;

namespace vs {
namespace {

float InfoF(const Villager& v, int off) { float x = 0; if (v.info) std::memcpy(&x, reinterpret_cast<const char*>(v.info) + off, 4); return x; }
uint32_t InfoU(const Villager& v, int off) { uint32_t x = 0; if (v.info) std::memcpy(&x, reinterpret_cast<const char*>(v.info) + off, 4); return x; }
uint8_t InfoB(const Villager& v, int off) { return v.info ? reinterpret_cast<const uint8_t*>(v.info)[off] : 0; }

// Work sites: the states that share a site's enter/exit slots.
enum Site { kNoSite, kFishFarm, kField };
Site SiteOf(uint8_t s) {
    if (s == VILLAGER_STATE_FISHERMAN_ARRIVES_AT_FISHING || s == VILLAGER_STATE_FISHING) return kFishFarm;
    if (s >= VILLAGER_STATE_FARMER_ARRIVES_AT_FARM && s <= VILLAGER_STATE_FARMER_DIGS_UP_CROP) return kField;
    return kNoSite;
}
bool IsFishingState(uint8_t s) { return SiteOf(s) != kNoSite; }
// On the way to a site counts as being at it (the original's sub_6E2010 test).
Site SiteOf(const Villager& v) {
    const Site s = SiteOf(v.action.top_state);
    return s != kNoSite ? s : SiteOf(v.action.final_state);
}
LHNodeList* Workers(Object* target, Site s) {
    if (!target) return nullptr;
    if (s == kFishFarm) return &static_cast<FishFarm*>(target)->villagers;
    if (s == kField) return &static_cast<Field*>(target)->farmers;
    return nullptr;
}
// The site states' enter slots (fishing 0x6EA8B0 -> sub_503660, farming
// 0x6E9420 -> sub_4FEFB0: onto the site's list) and exit slots (0x6EA910 ->
// sub_5036A0, 0x6E9470 -> sub_4FEF10: off it, and the target cleared).
void FishingSlots(Villager& v, Site was) {
    const Site now = SiteOf(v);
    if (now == was) return;
    if (was != kNoSite) {
        if (LHNodeList* l = Workers(v.target, was)) l->Remove(&v);
        v.target = nullptr;
    }
    if (now == kFishFarm && !v.GetTown()) return;
    if (LHNodeList* l = Workers(v.target, now); l && !l->Has(&v)) l->Add(&v);
}

// vslot 569 (sub_6E1B90), the core: the new state, its turn count from zero.
// ponytail: the original first may divert a frail villager into
// PauseForASecond (239), and runs every state's exit/enter slots; only the
// fishing states' are translated.
void SetState(Villager& v, uint8_t s) {
    const Site was = SiteOf(v);
    v.action.previous_state = v.action.top_state;
    v.action.top_state = s;
    if (IsFishingState(v.action.final_state) && !IsFishingState(s)) v.action.final_state = s;  // a stale goal must not keep it a fisherman
    v.action.turns_since_state_change = 0;
    FishingSlots(v, was);
}

// sub_5B0E40: walk (the state at villager info +292) to pos, then enter `arrive`.
void MoveToPosThen(Villager& v, const MapCoords& pos, uint8_t arrive) {
    uint8_t walk = InfoB(v, 292);
    if (!walk) walk = VILLAGER_STATE_MOVE_TO_POS;
    const Site was = SiteOf(v);
    v.action.previous_state = v.action.top_state;
    v.action.top_state = walk;
    v.action.final_state = arrive;
    v.action.turns_since_state_change = 0;
    MapCoords p = pos;
    p.altitude = GetTerrainHeightAt(MetresOf(p.x), MetresOf(p.z));
    v.SetGoalPos(p);
    FishingSlots(v, was);
}
// sub_5AC660. ponytail: the original asks the object for its own approach
// (vslot 32, e.g. an abode's door); straight to its position here.
void MoveToObjectThen(Villager& v, Object* o, uint8_t arrive) { MoveToPosThen(v, o->coords, arrive); }

// sub_6DE5A0 / sub_5C12D0: a point `r` metres from `from` at angle `a`.
MapCoords Around(const MapCoords& from, float a, float r) {
    return MapCoords(from.x + static_cast<int32_t>(std::cos(a) * r * kMapUnitsPerMetre),
                     from.z + static_cast<int32_t>(std::sin(a) * r * kMapUnitsPerMetre), from.altitude);
}
// sub_6DE3E0: the heading from a to b.
float Heading(const MapCoords& a, const MapCoords& b) {
    return std::atan2(static_cast<float>(b.z - a.z), static_cast<float>(b.x - a.x));
}
float DistanceM(const MapCoords& a, const MapCoords& b) {
    const float dx = MetresOf(b.x - a.x), dz = MetresOf(b.z - a.z);
    return std::sqrt(dx * dx + dz * dz);
}

// sub_6D9490: an emergency within the last TownInfo +272 turns (+0xF14).
bool TownInEmergency(Town* t) {
    uint32_t since, window = 0;
    std::memcpy(&since, reinterpret_cast<const char*>(t) + 0xF14, 4);
    if (t->info) std::memcpy(&window, reinterpret_cast<const char*>(t->info) + 272, 4);
    return since && g_game_turn - since < window;
}

bool Hungry(const Villager& v) { return v.food <= InfoF(v, 704); }                 // sub_6E2110
float HungerNeed(float food) { const float f = food < 1 ? food : 1; return 1.0f - f * f * f; }  // sub_6EAB60
float SleepNeed(const Villager& v) {                                               // sub_6EABC0
    const float t = InfoF(v, 860), life = v.life;
    const float x = (life - (t < life ? t : life)) / (1.0f - t);
    return 1.0f - x * x;
}
// sub_6E76E0: how much the villager's own needs press, against work.
float BusyFactor(Villager& v) {
    if (v.field_0xe0 & 1) return 0.0f;
    const float hunger = Hungry(v) ? HungerNeed(v.food) : 0.0f;
    const float hurt = 1.0f - v.life * v.life;
    float r = (hunger < hurt ? hunger : hurt) * 0.5f + (hunger > hurt ? hunger : hurt);
    if (v.IsChild() && r <= 0.11f) return 0.11f;
    return r >= 1.0f ? 1.0f : r;
}

void RandomIdle(Villager& v);
bool SleepHandler(Villager& v);
bool Eat(Villager& v);

// sub_6EFE70: a homeless villager moves into its town's best abode with space.
bool HomelessMoveIn(Villager& v) {
    Town* t = v.GetTown();
    if (!t) return false;
    Abode* a = t->FindAbodeWithSpaceInTown(&v, 0.0f);
    if (!a) return false;
    a->AddVillagerToAbode(&v);  // also takes it off the homeless list
    SetState(v, VILLAGER_STATE_GO_HOME);
    return true;
}

// sub_6EED70: sleep or eat, whichever presses harder past `threshold`;
// eating is sub_6EAEF0 (only when hungry, then sub_6EA9F0).
bool SleepOrEat(Villager& v, float threshold) {
    const float eat = HungerNeed(v.food) - threshold;
    const float sleep = SleepNeed(v) - threshold;
    auto eat_now = [&] { return Hungry(v) && Eat(v); };
    if (eat <= sleep || eat <= 0.0f) {
        if (sleep > 0.0f) {
            if (SleepHandler(v)) return true;
            if (eat > 0.0f) return eat_now();
        }
    } else {
        if (eat_now()) return true;
        if (sleep > 0.0f) return SleepHandler(v);
    }
    return false;
}

// sub_6EED30: worship (not yet), a job from the town's desires, then sleep/eat.
bool FindSomethingToDo(Villager& v) {
    if (Town* t = v.GetTown()) {
        if (t->desire.FindWorkForVillager(&v, BusyFactor(v))) {  // sub_6E76A0 -> sub_6D7D30
            v.field_0xe0 &= ~1u;
            return true;
        }
    }
    return SleepOrEat(v, InfoF(v, 908));
}

// sub_6EECB0
bool HomeOrWork(Villager& v) { return (!v.GetHome() && HomelessMoveIn(v)) || FindSomethingToDo(v); }

// sub_6E3630: a random way to pass the time.
void RandomIdle(Villager& v) {
    Abode* home = v.GetHome();
    Town* town = v.GetTown();
    switch (lh::Random(9)) {
    case 0:
        if ((home && home->IsFunctional()) || lh::Random(100) < 10) { SetState(v, VILLAGER_STATE_GO_HOME); return; }
        [[fallthrough]];
    case 1: case 2: case 3:
        if (home) { SetState(v, VILLAGER_STATE_GO_AND_CHILLOUT_OUTSIDE_HOME); return; }
        [[fallthrough]];
    case 4: case 5: case 6: case 7: case 8:
        if (town) {  // sub_6E3750: a spot out from the town towards the villager
            const float scale = 0.1f * [&] { float x = 0; if (town->info) std::memcpy(&x, reinterpret_cast<const char*>(town->info) + 320, 4); return x; }();
            const float a = Heading(town->coords, v.coords) + lh::RandomFloat(0.785398f) - 0.392699f;
            MoveToPosThen(v, Around(town->coords, a, lh::RandomFloat(scale * 9.0f) + scale), VILLAGER_STATE_SIT_AND_CHILLOUT);
            return;
        }
        [[fallthrough]];
    default:
        SetState(v, VILLAGER_STATE_GO_HOME);
    }
}

// sub_6EFF90: the Sleep desire's handler, and the sleep half of SleepOrEat.
bool SleepHandler(Villager& v) {
    if ((v.field_0xe0 & 1) && v.life >= InfoF(v, 860)) return false;
    if (!(v.field_0xe0 & 4)) {  // not inside
        if (v.GetHome()) { SetState(v, VILLAGER_STATE_GO_HOME); return true; }
        return v.action.top_state == VILLAGER_STATE_SLEEP_IN_TENT;
    }
    // ponytail: sub_6EF830 (the household turning in together) is not translated.
    SetState(v, VILLAGER_STATE_GOTO_BED_AT_HOME);
    return true;
}

// --- upkeep, eating, death --------------------------------------------------

// DETAIL_VILLAGER_STATE_TABLE_INFO, the element for state s (0xCDAB00 + 276 s).
const char* StateInfo(uint8_t s) { return static_cast<const char*>(infodat::Element(infodat::DETAIL_VILLAGER_STATE_TABLE_INFO, s)); }
uint32_t StateU(uint8_t s, int off) { uint32_t x = 0; if (const char* e = StateInfo(s)) std::memcpy(&x, e + off, 4); return x; }
float StateF(uint8_t s, int off) { float x = 0; if (const char* e = StateInfo(s)) std::memcpy(&x, e + off, 4); return x; }
float RawF(const void* p, int off) { float x = 0; if (p) std::memcpy(&x, static_cast<const char*>(p) + off, 4); return x; }

// vslot 704 (sub_6E19C0): the top state, unless it is a step on the way
// (element +0x1C clear, e.g. walking), then the state it leads to.
uint8_t RealState(const Villager& v) { return StateU(v.action.top_state, 0x1C) ? v.action.top_state : v.action.final_state; }

// dword_8D136C, 7 dwords per disciple type: +0 is 1 for the types that do not
// stop to eat on their own (types 1-6, 8, 9).
bool DiscipleWorks(const Villager& v) {
    static const uint8_t k[16] = {0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0};
    return v.disciple_type < 16 && k[v.disciple_type] == 1;
}

uint32_t TurnsSinceCheck(const Villager& v) { return g_game_turn - static_cast<uint32_t>(v.last_check_turn); }  // sub_6E0820

// sub_6E0860 -> vslot 425 (sub_6F8500): dying. ponytail: the death's
// notifications -- the player's and town's statistics (sub_4122C0,
// sub_6D0D80, sub_6D10C0), the disciple and mourning messages, dropping a
// carried object (sub_6E0AA0) -- and the cause byte at +0x110 are not kept.
void Die(Villager& v, int /*cause*/) {
    if ((v.field_0x24 & 0x40) || (v.status & 1)) return;
    v.resource_held[0] = v.resource_held[1] = 0;  // sub_6E0FE0(0) / sub_6E1040(0)
    v.SetLife(0.0f);
    SetState(v, VILLAGER_STATE_DYING);
    v.status |= 0x31;
    // The time spent dying: villager info +660 when the town has a +0x740
    // object in use, else +656.
    Town* t = v.GetTown();
    Object* o = nullptr;
    if (t) std::memcpy(&o, reinterpret_cast<const char*>(t) + 1856, sizeof o);
    v.turns_until_next_state_change = static_cast<int16_t>(InfoU(v, o && o->IsFunctional() ? 660 : 656));
    v.field_0xe0 |= 0x40;
}

// sub_6EAC20: how much food the villager wants to eat now -- its hunger (the
// cube curve) x villager info +728, a little less in a town that is well off
// (town +332, up to 30%).
int FoodWanted(Villager& v) {
    float x = HungerNeed(v.food) * static_cast<float>(static_cast<int32_t>(InfoU(v, 728)));
    if (Town* t = v.GetTown()) {
        float k = RawF(t, 332);
        k = k < 0 ? 0 : (k > 1 ? 1 : k);
        x *= 1.0f - k * 0.3f;
    }
    return static_cast<int>(x);
}
// sub_6EAC00: what it wants beyond what it carries.
// ponytail: the original's result is unsigned, so carrying more than it wants
// wraps to a huge need; here that is no need at all (it eats what it has).
int FoodNeeded(Villager& v) {
    const int n = FoodWanted(v) - v.resource_held[0];
    return n > 0 ? n : 0;
}

// sub_6E1AC0: where the villager gets food: its town's storage pit when it
// has one available, otherwise its home.
Abode* Store(Villager& v) {
    if (Town* t = v.GetTown())
        if (Abode* pit = reinterpret_cast<Abode*>(t->storage_pit_list); pit && pit->IsAvailable()) return pit;
    return v.GetHome();
}
bool Usable(Object* o) { return o && o->IsFunctional(); }
uint32_t FoodIn(Object* o) { return o->GetResource(static_cast<RESOURCE_TYPE>(0)); }
// sub_6E2E90: take up to n of a store's food into the villager's hands.
void TakeFood(Villager& v, Object* from, uint32_t n) {
    if (n > FoodIn(from)) n = FoodIn(from);
    if (!n) return;
    const uint32_t got = from->RemoveResource(static_cast<RESOURCE_TYPE>(0), n, nullptr, nullptr);
    v.resource_held[0] = static_cast<int16_t>(v.resource_held[0] + got);  // sub_6E10E0
}

// sub_6EAF10: eat from what is carried. Food rises by the share of the want
// eaten x villager info +696, capped at 1.
// ponytail: the town's carried-food statistic (town +1792, sub_6CE890) is not kept.
void Consume(Villager& v) {
    const float want = static_cast<float>(FoodWanted(v));
    const float held = static_cast<float>(v.resource_held[0]);
    const float eaten = want <= held ? want : held;
    v.resource_held[0] = static_cast<int16_t>(v.resource_held[0] - static_cast<int>(eaten));  // sub_6E0FE0
    if (want > 0) v.food += eaten / want * InfoF(v, 696);
    if (v.food < 0) v.food = 0;
    else if (v.food > 1) v.food = 1;
}

// sub_6EA9F0: go and eat -- at home if it has the food, else from the store,
// else what is carried.
bool Eat(Villager& v) {
    const uint32_t need = static_cast<uint32_t>(FoodNeeded(v));
    const bool inside = (v.field_0xe0 & 4) != 0;
    const uint8_t eat_here = inside ? VILLAGER_STATE_EAT_FOOD_AT_HOME : VILLAGER_STATE_EAT_FOOD;
    if (need == 0) { SetState(v, eat_here); return true; }
    if (Abode* home = v.GetHome(); Usable(home) && static_cast<uint32_t>(v.resource_held[0]) + FoodIn(home) >= need) {
        SetState(v, inside ? VILLAGER_STATE_EAT_FOOD_AT_HOME : VILLAGER_STATE_GO_HOME);
        return true;
    }
    if (Abode* store = Store(v); Usable(store)) {
        if (FoodIn(store) >= need) { SetState(v, VILLAGER_STATE_GOTO_STORAGE_PIT_FOR_FOOD); return true; }
    }
    // ponytail: with no store in use the original walks to a spot in town
    // (sub_6E3900 -> sub_6D1550) to find food there; not translated.
    if (v.resource_held[0] == 0) return false;
    SetState(v, eat_here);
    return true;
}

// sub_6EACC0: the food drain, once per check. Hunger costs life; a hungry
// villager goes to eat; one with no life left dies.
bool FoodDrain(Villager& v) {
    const uint32_t since = TurnsSinceCheck(v);
    if (!since) return false;
    bool done = false;
    float drain = static_cast<float>(since) * InfoF(v, 700);
    const float pace = static_cast<float>(v.speed) / static_cast<float>(static_cast<int32_t>(InfoU(v, 260)));
    if (GPlayer* p = v.GetPlayer()) drain /= RawF(p, 116);
    if (pace > 1.0f && (v.coords.x != v.obj_coords.x || v.coords.z != v.obj_coords.z)) drain *= pace;  // vslot 93: moved
    v.food -= drain;
    if (v.food < 0) v.food = 0;
    // vslot 297 (poisoned) also costs life; nothing poisons villagers yet.
    if (v.food < InfoF(v, 704)) {
        float k = 1.0f - v.food / InfoF(v, 704);
        if (k <= 1.0f) k = 1.0f;  // sic: the original's clamp makes this always 1
        v.ReduceLife(k * InfoF(v, 720), nullptr);
        const uint8_t real = RealState(v);
        if (StateU(real, 0xE0) && !DiscipleWorks(v)) done = Eat(v);
        if (v.food < InfoF(v, 708) && StateU(real, 0xE4) && !done) done = Eat(v);
        if (v.GetLife() <= 0.0f) {
            Die(v, (real >= 248 && real <= 250) || (v.field_0xe0 & 2) ? 4 : 1);
            done = true;
        }
    }
    v.last_check_turn = static_cast<int>(g_game_turn);  // sub_6E0840
    return done;
}

// sub_6EF970: old age. Past villager info +316 years, a cubed random share of
// the years to +320 is added; past +320 the villager dies.
bool OldAge(Villager& v) {
    const uint32_t age = v.GetAge();
    if (age <= InfoU(v, 316)) return false;
    const float r = lh::RandomFloat(1.0f);
    const uint32_t extra = static_cast<uint32_t>(static_cast<float>(InfoU(v, 320) - InfoU(v, 316)) * r * r * r);
    if (age + extra <= InfoU(v, 320)) return false;
    Die(v, 9);
    return true;
}

// sub_6E0EB0: a child grows up at villager info +312 years.
// ponytail: the quarter-yearly growth step (sub_6E2590, the scale) and the
// home's adult/child bookkeeping (sub_4037F0, sub_6E7430) are not translated.
void GrowUp(Villager& v) {
    const uint32_t adult = InfoU(v, 312);
    if (v.GetAge() >= adult) v.SetAge(adult < 18 ? 18 : adult);  // clears the child bit
}

// sub_6E05D0: the per-turn upkeep. The state's own life cost (element +0x108),
// then -- in states that feel hunger (+0xF4), once every villager info +732
// turns -- old age, tiredness sending it home, growing up, and the food drain.
void Upkeep(Villager& v) {
    if (v.field_0x24 & 0x400) return;
    uint8_t s = v.action.top_state;
    if (StateU(s, 0x24)) {
        v.ReduceLife(StateF(s, 0x108), nullptr);
        s = v.action.final_state;
    } else {
        v.ReduceLife(StateF(RealState(v), 0x108), nullptr);
    }
    if (!StateU(s, 0xF4)) return;  // ponytail: the disciple tail (LABEL_38) is not translated
    if (v.GetLife() == 0.0f) {
        const uint8_t real = RealState(v);
        Die(v, (real >= 248 && real <= 250) || (v.field_0xe0 & 2) ? 4 : 8);
        return;
    }
    const uint32_t since = TurnsSinceCheck(v);
    if (since <= InfoU(v, 732)) return;
    // sub_430370 numbers each object (its handle); the serial stands in, to
    // stagger the old-age checks the same way.
    if ((g_game_turn + v.field_0x3c) % 800u < since && OldAge(v)) return;
    if (v.GetLife() < InfoF(v, 860) && !(v.field_0xe0 & 4) && StateU(s, 0xF8) &&
        static_cast<int8_t>(v.status & 0xFF) >= 0 && !StateU(s, 0xE8) &&
        ((s != 19 && s != 20) || v.food > InfoF(v, 704)))
        SetState(v, VILLAGER_STATE_GO_HOME);
    if (v.IsChild()) GrowUp(v);
    // ponytail: pregnancy and birth (sub_6E1D80 -> sub_6F0C60) are not translated.
    FoodDrain(v);
}

// --- work: the store, the food job, fishing ----------------------------------

// sub_6DF670 -> sub_6DF550(0.5, x): how much a distance d within `range`
// still counts -- a sigmoid read from the 41-entry table at 0xB461D4.
float Falloff(float d, float range) {
    static const uint32_t kTable[41] = {
        0x00000000, 0x317763df, 0x322bcc77, 0x32f084a7, 0x33a71301, 0x34684017, 0x35218b62,
        0x35e0ae34, 0x369c419b, 0x375955de, 0x38172465, 0x38d235bd, 0x39922a17, 0x3a4b32f9,
        0x3b0d1eb3, 0x3bc38892, 0x3c868d9b, 0x3d35d41d, 0x3dea5e18, 0x3e8762a1, 0x3f000000,
        0x3f3c4eb0, 0x3f62b43d, 0x3f74a2be, 0x3f7bcb93, 0x3f7e78ef, 0x3f7f72e1, 0x3f7fcd33,
        0x3f7fedbb, 0x3f7ff96e, 0x3f7ffda3, 0x3f7fff27, 0x3f7fffb2, 0x3f7fffe4, 0x3f7ffff6,
        0x3f7ffffc, 0x3f7fffff, 0x3f800000, 0x3f800000, 0x3f800000, 0x3f800000};
    float x = 1.0f - (d < range ? d : range) / range;
    x = x < -1.0f ? -1.0f : (x > 1.0f ? 1.0f : x);
    float y = x - 0.5f;
    y = y < -1.0f ? -1.0f : (y > 1.0f ? 1.0f : y);
    int i = static_cast<int>((y + 1.0f) * 20.5f);  // _ftol: truncation
    if (i > 40) i = 40;
    float r;
    std::memcpy(&r, &kTable[i], 4);
    return r;
}

int CarryCapacity(const Villager& v) { return static_cast<int>(InfoU(v, 612)); }
int RoomToCarry(const Villager& v) { return CarryCapacity(v) - v.resource_held[0]; }  // sub_6E11C0

// sub_6E1210: what the villager carries, food first when it has more of it.
int Carried(const Villager& v, RESOURCE_TYPE* type) {
    if (v.resource_held[0] > v.resource_held[1]) { *type = static_cast<RESOURCE_TYPE>(0); return v.resource_held[0]; }
    *type = static_cast<RESOURCE_TYPE>(1);
    return v.resource_held[1];
}

// sub_6E3900, simplified: where it would drop things off -- the store, else
// its town. ponytail: without a store the original asks the town for a spot
// (sub_6D1550).
MapCoords DropOffSpot(Villager& v) {
    if (Abode* store = Store(v); Usable(store)) return store->coords;
    if (Town* t = v.GetTown()) return t->coords;
    return v.coords;
}

// sub_6F7670 (state 31's function): take what it carries to the store.
bool GotoStoragePit(Villager& v) {
    if (Abode* store = Store(v); Usable(store)) {
        MoveToObjectThen(v, store, VILLAGER_STATE_ARRIVES_AT_STORAGE_PIT_FOR_DROP_OFF);
        return true;
    }
    RESOURCE_TYPE type;
    if (Carried(v, &type) && static_cast<int>(type) < 2) {
        MoveToPosThen(v, DropOffSpot(v), VILLAGER_STATE_ARRIVES_AT_STORAGE_PIT_FOR_DROP_OFF);
        return true;
    }
    SetState(v, VILLAGER_STATE_DECIDE_WHAT_TO_DO);
    return false;
}

// sub_6F7720 (32): put one kind of what it carries into the store
// (vslot 39, AddResource), then decide.
// ponytail: without a store the original puts it on something in town.
void ArrivesAtStoragePit(Villager& v) {
    RESOURCE_TYPE type;
    const int n = Carried(v, &type);
    if (Abode* store = Store(v); n && Usable(store)) {
        const uint32_t put = store->AddResource(type, static_cast<uint32_t>(n), nullptr, false, store->coords, 0);
        int16_t& held = v.resource_held[static_cast<int>(type)];  // sub_6E0FB0
        held = static_cast<int16_t>(held - static_cast<int>(put < static_cast<uint32_t>(held) ? put : static_cast<uint32_t>(held)));
    }
    SetState(v, VILLAGER_STATE_DECIDE_WHAT_TO_DO);
}

// sub_503700: a fish farm's pull -- 1 while nobody fishes it, else 0 (the
// original truncates 1 - fishermen / info +288 to an integer).
float FishFarmPull(const FishFarm* f) {
    float k = static_cast<float>(f->villagers.count) / static_cast<float>(static_cast<int32_t>(
        f->info ? *reinterpret_cast<const uint32_t*>(reinterpret_cast<const char*>(f->info) + 288) : 1));
    if (k > 1.0f) k = 1.0f;
    return static_cast<float>(static_cast<int>(1.0f - k));
}

// sub_6EA5F0: off to fish at a farm.
bool GoFishing(Villager& v, FishFarm* farm) {
    SetState(v, VILLAGER_STATE_DECIDE_WHAT_TO_DO);
    v.target = farm;
    MoveToObjectThen(v, farm, VILLAGER_STATE_FISHERMAN_ARRIVES_AT_FISHING);
    return true;
}

// sub_6E9100: the Food desire's handler. The town's food sources are ranked
// by pull x distance falloff -- fish farms within 500 m (sub_6D13A0), fields
// within 300 m (sub_6D14C0), and a third list at town +0xF00 (sub_6D1440)
// -- against taking what it already carries to the store (how full its hands
// are x the store's falloff within 500 m). The best wins.
// The ranking is a list sorted highest first in which a later source goes
// behind earlier ones of equal score, so fish farms win ties.
// ponytail: the third source is not translated, so it never outranks the others.
bool GoFarming(Villager& v, Field* field);
bool FoodJob(Villager& v) {
    Town* t = v.GetTown();
    if (!t) return false;
    FishFarm* farm = nullptr;
    float farm_score = 0.0f;
    for (LHNode* n = t->fish_farms.head; n; n = n->next) {
        auto* f = static_cast<FishFarm*>(n->obj);
        const float sc = FishFarmPull(f) * Falloff(DistanceM(f->coords, v.coords), 500.0f);
        if (sc > farm_score) { farm_score = sc; farm = f; }
    }
    Field* field = nullptr;
    float field_score = 0.0f;
    for (LHNode* n = t->field_list.head; n; n = n->next) {
        auto* f = static_cast<Field*>(n->obj);
        const float sc = f->GetPull() * Falloff(DistanceM(f->coords, v.coords), 300.0f);
        if (sc > field_score) { field_score = sc; field = f; }
    }
    const bool fields_first = field_score > farm_score;
    const float best = fields_first ? field_score : farm_score;
    const float full = 1.0f - (static_cast<float>(RoomToCarry(v)) + 0.00001f) / (static_cast<float>(CarryCapacity(v)) + 0.00001f);
    if (Falloff(DistanceM(DropOffSpot(v), v.coords), 500.0f) * full > best) return GotoStoragePit(v);
    if (fields_first) return GoFarming(v, field);
    return farm && GoFishing(v, farm);
}

// sub_4FF540: a random spot in the field, within 5 m of its centre.
MapCoords FieldSpot(const Field* f) {
    const float dx = lh::RandomFloat(10.0f) - 5.0f, dz = lh::RandomFloat(10.0f) - 5.0f;
    return MapCoords(f->coords.x + static_cast<int32_t>(dx * kMapUnitsPerMetre),
                     f->coords.z + static_cast<int32_t>(dz * kMapUnitsPerMetre), f->coords.altitude);
}
// Villager +0x114: the spot in the field it is working (sub_6E8E10 / sub_6E8EF0).
MapCoords& WorkSpot(Villager& v) { return v.work_spot; }

// sub_6E8DD0 -> sub_6E8E10: off to a field that needs planting or harvesting.
bool GoFarming(Villager& v, Field* field) {
    if (!field) return false;
    const int act = field->GetFieldActivity(0);
    if (act != 1 && act != 2) return false;
    SetState(v, VILLAGER_STATE_DECIDE_WHAT_TO_DO);
    v.target = field;
    MoveToObjectThen(v, field, VILLAGER_STATE_FARMER_ARRIVES_AT_FARM);
    WorkSpot(v) = FieldSpot(field);
    return true;
}

// vslot 535 (sub_6F...): standing on the spot. ponytail: within a metre.
bool AtSpot(const Villager& v, const MapCoords& p) { return DistanceM(v.coords, p) < 1.0f; }

// sub_6EA700: standing in the farm's cell.
bool AtFarm(const Villager& v, const Object* farm) {
    return (v.coords.x >> 16) == (farm->coords.x >> 16) && (v.coords.z >> 16) == (farm->coords.z >> 16);
}

// --- states -----------------------------------------------------------------

void MoveToPos(Villager& v) {  // 1, sub_5AAE80. ponytail: straight-line walking
    if (v.speed == 0) v.SetSpeed(static_cast<int>(InfoU(v, 260)) ? static_cast<int>(InfoU(v, 260)) : 200);
    v.MoveToGoal();  // stands in for the wall-hugging path code (sub_5C5BA0)
    if (v.move_state == MOVE_TO_STATES_ARRIVED) SetState(v, v.action.final_state);  // sub_5AB4E0
}

void Created(Villager& v) {  // 85, sub_6E38B0: wait out the timer, then decide
    if (v.turns_until_next_state_change-- == 0) {
        v.turns_until_next_state_change = 0;
        SetState(v, VILLAGER_STATE_DECIDE_WHAT_TO_DO);
    }
}

void DecideWhatToDo(Villager& v) {  // 163, vslot 561 (sub_6E1260)
    Town* t = v.GetTown();
    if (t && TownInEmergency(t)) { SetState(v, VILLAGER_STATE_GOTO_CONGREGATE_IN_TOWN_AFTER_EMERGENCY); return; }
    // ponytail: disciples (+0xE0 0x200/0x400, sub_6E13C0) and children
    // (sub_6E73E0) have their own deciders; not translated.
    SetState(v, VILLAGER_STATE_DECIDE_WHAT_TO_DO);
    if (HomeOrWork(v)) return;
    // sub_6E1380: carrying more than villager info +620 / +624 -> the store.
    if (v.resource_held[1] > static_cast<int16_t>(InfoU(v, 620)) ||
        v.resource_held[0] > static_cast<int16_t>(InfoU(v, 624))) {
        SetState(v, VILLAGER_STATE_GOTO_STORAGE_PIT_FOR_DROP_OFF);
        return;
    }
    RandomIdle(v);
}

void GoHome(Villager& v) {  // 36 / 121, sub_6EEF60(37, 238)
    if (Abode* home = v.GetHome()) {
        if (v.field_0xe0 & 4) SetState(v, VILLAGER_STATE_AT_HOME);
        else if (v.action.final_state != VILLAGER_STATE_ARRIVES_HOME) MoveToObjectThen(v, home, VILLAGER_STATE_ARRIVES_HOME);
        return;
    }
    Town* t = v.GetTown();
    if (!t) { SetState(v, VILLAGER_STATE_VAGRANT_START); return; }
    uint8_t arrive = v.action.top_state;
    MapCoords pos;
    if (DistanceM(v.coords, t->coords) <= 100.0f) {  // near town: somewhere to lie down
        pos = Around(v.coords, lh::RandomFloat(6.2831855f), lh::RandomFloat(8.0f) + 2.0f);
        arrive = VILLAGER_STATE_SLEEP_IN_TENT;  // ponytail: sub_6EF1D0's free-spot search
    } else {                                       // far: head for town
        const float a = Heading(t->coords, v.coords) + lh::RandomFloat(1.5707964f) - 0.785398f;
        pos = Around(t->coords, a, lh::RandomFloat(25.0f) + 10.0f);
    }
    MoveToPosThen(v, pos, arrive);
}

void ArrivesHome(Villager& v) {  // 37, sub_6EF610 (the parts that need no door or children)
    Abode* home = v.GetHome();
    if (!home) { SetState(v, VILLAGER_STATE_HOMELESS_START); return; }
    if (Hungry(v) && !home->IsFunctional()) { SetState(v, VILLAGER_STATE_DECIDE_WHAT_TO_DO); return; }
    v.field_0xe0 |= 4;  // sub_6E1B20: inside
    SetState(v, VILLAGER_STATE_AT_HOME);
}

void AtHome(Villager& v) {  // 38, sub_6EEBE0
    Town* t = v.GetTown();
    if (v.GetHome() && t && TownInEmergency(t)) { SetState(v, VILLAGER_STATE_GOTO_BED_AT_HOME); return; }
    // sub_6EEE30: sleep or eat at home when it presses (threshold x 0.9).
    if (SleepOrEat(v, InfoF(v, 908) * 0.9f)) return;
    if (HomeOrWork(v)) return;
    // sub_6EECE0: inside, one time in four stay put; otherwise go out.
    if ((v.field_0xe0 & 4) && lh::Random(4) == 0) {
        v.turns_until_next_state_change = 0;
        SetState(v, VILLAGER_STATE_GOTO_BED_AT_HOME);
        return;
    }
    v.field_0xe0 &= ~4u;
    RandomIdle(v);
}

void GotoBedAtHome(Villager& v) {  // 119, sub_6EF800: asleep for villager info +588 turns
    SetState(v, VILLAGER_STATE_SLEEPING_AT_HOME);
    v.turns_until_next_state_change = static_cast<int16_t>(InfoU(v, 588));
}

void SleepingAtHome(Villager& v) {  // 120, sub_6EFA40 -> sub_6EFA80
    if (!v.GetTown()) return;
    if (--v.turns_until_next_state_change > 0) return;
    // sub_6EFA80: still tired (below info +864) -> sleep another info +588 turns.
    if (v.life < InfoF(v, 864)) { v.turns_until_next_state_change = static_cast<int16_t>(InfoU(v, 588)); return; }
    SetState(v, VILLAGER_STATE_AT_HOME);
}

void GoAndChilloutOutsideHome(Villager& v) {  // 245, sub_6F9400
    Abode* home = v.GetHome();
    Town* t = v.GetTown();
    if (!home || !t) { SetState(v, VILLAGER_STATE_DECIDE_WHAT_TO_DO); return; }
    float r = 0;
    if (t->info) std::memcpy(&r, reinterpret_cast<const char*>(t->info) + 324, 4);
    // ponytail: sub_6F9620's spot choice; a point at that radius from home
    MoveToPosThen(v, Around(home->coords, Heading(home->coords, v.coords), r * 10.0f), VILLAGER_STATE_SIT_AND_CHILLOUT);
}

void SitAndChillout(Villager& v) {  // 246, sub_6F94F0
    if (v.turns_until_next_state_change-- > 0) return;
    v.turns_until_next_state_change = 0;
    Town* t = v.GetTown();
    if (t && TownInEmergency(t)) { SetState(v, VILLAGER_STATE_GOTO_CONGREGATE_IN_TOWN_AFTER_EMERGENCY); return; }
    if (HomeOrWork(v)) return;
    if (lh::Random(10) == 0) { RandomIdle(v); return; }
    v.turns_until_next_state_change = static_cast<int16_t>(InfoU(v, 918));
}

void GotoStoragePitForFood(Villager& v) {  // 33, sub_6F7880
    if (Abode* store = Store(v); Usable(store)) MoveToObjectThen(v, store, VILLAGER_STATE_ARRIVES_AT_STORAGE_PIT_FOR_FOOD);
    else SetState(v, VILLAGER_STATE_DECIDE_WHAT_TO_DO);  // ponytail: the town spot (sub_6E3900)
}

void ArrivesAtStoragePitForFood(Villager& v) {  // 34, 0x6F7900 -> 0x6F7920(food, need, 163, 163)
    // ponytail: without a store the original takes food from something in
    // town (sub_6D1550); and it checks it stands close enough (sub_6F8330).
    if (Abode* store = Store(v); Usable(store)) TakeFood(v, store, static_cast<uint32_t>(FoodNeeded(v)));
    SetState(v, VILLAGER_STATE_DECIDE_WHAT_TO_DO);
}

void EatFood(Villager& v) {  // 117, 0x6EAFF0 (poisoned -> 212 instead: never yet)
    Consume(v);
    SetState(v, VILLAGER_STATE_DECIDE_WHAT_TO_DO);
}

void EatFoodAtHome(Villager& v) {  // 118, 0x6EB080: top up from home, eat, AtHome
    const int more = FoodWanted(v) - v.resource_held[0];
    if (Abode* home = v.GetHome(); home && more > 0) TakeFood(v, home, static_cast<uint32_t>(more));  // sub_6EB030
    Consume(v);
    SetState(v, VILLAGER_STATE_AT_HOME);
}

void FishermanArrivesAtFishing(Villager& v) {  // 55, sub_6EA660
    Object* farm = v.target;
    if (!farm) { SetState(v, VILLAGER_STATE_DECIDE_WHAT_TO_DO); return; }
    if (!AtFarm(v, farm)) { MoveToObjectThen(v, farm, VILLAGER_STATE_FISHERMAN_ARRIVES_AT_FISHING); return; }
    // ponytail: sub_5C1400 / sub_6F1FF0 move it to a free spot first when its
    // own is taken; it fishes where it stands.
    SetState(v, VILLAGER_STATE_FISHING);
}

// The fishing cast's length. The original waits out the animation
// (sub_5AB3C0: turns x dword_C22D78 against the clip's length); we have no
// clip lengths in core yet.
constexpr uint16_t kFishingCastTurns = 20;  // ponytail: a stand-in for the clip length

void Fishing(Villager& v) {  // 56, sub_6EA730
    auto* farm = static_cast<FishFarm*>(v.target);
    if (!farm) { SetState(v, VILLAGER_STATE_DECIDE_WHAT_TO_DO); return; }
    if (v.action.turns_since_state_change < kFishingCastTurns) return;
    v.action.turns_since_state_change = 0;
    if (lh::Random(farm->villagers.count) != 0) return;  // one chance in (fishermen)
    // A catch: a quarter of a full load x the season (spring 1.0, summer 0.9,
    // autumn 0.7, winter 0.6, sub_529350) x the player's fishing skill (player
    // +104 + 4 x 7, vslot 434), no more than there is room for.
    // ponytail: spring always -- the season follows a game clock whose start
    // (GGameInfo +32) is set at runtime; and there are no players yet (skill 1).
    const float season = 1.0f;
    const float room = static_cast<float>(RoomToCarry(v));
    float catch_ = static_cast<float>(CarryCapacity(v)) * 0.25f * season;
    if (catch_ > room) catch_ = room;
    const int n = static_cast<int>(catch_);
    if (n) v.resource_held[0] = static_cast<int16_t>(v.resource_held[0] + n);  // sub_6E1180
    if (static_cast<float>(RoomToCarry(v)) < static_cast<float>(n) || RoomToCarry(v) == 0) GotoStoragePit(v);
}

void ArrivesAtFarm(Villager& v) {  // 67, sub_6E8EF0
    auto* field = static_cast<Field*>(v.target);
    const int act = field ? field->GetFieldActivity(0) : 0;
    // Planting, or digging up a crop that has finished growing (sub_4FFBD0).
    const bool dig = act == 2 && field->growth >= [&] { float x = 0; std::memcpy(&x, reinterpret_cast<const char*>(field->type_info) + 292, 4); return x; }();
    if (act != 1 && !dig) { SetState(v, VILLAGER_STATE_DECIDE_WHAT_TO_DO); return; }
    MapCoords& spot = WorkSpot(v);
    if (!AtSpot(v, spot)) { MoveToPosThen(v, spot, VILLAGER_STATE_FARMER_ARRIVES_AT_FARM); return; }
    spot = FieldSpot(field);  // the next spot
    SetState(v, act == 1 ? VILLAGER_STATE_FARMER_PLANTS_CROP : VILLAGER_STATE_FARMER_DIGS_UP_CROP);
}

void FarmerPlantsCrop(Villager& v) {  // 68, 0x6E9090
    auto* field = static_cast<Field*>(v.target);
    if (field && field->PlantCrop(v.coords) && field->GetPlantCropPos()) {
        MoveToPosThen(v, v.coords, VILLAGER_STATE_FARMER_ARRIVES_AT_FARM);  // sub_6F1FF0: on to the next spot
        return;
    }
    SetState(v, VILLAGER_STATE_DECIDE_WHAT_TO_DO);
}

void FarmerDigsUpCrop(Villager& v) {  // 69, sub_6E9010
    auto* field = static_cast<Field*>(v.target);
    if (!field) { SetState(v, VILLAGER_STATE_DECIDE_WHAT_TO_DO); return; }
    if (const int n = field->Harvest(static_cast<float>(RoomToCarry(v)))) {
        v.resource_held[0] = static_cast<int16_t>(v.resource_held[0] + n);  // sub_6E1180
        // A full load: less room left than mobile object 15's +104 (dword_C5A3E4).
        float load = 0;
        if (const char* e = static_cast<const char*>(infodat::Element(infodat::DETAIL_MOBILE_OBJECT_INFO, 15)))
            std::memcpy(&load, e + 104, 4);
        if (static_cast<float>(RoomToCarry(v)) < load) { GotoStoragePit(v); return; }
    }
    SetState(v, VILLAGER_STATE_FARMER_ARRIVES_AT_FARM);
}

void ArrivesAtStoragePitForDropOff(Villager& v) { ArrivesAtStoragePit(v); }  // 32

void Dying(Villager& v) { SetState(v, VILLAGER_STATE_DEAD); }  // 14, vslot 551 (sub_6F85B0)

}  // namespace
}  // namespace vs

bool VillagerSleepHandler(Villager* v) { return vs::SleepHandler(*v); }
bool VillagerFoodHandler(Villager* v) { return vs::FoodJob(*v); }

// vslot 392 (sub_6E01E0): the state, then the upkeep (sub_6E05D0) unless
// +0xE0 bit 11 asks for a timed transition instead. ponytail: the second
// state slot and the timed transitions are not translated; untranslated states
// hold, and after 300 turns fall back to deciding so a villager is never
// stranded.
uint32_t Villager::ProcessState() {
    ++action.turns_since_state_change;
    switch (action.top_state) {
    case VILLAGER_STATE_MOVE_TO_POS: vs::MoveToPos(*this); break;
    case VILLAGER_STATE_CREATED: vs::Created(*this); break;
    case VILLAGER_STATE_DECIDE_WHAT_TO_DO: vs::DecideWhatToDo(*this); break;
    case VILLAGER_STATE_GO_HOME:
    case VILLAGER_STATE_WAKE_UP_AT_HOME: vs::GoHome(*this); break;
    case VILLAGER_STATE_ARRIVES_HOME: vs::ArrivesHome(*this); break;
    case VILLAGER_STATE_AT_HOME: vs::AtHome(*this); break;
    case VILLAGER_STATE_GOTO_BED_AT_HOME: vs::GotoBedAtHome(*this); break;
    case VILLAGER_STATE_SLEEPING_AT_HOME: vs::SleepingAtHome(*this); break;
    case VILLAGER_STATE_GO_AND_CHILLOUT_OUTSIDE_HOME: vs::GoAndChilloutOutsideHome(*this); break;
    case VILLAGER_STATE_SIT_AND_CHILLOUT: vs::SitAndChillout(*this); break;
    case VILLAGER_STATE_GOTO_STORAGE_PIT_FOR_DROP_OFF: vs::GotoStoragePit(*this); break;
    case VILLAGER_STATE_ARRIVES_AT_STORAGE_PIT_FOR_DROP_OFF: vs::ArrivesAtStoragePitForDropOff(*this); break;
    case VILLAGER_STATE_FISHERMAN_ARRIVES_AT_FISHING: vs::FishermanArrivesAtFishing(*this); break;
    case VILLAGER_STATE_FISHING: vs::Fishing(*this); break;
    case VILLAGER_STATE_FARMER_ARRIVES_AT_FARM: vs::ArrivesAtFarm(*this); break;
    case VILLAGER_STATE_FARMER_PLANTS_CROP: vs::FarmerPlantsCrop(*this); break;
    case VILLAGER_STATE_FARMER_DIGS_UP_CROP: vs::FarmerDigsUpCrop(*this); break;
    case VILLAGER_STATE_GOTO_STORAGE_PIT_FOR_FOOD: vs::GotoStoragePitForFood(*this); break;
    case VILLAGER_STATE_ARRIVES_AT_STORAGE_PIT_FOR_FOOD: vs::ArrivesAtStoragePitForFood(*this); break;
    case VILLAGER_STATE_EAT_FOOD: vs::EatFood(*this); break;
    case VILLAGER_STATE_EAT_FOOD_AT_HOME: vs::EatFoodAtHome(*this); break;
    case VILLAGER_STATE_DYING: vs::Dying(*this); break;
    case VILLAGER_STATE_DEAD: break;  // ponytail: the body's removal (vslot 552, sub_6F8620) is not translated
    default:
        if (action.turns_since_state_change > 300) vs::SetState(*this, VILLAGER_STATE_DECIDE_WHAT_TO_DO);
        break;
    }
    if (!(field_0xe0 & 0x800)) vs::Upkeep(*this);
    return 1;
}
