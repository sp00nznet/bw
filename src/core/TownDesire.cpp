// TownDesire — the 17 town desires, v1.0 (TownDesire::Process sub_6D7950).
// docs/town-economy.md has the table of desires and what is not yet translated.
//
// The desire functions run against the Town, at v1.0 offsets: the stats block
// at +0x608 is read through At<>() rather than TownStats' field names, several
// of which are v1.41 guesses (a "vtable" sits where v1.0 keeps a byte array).
#include "../include/black/TownDesire.h"

#include "../include/black/Abode.h"
#include "../include/black/InfoDat.h"
#include "../include/black/MultiMapFixed.h"
#include "../include/black/Town.h"
#include "../include/black/Villager.h"

#include <algorithm>
#include <cstdlib>
#include <cstring>

extern uint32_t g_game_turn;  // LevelLoader.cpp

namespace {

template <class T> T At(const void* base, int off) {
    T v; std::memcpy(&v, static_cast<const char*>(base) + off, sizeof v); return v;
}
float InfoF(const void* info, int off) { return info ? At<float>(info, off) : 0.0f; }

// The town's numbers the desires read (v1.0 offsets).
uint32_t Adults(const Town* t)    { return At<uint32_t>(t, 0x610); }  // [388]
uint32_t Children(const Town* t)  { return At<uint32_t>(t, 0x614); }  // [389]
uint32_t AdultRoom(const Town* t) { return At<uint32_t>(t, 0x63C); }  // [399]
uint32_t ChildRoom(const Town* t) { return At<uint32_t>(t, 0x648); }  // [402]

// The town's storage pit when it is alive (sub_6CE860), and resources in it.
Object* Store(Town* t) {
    Object* pit = reinterpret_cast<Object*>(t->storage_pit_list);
    return pit && pit->IsAvailable() ? pit : nullptr;
}
uint32_t StoreHas(Town* t, int type, int alt_off) {
    if (Object* s = Store(t)) return s->GetResource(static_cast<RESOURCE_TYPE>(type));
    Object* alt = At<Object*>(t, alt_off);
    return alt ? alt->GetResource(static_cast<RESOURCE_TYPE>(type)) : 0;
}
// sub_6D9590 / sub_6D9600: carried plus stored.
uint32_t FoodAvailable(Town* t) {
    return static_cast<uint32_t>(At<float>(t, 0x700)) + StoreHas(t, 0, 0x5F8);
}
uint32_t WoodAvailable(Town* t) {
    return static_cast<uint32_t>(At<float>(t, 0x708) + At<float>(t, 0x704)) + StoreHas(t, 1, 0x5FC);
}
// sub_6D95F0: TownInfo +220 x the town's summed per-villager food (+0x6EC).
float FoodNeeded(Town* t) { return InfoF(t->info, 220) * At<float>(t, 0x6EC); }
// sub_6D96E0 / sub_6D9660: TownInfo +224 / +228, scaled up once the abode
// count passes TownInfo +232.
float WoodNeeded(Town* t, int off) {
    const float r = static_cast<float>(t->abode_list.count) / InfoF(t->info, 232);
    return (r <= 1.0f ? 1.0f : r) * InfoF(t->info, off);
}

const char* DesireInfo(int k) {
    return static_cast<const char*>(infodat::Element(infodat::DETAIL_TOWN_DESIRE_INFO, k));
}
float Clamp01(float v) { return v < 0 ? 0 : v > 1 ? 1 : v; }

// sub_6D1080: a desire as everyone else reads it (desire + boost + cheat);
// sub_6D10A0: the same from the raw value.
float Total(const TownDesire& d, int k) { return d.desire[k] + d.boost[k] + d.cheat[k]; }
float RawTotal(const TownDesire& d, int k) { return d.raw[k] + d.boost[k] + d.cheat[k]; }

// --- the 17 raw desire functions (table at 0xCC3F60, +16) -----------------

float Food(Town* t) {  // Town vslot 264 (sub_6D9980)
    const float have = static_cast<float>(FoodAvailable(t)) + 0.0001f;
    return Clamp01(1.0f - have / (FoodNeeded(t) + 0.0001f));
}
float Wood(Town* t) {  // sub_6D9A70
    const TownDesire& d = t->desire;
    float building = 0;
    for (int k : {5, 6, 9, 12}) building += d.cheat[k] + d.boost[k] + d.raw[k];
    if (building > 3.0f) building = 3.0f;
    const float foresters = (At<uint8_t>(t, 0x6D8) + 0.001f) / (Adults(t) + 0.001f);
    const float have = static_cast<float>(WoodAvailable(t));
    const float a = std::min(1.0f, have / WoodNeeded(t, 224));
    const float b = std::min(1.0f, have / WoodNeeded(t, 228));
    return Clamp01((1.0f - b) * (1.0f - a + foresters + building));
}
float Playtime(Town* t) {  // sub_6DA1C0: only when nothing basic is wanted, after turn 4000

    for (int k : {0, 1, 5, 6, 9})
        if (Total(t->desire, k) >= At<float>(DesireInfo(k), 24)) return 0.0f;
    return g_game_turn > 4000 ? 0.1f : 0.0f;
}
float Protection(Town* t) { return At<float>(t, 0xEB8); }  // sub_6DA2B0: [942]
float Mercy(Town* t)      { return At<float>(t, 0xEB4); }  // sub_6DA2C0: [941]
float Abodes(Town* t) {  // sub_6D9C90
    const float a = std::min(1.5f, Adults(t) / (AdultRoom(t) + 0.00001f));
    const float c = std::min(1.5f, Children(t) / (ChildRoom(t) + 0.00001f));
    const float crowd = std::max(a, c);
    return Clamp01((1.0f - Total(t->desire, 6)) * (1.0f - RawTotal(t->desire, 9)) * crowd * crowd * crowd * crowd);
}
float CivicBuildings(Town* t) {  // sub_6D9DA0
    const uint32_t pop = Adults(t) + Children(t);
    const uint32_t homeless = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(t->homeless_list.last));
    float want = 0;
    for (int i = 0; i < 16; ++i) {
        if (At<uint8_t>(t, 0x710 + i)) continue;  // already has one
        // sub_4041D0: the abode info of this tribe and abode number i (or any tribe)
        int32_t needed = -1;
        for (uint32_t e = 0; e < infodat::Count(infodat::DETAIL_ABODE_INFO); ++e) {
            const char* ai = static_cast<const char*>(infodat::Element(infodat::DETAIL_ABODE_INFO, e));
            const int32_t tribe = At<int32_t>(ai, 0x158), number = At<int32_t>(ai, 0x124);
            if ((tribe == static_cast<int32_t>(t->tribe_type) || tribe == -1) && number == i) {
                needed = At<int32_t>(ai, 0x1B4);  // populationWhenNeeded
                break;
            }
        }
        if (needed > -1 && (needed == 0 || (pop && static_cast<float>(homeless) / pop < 0.2f)) &&
            static_cast<uint32_t>(needed) <= pop)
            want += ((pop - needed) + 0.001f) / (needed + 0.001f) * 0.5f + 0.5f;
    }
    return std::min(1.0f, want);
}
float Zero(Town*) { return 0.0f; }  // sub_6DA0C0: Supply_Worship, For_Rain, For_Sun, Supply_Workshop
float ForChildren(Town* t) {  // sub_6D9EA0
    const TownDesire& d = t->desire;
    const float food = RawTotal(d, 0);
    const float fed = food >= 1.0f ? 0.0f : food <= 0.0f ? 1.0f : 1.0f - food;
    const float child_room = Children(t) >= ChildRoom(t) ? 0.0f : 1.0f;
    const float adult_room = Adults(t) >= AdultRoom(t) ? 0.5f : 1.0f;
    const float safe = (1.0f - std::max(0.0f, Total(d, 4))) * (1.0f - std::max(0.0f, Total(d, 3)));
    // ponytail: with a player, x (player float^3 x 0.5 + 1) and the player's
    // per-desire factor (sub_5FA5C0, sub_6D1260); no GPlayers yet, so 1.
    float v = 1.0f * safe * adult_room * child_room * fed;
    if (!t->creche || !reinterpret_cast<Abode*>(t->creche)->IsFunctional()) v *= 0.5f;
    return Clamp01(v);
}
float ToBuild(Town*) {  // sub_6DA070: sum of building-site progress (sub_434560)
    return 0.0f;  // ponytail: building sites (+0x788) are not created yet
}
float RepairTown(Town* t) {  // sub_6DA0D0: abodes' and planned buildings' repair desire
    float v = 0;
    for (Abode* a = reinterpret_cast<Abode*>(t->abode_list.head); a; a = a->next) v += a->GetDesireToBeRepaired();
    // ponytail: + the planned list (+0x9A0, vslot 325); nothing is planned yet
    return std::min(1.0f, v);
}
float ForWonder(Town*) {  // sub_6DA150: x the town's belief in its player (sub_6CEC90)
    return 0.0f;  // ponytail: needs the player; 0 until GPlayers exist
}
// Relaxation / Sleep read the time of day (flt_B201CC), which we do not run.
// ponytail: noon until a game clock exists.
float Hour() { return 12.0f; }
float Relaxation(Town* t) {  // sub_6DA2D0 (night falloff sub_5293B0 approximated: daytime)
    (void)Hour();
    const float v = InfoF(t->info, 236) * 0.5f;
    return std::min(1.0f, std::max(0.1f, v));
}
float Sleep(Town* t) {  // sub_6DA370
    const float v = std::max(0.0f, Hour() / 24.0f - InfoF(t->info, 216));
    return v * v;
}

