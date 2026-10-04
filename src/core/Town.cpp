// Town class implementation
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)
// Cross-referenced with bw1-decomp (v1.20)
//
// Town is the largest class in the game (0xF28 bytes).
// Manages population, desires, buildings, fields, worship,
// resources, and player interaction.

#include <black/Town.h>
#include <black/Abode.h>
#include <black/StoragePit.h>
#include <black/Player.h>
#include <black/Villager.h>
#include <black/Game.h>
#include <black/InfoDat.h>
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

WorshipSite* Town::GetWorshipSite() {
    // Original at 0x0073c940 — complex lookup through citadel parts
    // Look up worship site through citadel parts — needs citadel worship site tracking
    return nullptr;
}

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
    // Original at 0x0073a090 — translated from x86 assembly
    if (!villager) return false;

    // If field_0x5f4 is set, town is locked — reject
    if (field_0x5f4 != 0) return false;

    // Add to town stats
    stats.num_adults++;

    // Set town reference on villager
    villager->SetTown(this);

    // Check if villager's current abode belongs to a different town
    Abode* abode = villager->GetHome();
    if (abode) {
        if (abode->GetTown() != this) {
            // Remove from foreign abode
            abode->RemoveAliveVillagerFromAbode(villager);
            villager->SetHome(nullptr);
            abode = nullptr;
        }
    }

    if (!abode) {
        // Try to find a home in this town
        Abode* found = FindAbodeWithSpaceInTown(villager, 0.0f);
        if (found) {
            found->AddVillagerToAbode(villager);
            return true;
        }
    }

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

Abode* Town::FindAbodeWithSpaceInTown(Villager* /*villager*/, float /*min_score*/) {
    // Original at 0x0073b370 — complex
    return nullptr;
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

void Town::AddBuildingSite(BuildingSite* /*site*/) {
    // Original at 0x0073b910 — complex
}

uint32_t Town::RemoveBuildingSite(MultiMapFixed* /*structure*/) {
    // Original at 0x0073ba20 — complex
    return 0;
}

void Town::SetBeliefInPlayer(GPlayer* player, float value) {
    // Original at 0x0073ba70 — set the town's belief in a given player
    if (!player) return;
    uint8_t player_num = player->GetPlayerNumber();
    belief.SetBelief(player_num, value);
}

void Town::SetWorshipPercentage(float percentage) {
    // Original at 0x0073c060 — sets the worship percentage for this town
    worship_percentage = percentage;
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

int Town::GetWorshipersNeeded(int /*param1*/, int /*param2*/, int* /*result*/) {
    // Original at 0x0073c860 — complex
    return 0;
}

bool32_t Town::IsBuildingSiteValid(BuildingSite* /*site*/) {
    // Original at 0x0073cf00 — complex
    return 0;
}

bool32_t Town::GetBestBuildingSite(const MapCoords& /*pos*/, int /*param*/) {
    // Original at 0x0073cf60 — complex
    return 0;
}

void Town::AddPlanned(PlannedMultiMapFixed* /*planned*/) {
    // Original at 0x0073d080 — complex
}

void Town::RemovePlanned(PlannedMultiMapFixed* /*planned*/) {
    // Original at 0x0073d0d0 — complex
}

void Town::AllVillagersCheckNeedNewAbode() {
    // Original at 0x0073d150 — complex
}

TownSpellIcon* Town::GetNextSpellIcon(TownSpellIcon* /*icon*/) {
    // Original at 0x0073d360 — complex
    return nullptr;
}

bool Town::AddMagicTypesHeld(MAGIC_TYPE /*type*/) {
    // Original at 0x0073d380 — complex
    return false;
}

bool Town::IsMagicTypeHeld(MAGIC_TYPE /*type*/) {
    // Original at 0x0073d630 — complex
    return false;
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
    return desire.field_0xd4[idx];
}

float Town::GetRawDesire(TOWN_DESIRE_INFO desire_type) {
    // Original at 0x0073e420 — reads raw unprocessed desire
    uint32_t idx = static_cast<uint32_t>(desire_type);
    if (idx >= 17) return 0.0f;
    return desire.field_0x90[idx];
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
    // Original at 0x00747380 — town simulation tick
    // Translated from vendor decompilation — the central town update loop.

    // Phase 1: Update town desires (food, wood, shelter needs)
    // Desire evaluation — updates desire values based on population needs

    // Phase 2: Population management
    // Check for new births if population can grow
    Birthday();

    // Phase 3: Housing check — assign homeless villagers to abodes
    AllVillagersCheckNeedNewAbode();

    // Phase 4: Construction management
    // Request new buildings if there are unmet desires
    if (planned_list.count > 0) {
        RequestBestPlanned();
    }

    // Phase 5: Emergency handling (starvation, etc.)
    ProcessTownEmergency();

    // Phase 6: Worship and belief updates
    UpdateAttitudeToCreature();

    // Phase 7: Resource accounting — tally total food/wood in town
    float food_total = 0.0f;
    float wood_total = 0.0f;

    // Sum resources from storage pits
    StoragePit* pit = storage_pit_list;
    if (pit) {
        food_total += static_cast<float>(pit->GetResource(static_cast<RESOURCE_TYPE>(0))); // FOOD
        wood_total += static_cast<float>(pit->GetResource(static_cast<RESOURCE_TYPE>(1))); // WOOD
    }

    // Update town stats with resource totals
    stats.total_food = food_total;
    // stats.total_wood = wood_total; // field offset needs verification

    return 1;
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
