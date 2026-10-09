// Town class implementation
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)
// Cross-referenced with bw1-decomp (v1.20)
//
// Town is the largest class in the game (0xF28 bytes).
// Manages population, desires, buildings, fields, worship,
// resources, and player interaction.

#include <black/Town.h>
#include <black/BuildingSite.h>
#include <black/EntityFactory.h>
#include <black/PlannedAbode.h>
#include <black/PlannedTownCitadelHeart.h>
#include <black/BigForest.h>
#include <black/Forest.h>
#include <black/Abode.h>
#include <black/StoragePit.h>
#include <black/Player.h>
#include <black/Villager.h>
#include <black/Game.h>
#include <black/InfoDat.h>
#include <black/WorshipSite.h>
#include <cmath>
#include <cstdlib>
#include <cstring>

extern GGame* g_game;

// ============================================================================
// Overrides of Base virtuals
// ============================================================================

void Town::ToBeDeleted(int /*param*/) {
    // Original at 0x00739970 — complex cleanup
}

// ============================================================================
// Overrides of GameThing virtuals
// ============================================================================

Town* Town::GetTown() {
    // Original at 0x007391e0: returns this
    return this;
}

float Town::GetVillagerActivityDesire(Villager* /*villager*/) {
    // Original at 0x0073ff00 — complex
    return 0.0f;
}

void Town::SetVillagerActivity(Villager* /*villager*/) {
    // Original at 0x0073ff10 — complex
}

float Town::GetRadius() {
    // v1.0 Town vslot 24 (sub_6D0540), from the disassembly: half the larger of
    // the bounding box's whole-metre width and depth.
    const int dx = std::abs(static_cast<int>(MetresOf(field_0x734.x) - MetresOf(field_0x728.x)));
    const int dz = std::abs(static_cast<int>(MetresOf(field_0x734.z) - MetresOf(field_0x728.z)));
    return static_cast<float>(dx > dz ? dx : dz) * 0.5f;
}

uint16_t Town::GetNumberOfInstanceForGlobalList() {
    // Original at 0x0073af80 — returns population count for global list
    return static_cast<uint16_t>(stats.num_adults + stats.num_children);
}

char* Town::GetDebugText() {
    // Original at 0x007392a0
    static char text[] = "Town";
    return text;
}

uint32_t Town::Load(GameOSFile* /*file*/) {
    // Original at 0x0073f450 — complex serialization
    return 0;
}

uint32_t Town::Save(GameOSFile* /*file*/) {
    // Original at 0x0073ed30 — complex serialization
    return 0;
}

uint32_t Town::GetSaveType() {
    // Original at 0x00739290: mov eax, 0x28; ret
    return 0x28;
}

void Town::ResolveLoad() {
    // Original at 0x007412e0 — complex post-load resolution
}

// ============================================================================
// Overrides of GameThingWithPos virtuals
// ============================================================================

uint32_t Town::GetCreatureBeliefType() {
    // Original at 0x007391f0
    return 0;
}

uint32_t Town::GetCreatureBeliefListType() {
    // Original at 0x00739200
    return 0;
}

Citadel* Town::GetCitadel() {
    // Original at 0x0073bc40 — complex citadel lookup
    // Traverse town structure list to find the associated citadel
    return nullptr;
}

uint32_t Town::GetOrigin() {
    // Original at 0x007391d0 — returns the tribe type
    return static_cast<uint32_t>(tribe_type);
}

bool Town::IsTown_0() {
    // Original at 0x00739250: returns true
    return true;
}

bool Town::IsTown_1(Creature* /*creature*/) {
    // Original at 0x00739220: returns true
    return true;
}

bool Town::IsActivityObjectWhichAngerAppliesTo(Creature* /*creature*/) {
    // Original at 0x004e47f0 — complex
    return false;
}

bool Town::IsActivityObjectWhichCompassionAppliesTo(Creature* /*creature*/) {
    // Original at 0x00739230: returns true
    return true;
}

bool Town::IsActivityObjectWhichPlayfulnessAppliesTo(Creature* /*creature*/) {
    // Original at 0x00739240: returns true
    return true;
}

bool Town::IsTownBelongingToAnotherPlayer(Creature* /*creature*/) {
    // Original at 0x004e4750 — complex
    return false;
}

bool32_t Town::IsSuitableForCreatureActivity() {
    // Original at 0x00739260: returns 1
    return 1;
}

bool32_t Town::CanBePlayedWithByCreature(Creature* /*creature*/) {
    // Original at 0x00739270: returns 1
    return 1;
}

WorshipSite* Town::GetWorshipSite() { return worship_site; }  // v1.0 sub_6CFAA0

bool32_t Town::IsTownBelongingToOtherPlayer(Creature* /*creature*/) {
    // Original at 0x004e4140 — complex
    return 0;
}

bool32_t Town::IsScriptContainer() const {
    // Original at 0x00739210: returns 1
    return 1;
}