using RawFn = float (*)(Town*);
const RawFn kRaw[17] = {Food, Wood, Playtime, Protection, Mercy, Abodes, CivicBuildings, Zero,
                        ForChildren, ToBuild, Zero, Zero, RepairTown, Zero, ForWonder,
                        Relaxation, Sleep};

// --- multipliers (+80): how far the town is from covering the need ---------

float VillagerCarry(int off) {  // 150 food / 250 wood per villager (dword_CC9F4C / CC9F50)
    const char* v = static_cast<const char*>(infodat::Element(infodat::DETAIL_VILLAGER_INFO, 10));
    return v ? static_cast<float>(At<uint32_t>(v, off)) : 0.0f;
}
float FoodMult(Town* t, int k) {  // sub_6D7F50
    const float coming = VillagerCarry(612) * t->desire.state_amount[k] + 0.0001f;
    const float stored = Store(t) ? static_cast<float>(Store(t)->GetResource(static_cast<RESOURCE_TYPE>(0))) : 0.0f;
    return 1.0f - std::min(1.0f, (stored + coming) / (FoodNeeded(t) + 0.0001f));
}
float WoodMult(Town* t, int k) {  // sub_6D8000
    const float coming = VillagerCarry(616) * t->desire.state_amount[k] + 0.0001f;
    const float stored = Store(t) ? static_cast<float>(Store(t)->GetResource(static_cast<RESOURCE_TYPE>(1))) : 0.0f;
    return 1.0f - std::min(1.0f, (stored + coming) / (WoodNeeded(t, 228) + 0.0001f));
}
float PeopleMult(Town* t, int k) {  // sub_6D8140: villagers already on it, of everyone
    return 1.0f - std::min(1.0f, t->desire.state_amount[k] / ((Adults(t) + Children(t)) + 0.00001f));
}
float BuildMult(Town*, int) {  // sub_6D80B0: builders on sites / builders wanted
    return 1.0f;  // ponytail: no building sites yet (sum over +0x788 is 0/0 -> 1 - 1e-4/1e-4)
}
using MultFn = float (*)(Town*, int);
const MultFn kMult[17] = {FoodMult, WoodMult, PeopleMult, PeopleMult, PeopleMult, PeopleMult,
                          PeopleMult, PeopleMult, PeopleMult, BuildMult, PeopleMult, PeopleMult,
                          PeopleMult, PeopleMult, PeopleMult, PeopleMult, PeopleMult};

}  // namespace

