// Villager class implementation
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)
// Cross-referenced with bw1-decomp (v1.20)
//
// Villagers are the main population unit. They have needs (food, shelter),
// can become disciples, carry resources, build structures, and worship.

#include <black/Villager.h>
#include <black/Terrain.h>
#include <cstring>
#include <black/LHRandom.h>
#include <black/Abode.h>
#include <black/BuildingSite.h>
#include <black/StoragePit.h>
#include <black/Town.h>
#include <black/MultiMapFixed.h>

// ============================================================================
// Overrides from GameThingWithPos / Object
// ============================================================================

uint32_t Villager::GetCreatureBeliefType() {
    // Original at 0x0055ca70
    return 6;
}

bool32_t Villager::IsABeliever() {
    // Villagers are always believers
    // Original at 0x0055c990
    return 1;
}

bool32_t Villager::CanReceiveGifts(Creature*) {
    // Villagers can always receive gifts
    // Original at 0x0055ca90
    return 1;
}

bool32_t Villager::IsVillager(Creature*) {
    // Original at 0x0055cab0
    return 1;
}

bool Villager::CanBePickedUp() {
    // Original at 0x0055ca50
    // If bit 2 of field_0xe0 is set, cannot be picked up (e.g. in special state)
    if (field_0xe0 & 0x04) {
        return false;
    }
    // Otherwise, can be picked up if bit 13 of field_0x24 is NOT set
    // (bit 13 = "cannot be picked up" flag in GameThingWithPos)
    return !(field_0x24 & 0x2000);
}

uint32_t Villager::GetTastiness() {
    // Villagers are tastiness level 2 (creatures find them moderately tasty)
    // Original at 0x0055ca30
    return 2;
}

int Villager::GetMesh() const {
    // Original at 0x0052e190: reads mesh ID from info struct at offset 0x214
    return *reinterpret_cast<const int*>(
        reinterpret_cast<const char*>(info) + 0x214);
}

int Villager::GetDetailMesh(int detail) {
    // Original at 0x0052e1a0: reads detail mesh from info at 0x210 + detail * 4
    return *reinterpret_cast<const int*>(
        reinterpret_cast<const char*>(info) + 0x210 + detail * 4);
}

// ============================================================================
// New virtual methods (vtable 0xB40-0xB44)
// ============================================================================

const char* Villager::GetVillagerName() {
    // Original at 0x0055ca40 — returns null (name resolved elsewhere)
    return nullptr;
}

float Villager::GetHowMuchCreatureWantsToLookAtMe() {
    // Original at 0x004d1b40
    return 0.5f;
}

void Villager::DrawVillagerInfo() {}

// ProcessState (v1.0's villager tick and states): VillagerStates.cpp.

// ============================================================================
// Overrides of GameThingWithPos type predicates
// ============================================================================

bool32_t Villager::IsMaleVillager() {
    return Sex() == 0;  // v1.0 vslot 275 (sub_52E250): info +504 == 0
}

bool32_t Villager::IsFemaleVillager() {
    return Sex() != 0;
}

// ============================================================================
// Overrides of Living virtuals
// ============================================================================

bool Villager::AmILikelyToMove() {
    uint8_t state = action.top_state;
    return state == VILLAGER_STATE_MOVE_TO_POS ||
           state == VILLAGER_STATE_MOVE_TO_OBJECT ||
           state == VILLAGER_STATE_MOVE_ON_STRUCTURE ||
           state == VILLAGER_STATE_FLEEING_FROM_OBJECT_REACTION ||
           state == VILLAGER_STATE_FOLLOWING_OBJECT_REACTION ||
           state == VILLAGER_STATE_GOTO_FOOD_REACTION ||
           state == VILLAGER_STATE_GOTO_WOOD_REACTION;
}

uint32_t Villager::GetScriptObjectType() {
    // Original at 0x005c2d80 — villagers are script type 1
    return 1;
}

HOLD_TYPE Villager::GetHoldType() {
    // Original at 0x005c2e40 — villagers use hold type 7
    return static_cast<HOLD_TYPE>(7);
}

float Villager::GetHoldLoweringMultiplier() {
    // Original at 0x005c2650
    return 0.65f;
}