const char* Town::GetText() {
    // Original at 0x00739280 — returns field_0x5b0
    return field_0x5b0;
}

float Town::CalculateDesireForFood() {
    // Original at 0x00747f00 — food desire based on population vs food supply
    if (stats.num_adults <= 0) return 0.0f;
    float food_per_person = stats.total_food / static_cast<float>(stats.num_adults);
    if (food_per_person >= 10.0f) return 0.0f;  // Well fed
    return 1.0f - (food_per_person / 10.0f);    // Linear desire
}

uint32_t Town::GetScriptObjectType() {
    // Original at 0x0073e200: mov eax, 0x09; ret
    return 0x9;
}

// ============================================================================
// Static methods
// ============================================================================

Town* Town::GetNearestTownToPos(const MapCoords& /*coords*/, TRIBE_TYPE /*tribe_type*/,
                                 ABODE_TYPE /*abode_type*/, float /*max_distance*/) {
    // Original at 0x0073b170 — complex
    return nullptr;
}

void Town::AsssignTownFeature() {
    // Original at 0x0073eac0 — complex
}

bool Town::FindClearArea(MapCoords& /*p1*/, MapCoords& /*p2*/, float /*p3*/, float /*p4*/,
                          float /*p5*/, ObjectCompareFunc /*callback*/, Object* /*obj*/) {
    // Original at 0x007412f0 — complex
    return false;
}

bool Town::CheckForClearArea(MapCoords& /*p1*/, float /*p2*/,
                              ObjectCompareFunc /*callback*/, Object* /*obj*/) {
    // Original at 0x007413d0 — complex
    return false;
}

// ============================================================================
// Non-virtual methods
// ============================================================================

void Town::AddStructureToTown(MultiMapFixed* structure) {
    // v1.0 sub_6CD6B0: an abode goes on the town's abode list (+0x74C, link at
    // abode +0x9C, count +0x750); every structure is told its town (vslot 572)
    // and the town's bounds are recomputed (sub_6CE1E0).
    // ponytail: not yet the turn stamp at +0x6E8 or the spell-icon pass when
    // +0x988 is set; both need systems we don't run.
    if (!structure) return;
    if (Abode* abode = reinterpret_cast<GameThing*>(structure)->CastAbode()) {
        abode->next = reinterpret_cast<Abode*>(abode_list.head);
        abode_list.head = abode;
        ++abode_list.count;
    }
    structure->SetTown(this);
    RecalculateBounds();
}

// sub_6CE1E0's first half: the min/max of every abode's position +/- its radius,
// in map units (+0x720 min, +0x72C max). The original also folds in the list
// at +0x778 and then derives a bounding sphere; neither is done here yet.
void Town::RecalculateBounds() {
    field_0x728 = MapCoords(0x7FFFFFFF, 0x7FFFFFFF, 0.0f);
    field_0x734 = MapCoords(0, 0, 0.0f);
    for (Abode* a = reinterpret_cast<Abode*>(abode_list.head); a; a = a->next) {  // sub_6CE380
        const float r = a->GetRadius();
        const float x = MetresOf(a->coords.x), z = MetresOf(a->coords.z);
        if (x - r < MetresOf(field_0x728.x)) field_0x728.x = static_cast<int32_t>((x - r) * kMapUnitsPerMetre);
        if (x + r > MetresOf(field_0x734.x)) field_0x734.x = static_cast<int32_t>((x + r) * kMapUnitsPerMetre);
        if (z - r < MetresOf(field_0x728.z)) field_0x728.z = static_cast<int32_t>((z - r) * kMapUnitsPerMetre);
        if (z + r > MetresOf(field_0x734.z)) field_0x734.z = static_cast<int32_t>((z + r) * kMapUnitsPerMetre);
    }
}

void Town::AddAbodeToTownStats(Abode* /*abode*/) {
    // Original at 0x00739a20 — complex
}

bool Town::AddVillagerToTown(Villager* villager) {
    // v1.0 sub_6CD8E0. Refused while uninhabitable (+0x5F4); counted; the
    // villager's town set. A home in another town is left; then the best abode
    // with space takes it, or it is homeless here.
    if (!villager || field_0x5f4) return false;
    stats.AddVillager(villager);
    villager->SetTown(this);
    Abode* home = villager->GetHome();
    if (home && home->GetTown() == this) return true;
    if (home) {
        home->RemoveAliveVillagerFromAbode(villager);
        villager->SetHome(nullptr);
        villager->SetTown(this);
    }
    if (Abode* a = FindAbodeWithSpaceInTown(villager, 0.0f)) {
        a->AddVillagerToAbode(villager);
        return true;
    }
    villager->BecomeHomeless();
    return true;
}

PlannedMultiMapFixed* Town::GetBestPlanned(float& /*score*/, ABODE_TYPE /*type*/) {
    // Original at 0x0073a140 — complex
    return nullptr;
}

float Town::GetDesireToBeBuilt(const GMultiMapFixedInfo* /*info*/, unsigned long /*param*/) {
    // Original at 0x0073a1a0 — complex
    return 0.0f;
}