TownDesire::~TownDesire() {}

GTownDesireInfo* TownDesire::GetInfo(uint32_t index) const {
    return static_cast<GTownDesireInfo*>(const_cast<void*>(infodat::Element(infodat::DETAIL_TOWN_DESIRE_INFO, index)));
}

void TownDesire::Process() {
    // sub_6D7950.
    Town* t = town;
    if (!t) return;
    // Villagers free for work: everyone, less those at +0x5CC and worshipping (+0x5C4).
    free_villagers = static_cast<float>(Adults(t) + Children(t) - At<uint32_t>(t, 0x5CC) - At<uint32_t>(t, 0x5C4));

    for (int k = 0; k < 17; ++k) {  // sub_6D7B10
        if (state_amount[k] < 0) state_amount[k] = 0;
        prev_state_amount[k] = state_amount[k];
        prev_state_count[k] = state_count[k];
        // +32/+48 (Abodes, Civic, Worship): have/want counts.
        // ponytail: Abodes' pair is stats [390] and its fill ratio (sub_6D9780);
        // Civic's [393]/[395]; Worship's needs the worship site. Read raw here.
        if (k == 5) { count_a[k] = static_cast<float>(At<uint32_t>(t, 0x618)); }
        if (k == 6) { count_a[k] = static_cast<float>(At<uint32_t>(t, 0x624)); count_b[k] = static_cast<float>(At<uint32_t>(t, 0x62C)); }
        // sub_6D7BF0: raw x tribe weight, then x the multiplier, into [-1, 1].
        const char* info = DesireInfo(k);
        const int tribe = static_cast<int>(t->tribe_type);
        const float weight = info && tribe >= 0 && tribe < 9 ? At<float>(info, 88 + 4 * tribe) : 0.0f;
        raw[k] = weight * kRaw[k](t);
        desire[k] = std::max(-1.0f, std::min(1.0f, kMult[k](t, k) * raw[k]));
    }

    // sub_6D7E80 / sub_6D7ED0: the desires sorted by total, and by raw total.
    for (int k = 0; k < 17; ++k) {
        sorts[k] = {0, 0, static_cast<TOWN_DESIRE_INFO>(k)};
        float extra = boost[k] + cheat[k];
        std::memcpy(&sorts[k].field_0x0, &extra, 4);
        sorts[k].field_0x4 = desire[k] + extra;
        sorts2[k] = {0, raw[k] + extra, static_cast<TOWN_DESIRE_INFO>(k)};
        std::memcpy(&sorts2[k].field_0x0, &cheat[k], 4);
    }
    auto desc = [](const DesireSort& a, const DesireSort& b) { return a.field_0x4 > b.field_0x4; };
    std::stable_sort(sorts, sorts + 17, desc);
    std::stable_sort(sorts2, sorts2 + 17, desc);
    // not yet: every 50 turns the player's advisor commentary (needs a player).
}