uint32_t Villager::GetPhysicsConstantsType() {
    // Original at 0x005c2660 — villagers use physics type 7
    return 7;
}

bool32_t Villager::CanBeEatenByCreature(Creature* /*creature*/) {
    // Original at 0x004e48a0 — villagers can be eaten if not dead
    return !IsDead() ? 1 : 0;
}

bool32_t Villager::CanBeBefriendedByCreature(Creature* /*creature*/) {
    // Original at 0x0055c9a0 — villagers can be befriended
    return 1;
}

bool32_t Villager::CanBeStrokedByCreature(Creature* /*creature*/) {
    // Original at 0x0055c9b0 — villagers can be stroked
    return 1;
}

bool32_t Villager::CanBeKissedByCreature(Creature* /*creature*/) {
    // Original at 0x0055c9c0 — villagers can be kissed
    return 1;
}

bool32_t Villager::CanBeGivenToTown(Creature* /*creature*/) {
    // Original at 0x0055c9d0 — villagers can be given to a town
    return 1;
}

bool32_t Villager::CanBePutInFoodPile(Creature* /*creature*/) {
    // Original at 0x0055c9e0 — villagers cannot be put in food pile
    return 0;
}

bool32_t Villager::CanBePutInWoodPile(Creature* /*creature*/) {
    // Original at 0x0055c9f0 — villagers cannot be put in wood pile
    return 0;
}

bool32_t Villager::CanBeBroughtBackToCitadel(Creature* /*creature*/) {
    // Original at 0x0055ca00 — villagers can be brought to citadel
    return 1;
}

bool32_t Villager::CanBeThrownByCreature(Creature* /*creature*/) {
    // Original at 0x0055ca10 — villagers can be thrown
    return 1;
}

bool32_t Villager::CanBeGivenToVillager(Creature* /*creature*/) {
    // Original at 0x0055ca20 — villagers can receive other villagers
    return 0;
}

// ============================================================================
// Non-virtual methods
// ============================================================================

Town* Villager::GetTown() {
    return town;  // v1.0 vslot 18 (sub_706D30): this[73]
}

Abode* Villager::GetHome() {
    return home;
}

void Villager::SetHome(Abode* abode) {
    // v1.0 sub_6E0D10: the home, and the town becomes the home's town.
    home = abode;
    town = nullptr;
    if (abode) town = abode->GetTown();
}

void Villager::SetTown(Town* t) {
    town = t;
}

bool Villager::IsPregnant() const {
    return is_pregnant != 0;
}

bool Villager::IsHomeless() const {
    return home == nullptr;
}

bool Villager::IsCarryingResource() const {
    return resource_held[0] != 0 || resource_held[1] != 0 || resource_held[2] != 0;
}

int16_t Villager::GetResourceHeld(RESOURCE_TYPE type) const {
    if (static_cast<uint32_t>(type) < 3) return resource_held[static_cast<uint32_t>(type)];
    return 0;
}

void Villager::AddResourceHeld(RESOURCE_TYPE type, int16_t amount) {
    if (static_cast<uint32_t>(type) < 3) {
        resource_held[static_cast<uint32_t>(type)] += amount;
    }
}

void Villager::ClearResourceHeld() {
    resource_held[0] = 0;
    resource_held[1] = 0;
    resource_held[2] = 0;
}

float Villager::GetFood() const {
    return food;
}

void Villager::SetFood(float value) {
    food = value;
}

bool Villager::IsFoodSpeedUp() const {
    return food_speed_up;
}

// ============================================================================
// v1.0 construction and housing. docs/constructors.md.
// ============================================================================

namespace {
// The game's generator (sub_67BC90 ints, sub_67BCB0 floats), black/LHRandom.h.
uint32_t RandInt(uint32_t n) { return lh::Random(n); }
float RandFloat(float max) { return lh::RandomFloat(max); }
float InfoF(const GObjectInfo* info, int off) { float v = 0; if (info) std::memcpy(&v, reinterpret_cast<const char*>(info) + off, 4); return v; }
uint32_t InfoU(const GObjectInfo* info, int off) { uint32_t v = 0; if (info) std::memcpy(&v, reinterpret_cast<const char*>(info) + off, 4); return v; }
}  // namespace