bool32_t Town::RequestBestPlanned() {
    // Original at 0x0073a650 — complex
    return 0;
}

void Town::ChildToAdult(Villager* villager) {
    // Original at 0x0073af50: delegates to stats.ChildToAdult
    // ecx = this + 0x610 (stats offset), push villager, call TownStats::ChildToAdult
    stats.ChildToAdult(villager);
}

bool Town::IsHarvestTime() {
    // Original at 0x0073b2d0 — checks if it's harvest season
    // Harvest happens when food_for_harvest > threshold
    return stats.total_food > 0.0f;
}

bool32_t Town::RequestANewAbode(ABODE_TYPE /*type*/) {
    // Original at 0x0073b330 — complex
    return 0;
}

Abode* Town::FindAbodeWithSpaceInTown(Villager* villager, float min_score) {
    // v1.0 sub_6CE7D0: the functional abode scoring highest above min_score.
    // Score (sub_403670): room left for the villager's kind (adults against
    // maxAdults +0x174, children against maxChildren +0x178), times how few of
    // the same sex already live there, times nearness (500 m scale).
    // ponytail: vslot 53 also asks vslot 548, untranslated; distance falloff
    // (sub_6DF670) read as 1 - d/500 clamped.
    Abode* best = nullptr;
    for (Abode* a = reinterpret_cast<Abode*>(abode_list.head); a; a = a->next) {
        if (!a->IsFunctional() || !a->info) continue;
        const char* ai = reinterpret_cast<const char*>(a->info);
        int32_t cap; uint8_t have;
        if (villager->IsChild()) { std::memcpy(&cap, ai + 0x178, 4); have = a->field_0xb7; }
        else                     { std::memcpy(&cap, ai + 0x174, 4); have = a->adult_count; }
        if (cap <= 0) continue;
        float fill = static_cast<float>(have) / static_cast<float>(cap);
        if (fill > 1.0f) fill = 1.0f;
        const float room = 1.0f - fill;
        if (room <= 0.0f) continue;
        float same = 0, n = static_cast<float>(a->villagers.count);
        for (Villager* v = static_cast<Villager*>(a->villagers.head); v; v = v->next_villager)
            if (v->Sex() == villager->Sex()) same += 1;
        const float sex_factor = n > 0 ? (1.0f - same / n + 1.0f) * 0.5f : 1.0f;
        const float dx = MetresOf(a->coords.x - villager->coords.x), dz = MetresOf(a->coords.z - villager->coords.z);
        float near = 1.0f - std::sqrt(dx * dx + dz * dz) / 500.0f;
        if (near < 0) near = 0;
        const float score = (near + 1.0f) * 0.5f * sex_factor * room;
        if (score > min_score) { min_score = score; best = a; }
    }
    return best;
}

Field* Town::FindClosesFieldToWithFood(const MapCoords& /*pos*/) {
    // Original at 0x0073b3d0 — complex
    return nullptr;
}

bool32_t Town::IsVillagerInHomelessList(Villager* villager) {
    // Original at 0x0073b580 — check homeless linked list
    if (!villager) return 0;
    // Iterate LHLinkedList: first/last are at field offsets
    Villager* curr = static_cast<Villager*>(homeless_list.first);
    while (curr) {
        if (curr == villager) return 1;
        curr = curr->next_villager;
    }
    return 0;
}

StoragePit* Town::GetStoragePit() {
    // Original at 0x0073b5b0: returns storage_pit_list
    return storage_pit_list;
}

void Town::Birthday() {
    // Original at 0x0073b5d0 — ages villagers, triggers births
    // Simplified: births occur when population has capacity and resources
    // Iterates villager list: check pregnant timers, spawn children
    // Ages children to adults when age timer expires
}

BuildingSite* Town::AddBuildingSite(PlannedMultiMapFixed* /*planned*/) {
    // Original at 0x0073b860 — complex
    return nullptr;
}

BuildingSite* Town::AddBuildingSiteNoFixedCheck(PlannedMultiMapFixed* /*planned*/) {
    // Original at 0x0073b8a0 — complex
    return nullptr;
}

// v1.0 sub_6CEC00: the building's site is deleted (vslot 3). Ours does not
// delete itself, so it leaves the list here.
uint32_t Town::RemoveBuildingSite(MultiMapFixed* structure) {
    BuildingSite* s = SiteFor(structure);
    if (!s) return 0;
    s->ToBeDeleted(0);
    building_site_list.Remove(s);
    return 1;
}

void Town::SetBeliefInPlayer(GPlayer* player, float value) {
    // Original at 0x0073ba70 — set the town's belief in a given player
    if (!player) return;
    uint8_t player_num = player->GetPlayerNumber();
    belief.SetBelief(player_num, value);
}