// The villager handler for each desire (table +64): the villager-side answer.
// ponytail: only Food and Sleep are translated; Relaxation's (sub_6EFF60) asks the town
// for a place to relax (Town vslot 20), which needs objects we do not create;
// the job handlers (food, wood, building, ...) come next.
bool VillagerSleepHandler(Villager* v);  // VillagerStates.cpp, sub_6EFF90
bool VillagerFoodHandler(Villager* v);   // VillagerStates.cpp, sub_6E9100
namespace {
using Handler = bool (*)(Villager*);
const Handler kHandler[17] = {VillagerFoodHandler, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
                              nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
                              VillagerSleepHandler};
// Table +96: desires a child may be given (from the table at 0xCC3F60).
const bool kChildOk[17] = {false};
}  // namespace

bool TownDesire::FindWorkForVillager(Villager* v, float busy) {
    // sub_6D7D30. Walk the ranking (sorts); a desire is offered when its total,
    // scaled by how few villagers already work it (sub_6D81A0), beats the
    // desire's threshold (info +24) plus how busy the villager already is.
    if (busy == 0.0f) busy = 0.001f;
    const bool child = v->IsChild();
    for (int rank = 0; rank < 17; ++rank) {
        const int k = static_cast<int>(sorts[rank].field_0x8);
        const char* info = static_cast<const char*>(infodat::Element(infodat::DETAIL_TOWN_DESIRE_INFO, k));
        const float threshold = std::min(1.0f, busy + (info ? At<float>(info, 24) : 0.0f));
        if ((!child || kChildOk[k]) && kHandler[k]) {
            // sub_6D81A0: 1 - (villagers newly on it this turn) / everyone
            float added = state_amount[rank] - prev_state_amount[rank];
            if (added < 0) added = 0;
            const float everyone = static_cast<float>(Adults(town) + Children(town)) + 0.00001f;
            const float rank_factor = 1.0f - std::min(1.0f, added / everyone);
            if (rank_factor * sorts[rank].field_0x4 <= threshold) return false;
            if (kHandler[k](v)) return true;
        }
    }
    return false;
}