// The length of a game year in turns (dword_C22D44). It is .bss, set at runtime
// by code we have not found (no immediate writes it); only age<->birth-turn
// conversions use it. ponytail: 1 until recovered -- ages are then counted in
// turns, which is wrong for aging and right for everything else here.
int32_t g_turns_per_year = 1;
extern uint32_t g_game_turn;  // LevelLoader.cpp

uint32_t Villager::Sex() const { return InfoU(info, 504); }

bool Villager::IsChild() { return (field_0xe0 >> 3) & 1; }

void Villager::SetAge(uint32_t age) {
    // sub_6E23C0 without its mesh/texture half. Below the adult age (info +312)
    // the child bit is set; otherwise the age is at least 18 and the bit clear.
    const uint32_t adult = InfoU(info, 312);
    if (age < adult) {
        field_0xe0 |= 8;
    } else {
        if (age < 18) age = 18;
        field_0xe0 &= ~8u;
    }
    // sub_6DFEA0 then sub_6E2590: the scale. Adults land in [0.95, 1.05);
    // children grow towards the next year's size from the table at info +740.
    if (age >= adult) {
        scale = 0.9f;
        const float target = 0.05f - RandFloat(0.1f) + 1.0f;
        if (scale < target) scale = target;
    } else {
        scale = InfoF(info, 740 + 4 * static_cast<int>(age));
        const float step = (InfoF(info, 748 + 4 * static_cast<int>(age)) - scale) * 0.75f;
        scale += RandFloat(step > 0 ? step : 0.0f);
    }
    birth_turn = static_cast<int32_t>(g_game_turn) - static_cast<int32_t>(age) * g_turns_per_year;  // sub_5ABD10
}

void Villager::Construct(uint32_t age, bool flag) {
    // Living (sub_5AAAE0): speed from info +260, +0x9C from info +300, life
    // from info +296, a starting birth turn from info +308.
    SetSpeed(static_cast<int>(InfoU(info, 260)));
    field_0x9c = static_cast<int>(InfoF(info, 300));
    life = InfoF(info, 296);
    {
        const uint32_t base = InfoU(info, 308);
        const uint32_t years = base - (base >> 2) + RandInt(base >> 1);
        birth_turn = static_cast<int32_t>(g_game_turn) - static_cast<int32_t>(years) * g_turns_per_year;
    }
    // Villager (sub_6DFC80).
    SetAge(age);
    if (InfoU(info, 504) == 1) resource_held[2] = 0;
    food = InfoF(info, 704) + RandFloat(0.6f);
    if (food > 1.0f) food = 1.0f;
    {
        const uint32_t r = RandInt(InfoU(info, 732));
        last_check_turn = static_cast<int>(g_game_turn - (r < g_game_turn ? r : g_game_turn));
    }
    turns_until_next_state_change = static_cast<int16_t>(RandInt(500) + 1);
    // sub_5BFB00: on a deep-water cell (flag 0x10, or off the map) it starts
    // drowning; otherwise it is Created, the state a new villager decides from.
    const uint32_t cx = static_cast<uint32_t>(coords.x) >> 16, cz = static_cast<uint32_t>(coords.z) >> 16;
    const int32_t flags = g_cell_flags_func ? g_cell_flags_func(cx, cz) : 0;
    const bool deep = flags < 0 || (flags & 0x10);
    action.top_state = deep ? VILLAGER_STATE_DROWNING : VILLAGER_STATE_CREATED;  // 16 : 85
    action.final_state = action.top_state;
    status = static_cast<uint16_t>((status & ~0x40u) | ((flag ? 1u : 0u) << 6));  // sub_6E5990
}

void Villager::BecomeHomeless() {
    // sub_6EFD50: leave the home, keep the town, join its homeless list once.
    Town* t = GetTown();
    if (home) {
        home->RemoveAliveVillagerFromAbode(this);
        SetHome(nullptr);
        SetTown(t);
    }
    if (!t || t->IsVillagerInHomelessList(this)) return;
    next_villager = static_cast<Villager*>(t->homeless_list.first);
    t->homeless_list.first = this;
    reinterpret_cast<uint32_t&>(t->homeless_list.last)++;  // v1.0 keeps a count here
}