// v1.0 sub_6CF1C0: kept only while the town has a worship site.
// ponytail: the town centre's totem (sub_6CC0B0 / sub_6CC2B0) and calling
// the extra worshippers in (sub_6CF250) are not translated; villagers ask
// for themselves when they look for something to do (sub_6F99B0).
void Town::SetWorshipPercentage(float percentage) {
    worship_percentage = GetWorshipSite() ? percentage : 0.0f;
}

void Town::AdjustWorshipersWorshipping(long /*param1*/, int /*param2*/, int /*param3*/) {
    // Original at 0x0073c0f0 — complex
}

GTribeInfo* Town::GetTribe() const {
    // Original at 0x0073c840: returns tribe info from game data
    if (g_game) {
        return g_game->GetTribe(tribe_type);
    }
    return nullptr;
}

// v1.0 sub_6CF9C0: the worshippers wanted (the percentage of the people,
// at least one, plus the site's extra +0x124) less those worshipping (+0x5C4)
// and, with on_way, those walking there (+0x5CC). *full: more are wanted
// though the percentage alone is met.
int Town::GetWorshipersNeeded(int on_way, int site_extra, int* full) {
    const int have = static_cast<int>(worship_count) + (on_way ? worshippers_on_way : 0);
    WorshipSite* ws = site_extra ? GetWorshipSite() : nullptr;
    const int extra = ws ? ws->num_villagers_requesting_to_go_home : 0;
    int want = 0;
    if (worship_percentage > 0.0f) {
        want = static_cast<int>(static_cast<float>(stats.num_adults + stats.num_children) * worship_percentage + 0.5f);
        if (want <= 1) want = 1;
    }
    const int r = extra + want - have;
    if (full) *full = r > 0 && have >= want;
    return r;
}

bool32_t Town::IsBuildingSiteValid(BuildingSite* /*site*/) {
    // Original at 0x0073cf00 — complex
    return 0;
}

bool32_t Town::GetBestBuildingSite(const MapCoords& /*pos*/, int /*param*/) {
    // Original at 0x0073cf60 — complex
    return 0;
}

void Town::RemovePlanned(PlannedMultiMapFixed* planned) {
    auto** link = reinterpret_cast<PlannedMultiMapFixed**>(&planned_list.head);
    while (*link && *link != planned) link = &(*link)->next;
    if (*link) { *link = planned->next; --planned_list.count; }
}

void Town::AllVillagersCheckNeedNewAbode() {
    // Original at 0x0073d150 — complex
}

TownSpellIcon* Town::GetNextSpellIcon(TownSpellIcon* /*icon*/) {
    // Original at 0x0073d360 — complex
    return nullptr;
}

// v1.0 sub_6D0200: the town holds the magic, and its player gains it
// (sub_5F94A0: count +0x188, enabled +0x230). A seed's base magic gets its
// icon at the town's worship site (through the town centre, sub_6D6180).
// ponytail: power-ups (sub_6D6140), the town centre's own icons and the
// player's sites' refresh (sub_7049E0) are not kept.
bool Town::AddMagicTypesHeld(MAGIC_TYPE type) {
    const int m = static_cast<int>(type);
    if (m < 0 || m >= 42 || magic_held[m]) return false;
    magic_held[m] = 1;
    if (GPlayer* p = GetPlayer()) {
        ++p->magic_remainder[m];
        p->magic_enabled[m] = true;
    }
    const int seed = SeedOfMagic(m);
    if (town_centre && worship_site && seed >= 0 && SeedBase(seed) == m)
        worship_site->AddSpellIconIfNecessary(static_cast<SPELL_SEED_TYPE>(seed));
    return true;
}

bool Town::IsMagicTypeHeld(MAGIC_TYPE type) {  // sub_6D0490
    const int m = static_cast<int>(type);
    return m >= 0 && m < 42 && magic_held[m] > 0;
}

bool Town::GetFlock(LIVING_TYPE /*type*/, int /*param*/) {
    // Original at 0x0073de30 — complex
    return false;
}

TotemStatue* Town::GetTotemStatue() {
    // Original at 0x0073e1d0 — complex
    return nullptr;
}

void Town::RemoveVillager(Villager* villager) {
    // Original at 0x0073e210 — translated from x86 assembly
    if (!villager) return;

    // Step 2: Get abode and remove from stats
    Abode* abode = villager->GetHome();
    stats.Remove(villager);

    // Step 3: Remove from abode or homeless list
    if (abode) {
        abode->RemoveAliveVillagerFromAbode(villager);
        villager->SetHome(nullptr);
    } else {
        // Remove from homeless linked list
        if (IsVillagerInHomelessList(villager)) {
            // Walk the singly-linked list (next_villager at offset 0xE4)
            Villager* head = static_cast<Villager*>(homeless_list.first);
            if (head == villager) {
                // Removing head of list
                homeless_list.first = villager->next_villager;
            } else if (head) {
                // Walk list to find predecessor
                Villager* prev = head;
                while (prev) {
                    if (prev->next_villager == villager) {
                        prev->next_villager = villager->next_villager;
                        break;
                    }
                    prev = prev->next_villager;
                }
            }
            // Decrement homeless count — asm does dec [edi+0x76c] which is homeless_list.last used as count
            reinterpret_cast<uint32_t&>(homeless_list.last)--;
            villager->next_villager = nullptr;
        }
    }

    // Step 4: Remove from worship site tracking
    RemoveVillagerOnWayToWorshipSite(villager);

    // Step 5: Clear town reference on villager
    villager->SetTown(nullptr);
}

void Town::RemoveVillagerOnWayToWorshipSite(Villager* /*villager*/) {
    // Original at 0x0073e360 — complex
}

float Town::GetDesire(TOWN_DESIRE_INFO desire_type) {
    // Original at 0x0073e400 — reads processed desire from TownDesire
    uint32_t idx = static_cast<uint32_t>(desire_type);
    if (idx >= 17) return 0.0f;
    return desire.desire[idx] + desire.boost[idx] + desire.cheat[idx];  // v1.0 sub_6D1080
}

float Town::GetRawDesire(TOWN_DESIRE_INFO desire_type) {
    // Original at 0x0073e420 — reads raw unprocessed desire
    uint32_t idx = static_cast<uint32_t>(desire_type);
    if (idx >= 17) return 0.0f;
    return desire.raw[idx] + desire.boost[idx] + desire.cheat[idx];  // v1.0 sub_6D10A0
}

void* Town::GetTemporaryResourceStorePotOrPos(const MapCoords& /*p1*/, MapCoords& /*p2*/,
                                               RESOURCE_TYPE /*type*/) {
    // Original at 0x0073e900 — complex
    return nullptr;
}

void Town::AssignForestsToTown() {
    // Original at 0x0073eb00 — complex
}

Workshop* Town::GetBestWorkshop(MapCoords& /*pos*/, int /*p2*/, int /*p3*/) {
    // Original at 0x00740250 — complex
    return nullptr;
}

MapCoords* Town::GetCongregationPos(MapCoords* out) {
    // Original at 0x007408b0: returns congregation_pos via out param
    *out = congregation_pos;
    return out;
}

void Town::MakeScenicForest() {
    // Original at 0x00741b40 — complex
}

void Town::UpdateAttitudeToCreature() {
    // Original at 0x007437f0 — complex
}

uint32_t Town::Process() {
    // v1.0 sub_6D8EB0, called once a turn per town from GPlayer::Process
    // (sub_5F7440). Steps in the original's order; the ones marked "not yet"
    // are named so the order stays visible. docs/town-economy.md.
    extern uint32_t g_game_turn;
    auto info_u = [this](int off) { uint32_t v = 0; if (info) std::memcpy(&v, reinterpret_cast<const char*>(info) + off, 4); return v; };

    field_0x5e4 = 0;                         // +0x5E4
    // not yet: sub_4344F0 over the list at +0x788 (drops finished entries)
    influence = TownInfoInfluence();         // sub_6D2810
    ProcessAbodes(g_game_turn, info_u(76));  // sub_6D9120
    // not yet: x game influence multiplier (+2408752) when the town has a player
    desire.Process();                        // sub_6D7950
    // not yet: sub_6D92A0 (list +0x98C), every 10 turns sub_6DA400,
    //          sub_6D9180 (drop dead villagers from +0x768), the object at +0xE9C,
    //          sub_6D9270 (process list +0x770), sub_6D0630 (desire flags),
    //          sub_6D0BA0 (interaction multipliers), sub_6D9860, sub_6D92C0,
    //          sub_6D59C0, the two objects at +0x5F8, the list at +0x994,
    //          sub_4310A0 (belief), the countdown at +0xF18, the influence map
    // Every TownInfo +360 turns, staggered by id * 20: sub_6D3E70.
    // not yet translated.
    return 1;
}

// v1.0 sub_6D2810: TownInfo +120 (mode 0; +188 + 4n in the game's other modes).
float Town::TownInfoInfluence() const {
    float v = 0;
    if (info) std::memcpy(&v, reinterpret_cast<const char*>(info) + 120, 4);
    return v;
}

// v1.0 sub_6D9120: every `period` turns each abode runs its Process (vslot 383)
// and its influence (vslot 538) is added to the town's. Abodes belong to their
// town's tick, not the global object loop.
void Town::ProcessAbodes(uint32_t turn, uint32_t period) {
    if (!period || turn % period) return;
    for (Abode* a = reinterpret_cast<Abode*>(abode_list.head); a; a = a->next) {
        a->Process();
        influence += a->GetInfluence();
    }
}

void Town::ProcessTownEmergency() {
    // Original at 0x007477a0 — handles starvation, lack of shelter
    // Check if town is starving (no food, has population)
    if (stats.num_adults > 0 && stats.total_food <= 0.0f) {
        // Town is in food emergency
        // Starvation: reduce happiness, trigger emergency villager states
    }
}

bool Town::IsInStateOfEmergency() {
    // Original at 0x00747970 — complex
    return false;
}

void Town::SetInStateOfEmergency() {
    // Original at 0x007479a0 — complex
}

bool32_t Town::GetBestRepairBuildingSite() {
    // Original at 0x00747ea0 — complex
    return 0;
}

bool32_t Town::DisplayHowImpressed() {
    // Original at 0x007635d0 — complex
    return 0;
}

// ============================================================================
// Construction — v1.0 sub_6CD070 and the helpers it calls. Only the non-zero
// state is written here: the Town arrives value-initialised (all zero, vtables
// set), which is everything the original's field-clearing does. Not yet:
// the desire-flag objects (sub_6D05E0 -> sub_6D8950, a 152-byte object class),
// the player hookup (sub_6CDFF0: player town list, spell icons; needs GPlayers),
// and the map-region flag at +0x5E0 (sub_6FE660). docs/constructors.md.
// ============================================================================

void Town::Construct(const MapCoords& pos, const void* town_info, GPlayer* player,
                     uint8_t player_num, TRIBE_TYPE tribe, const char* name, uint32_t id) {
    const char* ti = static_cast<const char*>(town_info);
    auto info_f = [ti](int off) { float v = 0; if (ti) std::memcpy(&v, ti + off, 4); return v; };

    // Container (sub_456870): info, position, owner.
    info = static_cast<GContainerInfo*>(const_cast<void*>(town_info));
    SetPos(pos);
    owner = player;
    // sub_6CDFF0 -> sub_5F9230: the tail of its player's town list (+616, next +0x754).
    if (player) {
        next = nullptr;
        Town** tail = &player->towns.first;
        while (*tail) tail = &(*tail)->next;
        *tail = this;
        ++player->towns.count;
    }

    // TownDesire (sub_6D7580 / sub_6D75E0): it knows its town.
    desire.town = this;

    // 8 player interactions (sub_6D0D20): +0x10 = 1.0, and their EffectValues
    // (sub_4FC9F0) start with effect 5 at 1.0.
    for (PlayerTownInteract& pti : player_interactions) {
        pti.field_0x10 = 1.0f;
        pti.effect_values.numbers.values[5] = 1.0f;
    }

    // sub_6CF870: the two multipliers at +0xEAC/+0xEB0.
    field_0xeb4 = 1.0f;
    field_0xeb8 = 1.0f;

    // GBelief (sub_430AF0): caps of 10 per player, 41 reaction multipliers of 1,
    // and each town desire's belief weight from DETAIL_TOWN_DESIRE_INFO (+0x3C
    // of each 144-byte element, sub_430B70).
    for (float& cap : belief.belief_in_player_max) cap = 10.0f;
    for (float& m : belief.boredom_multiplier) m = 1.0f;
    for (uint32_t d = 0; d < 17; ++d) {
        const char* e = static_cast<const char*>(infodat::Element(infodat::DETAIL_TOWN_DESIRE_INFO, d));
        if (e) std::memcpy(&belief.field_0x18c[d], e + 0x3C, 4);
    }

    // Identity: id (this[365]), name (this[364]), tribe (this[366]), player byte.
    field_0x5b4 = id;
    if (name) {
        field_0x5b0 = static_cast<char*>(std::malloc(std::strlen(name) + 1));
        std::strcpy(field_0x5b0, name);
    }
    tribe_type = tribe;
    player_number = player_num;

    // this[370] (sub_6D2810): TownInfo +120, or +188 + 4*n when the game's mode
    // index at +2104004 is set. ponytail: mode 0 assumed until GGame carries it.
    influence = info_f(120);
    // this[374] = TownInfo +184 (the belief sub_430AF0 reads back), this[375] = 1.0.
    belief_in_neutral_player = info_f(184);
    field_0x5dc = 1.0f;
}

void Town::SetStoragePit(StoragePit* pit) {
    // v1.0 sub_6D16B0: the town's store (+0x30). The original then empties the
    // two temporary stores at +0x5F8/+0x5FC into it; we never create those.
    storage_pit_list = pit;
}

namespace {
float TownInfoF(const Town* t, int off) {
    float x = 0;
    if (t->info) std::memcpy(&x, reinterpret_cast<const char*>(t->info) + off, 4);
    return x;
}
float Dist(const MapCoords& a, const MapCoords& b) {
    const float dx = MetresOf(b.x - a.x), dz = MetresOf(b.z - a.z);
    return std::sqrt(dx * dx + dz * dz);
}
// sub_50EF80 / vslot 527 (sub_5E9230): a forest's nearest point to pos -- on
// its big forest's edge (or pos itself inside it), else the forest's position.
MapCoords ForestPoint(const Forest* f, const MapCoords& pos) {
    BigForest* bf = f->big_forest;
    if (!bf) return f->coords;
    const float r = bf->GetRadius(), d = Dist(bf->coords, pos);
    if (d <= r) return pos;
    const float k = r / d;
    return MapCoords(bf->coords.x + static_cast<int32_t>((pos.x - bf->coords.x) * k),
                     bf->coords.z + static_cast<int32_t>((pos.z - bf->coords.z) * k), bf->coords.altitude);
}
// sub_50F450: the wood a forest holds (its big forest's plus its trees').
float ForestWood(const Forest* f) { return f->big_forest ? f->big_forest->GetWoodValue() : 0.0f; }
}  // namespace

void Town::CollectForests(const std::vector<Forest*>& all) {
    // ponytail: no store and no town spot search (sub_6D1550): the town's own
    // position stands in when there is no storage pit.
    const MapCoords centre = storage_pit_list ? reinterpret_cast<Object*>(storage_pit_list)->coords : coords;
    while (forests.head) forests.Remove(forests.head->obj);
    for (Forest* f : all)
        if (Dist(ForestPoint(f, centre), centre) < TownInfoF(this, 356) && ForestWood(f) != 0.0f) forests.Add(f);
}

Forest* Town::NearestForest(const MapCoords& pos) {
    // Two rankings within TownInfo +356: forests flagged at +0x3C count only
    // when no other is in range.
    // ponytail: the original does not skip emptied forests -- it deletes
    // them; we keep them with no wood, so they are skipped here instead.
    float best = TownInfoF(this, 356), best_flagged = best;
    Forest *found = nullptr, *flagged = nullptr;
    for (LHNode* n = forests.head; n; n = n->next) {
        auto* f = static_cast<Forest*>(n->obj);
        if (ForestWood(f) == 0.0f) continue;
        const float d = Dist(ForestPoint(f, pos), pos);
        if (f->field_0x3c == 1) { if (d < best_flagged) { best_flagged = d; flagged = f; } }
        else if (d < best) { best = d; found = f; }
    }
    return found ? found : flagged;
}

void Town::AddPlanned(PlannedMultiMapFixed* p) {  // sub_6CFFB0
    // ponytail: TownStats' planned count (sub_6DB100) is not kept.
    p->next = nullptr;
    auto** tail = reinterpret_cast<PlannedMultiMapFixed**>(&planned_list.head);
    while (*tail) tail = &(*tail)->next;
    *tail = p;
    ++planned_list.count;
}

namespace {
uint32_t InfoU32(const void* info, int off) { uint32_t x = 0; if (info) std::memcpy(&x, static_cast<const char*>(info) + off, 4); return x; }
float InfoF32(const void* info, int off) { float x = 0; if (info) std::memcpy(&x, static_cast<const char*>(info) + off, 4); return x; }
}  // namespace

float Town::PlanScore(const void* info, uint32_t a3) {
    // sub_6CD9F0, read from the disassembly. The type is abode info +288
    // (GAbodeInfo vslot 16); the base want is +276.
    // ponytail: only the abode type (2) and types without a case of their
    // own are scored; the special cases (20, 36, 68, 132, 256 wonder, 516,
    // 1028 town centre, 4100, 8196) score 0 until translated, and a3 (the
    // turn-based decay) is not used.
    const int32_t type = static_cast<int32_t>(InfoU32(info, 288));
    float base = InfoF32(info, 276);
    // Sites already building the same type share the want (+0x788).
    uint32_t building_same = 0;
    for (LHNode* n = building_site_list.head; n; n = n->next) {
        auto* site = static_cast<BuildingSite*>(n->obj);
        if (site->root_building && InfoU32(site->root_building->info, 288) == static_cast<uint32_t>(type)) ++building_same;
    }
    if (base == 0.0f) return 0.0f;
    float r = base;
    switch (type) {
    case 20: case 36: case 68: case 132: case 256: case 516: case 1028: case 4100: case 8196: return 0.0f;
    default: break;
    }
    if (type == 2) {
        // Spare room for adults (stats +0x4C) less the homeless (+0x764),
        // against a tenth of the town plus one.
        const int32_t spare = static_cast<int32_t>(stats.field_0x4c) - static_cast<int32_t>(reinterpret_cast<const uint32_t&>(homeless_list.last));
        const int32_t need = static_cast<int32_t>(static_cast<uint32_t>(stats.num_adults + stats.num_children) / 10u + 1u);
        if (spare > need && !a3) {
            r = 0.0f;
        } else if (spare < 0) {
            float x = base + static_cast<float>(spare) / static_cast<float>(need) * -1.0f;
            if (x > 0.8f) x = 0.8f;
            const float over = -10.0f > static_cast<float>(spare) ? -10.0f : static_cast<float>(spare);
            const uint32_t n = static_cast<uint32_t>(static_cast<int>(over * -1.0f));
            const uint32_t room = InfoU32(info, 0x174);  // maxAdults
            const float f = n > room ? static_cast<float>(room) / static_cast<float>(n) * 0.2f
                                     : static_cast<float>(n) / static_cast<float>(room) * 0.2f + 0.2f;
            r = x * (f + 0.6f);
        }
        // The town's count of this abode (stats byte table +0x108, by +292).
        const uint32_t number = InfoU32(info, 292);
        const uint32_t have = number < 16 ? reinterpret_cast<const uint8_t*>(&stats)[0x108 + number] : 0;
        float div = static_cast<float>(have + 1);
        if (div < 10.0f) div = 10.0f;
        r = r - r / div * static_cast<float>(have);
    }
    if (building_same) r /= static_cast<float>(building_same);
    return r;
}

void Town::AddBuildingSite(BuildingSite* site) {  // sub_6CEAF0
    // ponytail: TownStats' site counts (sub_6DB140) are not kept.
    if (!site || building_site_list.Has(site)) return;
    building_site_list.Add(site);
    field_0x5e8 = 1;
    field_0x5ec = 0;
}

BuildingSite* Town::PlanBuilding(uint32_t mask) {
    // sub_6CD990: the planned building of a masked type the town wants most.
    PlannedMultiMapFixed* best = nullptr;
    float best_score = 0.0f;
    for (PlannedMultiMapFixed* p = static_cast<PlannedMultiMapFixed*>(planned_list.head); p; p = p->next) {
        // vslot 324 -> info +288. ponytail: a planned citadel heart answers
        // 0x804 there (sub_44F8F0) and is scored by its own record; it is left
        // to BUILD_BUILDING.
        if (dynamic_cast<PlannedTownCitadelHeart*>(p) || !(InfoU32(p->info, 288) & mask)) continue;
        const float s = PlanScore(p->info, 0);
        if (s > best_score) { best_score = s; best = p; }
    }
    if (!best) return nullptr;
    // sub_6CEA40: the building (vslot 320 -> sub_403E80 -> sub_401BA0: an
    // abode at its planned place, nothing built yet), the plan gone, a site.
    // ponytail: the land check (sub_5BFD30), PostCreatePlanned (vslot 322)
    // and the +0x30 flag are not translated; new buildings are not drawn by
    // the viewer until it learns of them.
    const char* e0 = static_cast<const char*>(infodat::Element(infodat::DETAIL_ABODE_INFO, 0));
    EntityCreateParams params;
    params.world_x = MetresOf(best->coords.x);
    params.world_z = MetresOf(best->coords.z);
    params.angle = best->field_0x28;
    params.scale = best->scale;
    params.mesh_id = -1;
    params.type_enum = static_cast<uint32_t>((reinterpret_cast<const char*>(best->info) - e0) / 456);
    params.type_name = "";
    Object* o = EntityFactory::CreateEntity(ENTITY_CAT_ABODE, params);
    Abode* abode = o ? o->CastAbode() : nullptr;
    if (!abode) return nullptr;
    abode->percent_built = 0.0f;
    abode->JoinTown(this);
    RemovePlanned(best);
    delete best;
    abode->CreateBuildingSite();  // vslot 309
    AddBuildingSite(abode->building_site);
    return abode->building_site;
}

BuildingSite* Town::StartPlanned(PlannedMultiMapFixed* planned) {  // sub_6CEA80
    MultiMapFixed* b = planned ? planned->CreatePlannedNoFixedCheck(0.0f) : nullptr;
    if (!b || !b->CreateBuildingSite() || !b->building_site) return nullptr;
    AddBuildingSite(b->building_site);
    return b->building_site;
}

BuildingSite* Town::SiteFor(MultiMapFixed* building) {
    for (LHNode* n = building_site_list.head; n; n = n->next)
        if (static_cast<BuildingSite*>(n->obj)->root_building == building) return static_cast<BuildingSite*>(n->obj);
    return nullptr;
}

BuildingSite* Town::StartBuilding(MultiMapFixed* building) {
    if (!building->CreateBuildingSite() || !building->building_site) return nullptr;
    AddBuildingSite(building->building_site);
    return building->building_site;
}

// ponytail: the game-wide check (game +2104004 == 1) is not kept.
bool Town::CanWorship() const { return !field_0x5f0 && stats.num_adults + stats.num_children; }

// ponytail: the walk to it (sub_6D5F30, when +0x99C is set) is not translated.
void Town::SetWorshipSite(WorshipSite* site) {
    worship_site = site;
    if (!site->IsBuilt() && !SiteFor(site)) StartBuilding(site);
}

BuildingSite* BuildPlannedAt(const MapCoords& at, float priority) {
    BuildingSite* last = nullptr;
    for (uint32_t i = 0; i < 8; ++i)
        for (Town* t = PlayerAt(i)->towns.first; t; t = t->next) {
            PlannedMultiMapFixed* best = nullptr;
            float best_d = 10.0f;
            for (auto* p = static_cast<PlannedMultiMapFixed*>(t->planned_list.head); p; p = p->next) {
                const float d = std::hypot(MetresOf(p->coords.x) - MetresOf(at.x), MetresOf(p->coords.z) - MetresOf(at.z));
                if (d <= best_d) best_d = d, best = p;
            }
            if (BuildingSite* s = best ? t->StartPlanned(best) : nullptr) {
                s->field_0x63c = priority;
                last = s;
            }
        }
    return last;
}
