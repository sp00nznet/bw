// Abode class implementation
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)
// Cross-referenced with bw1-decomp (v1.20)
//
// Residential building class — houses villagers, manages food/wood
// resources, handles building/repair lifecycle.

#include <black/Abode.h>
#include <black/Town.h>

// ============================================================================
// Overrides of Base virtuals
// ============================================================================

void Abode::Delete(int param) {
    // Original at 0x00402c10: removes from town, cleans up
    StopBeingFunctional(nullptr);
    DeleteDependancys();
    Base::Delete(param);
}

void Abode::ToBeDeleted(int param) {
    // Original at 0x00402c60: mark for deletion, clean up villagers
    RemoveAllVillagersFromAbode();
    StopBeingFunctional(nullptr);
    MultiMapFixed::ToBeDeleted(param);
}

// ============================================================================
// Overrides of GameThing virtuals
// ============================================================================

GPlayer* Abode::GetPlayer() {
    // Original at 0x00404600: if GetTown() != null, return GetTown()->GetPlayer()
    Town* t = GetTown();
    if (t) {
        return reinterpret_cast<GameThing*>(t)->GetPlayer();
    }
    return nullptr;
}

Town* Abode::GetTown() {
    // Original at 0x00401730
    return town;
}

uint32_t Abode::JustAddResource(RESOURCE_TYPE type, uint32_t amount, bool /*param3*/) {
    // Original at 0x00404d40
    if (type < 2) {
        resources[type] += amount;
    }
    return amount;
}

uint32_t Abode::JustRemoveResource(RESOURCE_TYPE type, uint32_t amount, bool* /*param3*/) {
    // Original at 0x00404d60
    if (type >= 2) return 0;
    uint32_t available = resources[type];
    uint32_t removed = (amount <= available) ? amount : available;
    resources[type] -= removed;
    return removed;
}

uint32_t Abode::GetResource(RESOURCE_TYPE type) {
    // Original at 0x00404d30: mov eax,[ecx+0x28]; mov eax,[eax+type*4+0xBC]
    // Reads directly from the resources array
    return resources[type];
}

uint32_t Abode::AddResource(RESOURCE_TYPE type, uint32_t amount, GInterfaceStatus* /*status*/, bool param4, const MapCoords& /*coords*/, int /*param6*/) {
    // Original at 0x00404d90 — delegates to DoResourceAdding/JustAddResource
    return JustAddResource(type, amount, param4);
}

uint32_t Abode::RemoveResource(RESOURCE_TYPE type, uint32_t amount, GInterfaceStatus* /*status*/, bool* param4) {
    // Original at 0x00404f10 — delegates to DoResourceRemoving/JustRemoveResource
    return JustRemoveResource(type, amount, param4);
}

Abode* Abode::CastAbode() {
    // Original at 0x00401640
    return this;
}

uint16_t Abode::GetNumberOfInstanceForGlobalList() {
    // Original at 0x00403f10 — returns adult + child count
    return static_cast<uint16_t>(adult_count + field_0xb7);
}

bool Abode::IsFunctional() {
    // Original at 0x00406200
    // Calls MultiMapFixed::IsFunctional(), then if true also checks IsBuilt()
    if (!MultiMapFixed::IsFunctional())
        return false;
    if (!IsBuilt())
        return false;
    return true;
}

char* Abode::GetDebugText() {
    // Original at 0x004017b0: returns pointer to "Abode" string
    static char text[] = "Abode";
    return text;
}

uint32_t Abode::Load(GameOSFile* /*file*/) {
    // Original at 0x00406d20 — complex serialization
    // TODO: implement when save system is available
    return 0;
}

uint32_t Abode::Save(GameOSFile* /*file*/) {
    // Original at 0x00406a10 — complex serialization
    // TODO: implement when save system is available
    return 0;
}

uint32_t Abode::GetSaveType() {
    // Original at 0x004017a0
    return 7;
}

// ============================================================================
// Overrides of GameThingWithPos virtuals
// ============================================================================

MapCoords* Abode::GetArrivePos(MapCoords* out) {
    // Original at 0x00401770: calls GetDoorPos through vtable (0x864)
    return GetDoorPos(out);
}

uint32_t Abode::GetCreatureBeliefType() {
    // Original at 0x00401740
    return 3;
}

uint32_t Abode::GetOrigin() {
    // Original at 0x00401760
    return 1;
}

bool Abode::IsInteractable() {
    // Original at 0x00407200 — abodes are interactable when functional
    return IsFunctional();
}

bool32_t Abode::IsCastShadowAtNight() {
    // Original at 0x00401720
    return 1;
}

bool32_t Abode::IsAbode() {
    // Original at 0x00401710
    return 1;
}

bool32_t Abode::CanBeStompedOnByCreature(Creature* /*creature*/) {
    // Original at 0x004e43f0 — complex
    // TODO: implement properly
    return 0;
}

bool32_t Abode::CanBeKickedByCreature(Creature* /*creature*/) {
    // Original at 0x004e3fa0 — complex
    // TODO: implement properly
    return 0;
}

uint32_t Abode::GetCreatureMimicType() {
    // Original at 0x00401750
    return 5;
}

float Abode::GetHowMuchCreatureWantsToLookAtMe() {
    // Original at 0x004d1b60: creatures are interested in abodes
    return 0.5f;
}

void Abode::CalculateWhereIWillBeAfterNSeconds(float /*seconds*/, LHPoint* outPos) {
    // Original at 0x0063b940 — buildings don't move, return current position
    if (outPos) {
        outPos->x = *reinterpret_cast<float*>(&coords.x);
        outPos->y = *reinterpret_cast<float*>(&coords.z);
        outPos->z = coords.altitude;
    }
}

bool32_t Abode::IsHouse() {
    // Original at 0x00401790
    return 1;
}

bool32_t Abode::IsWonder() {
    // Original at 0x004061c0
    // Reads GAbodeInfo::abodeType at offset 0x120 from info pointer
    // Returns true if abodeType == 0x100 (ABODE_TYPE_WONDER)
    ABODE_TYPE type = *reinterpret_cast<const ABODE_TYPE*>(
        reinterpret_cast<const char*>(info) + 0x120);
    return (type == static_cast<ABODE_TYPE>(0x100)) ? 1 : 0;
}

uint32_t Abode::GetScriptObjectType() {
    // Original at 0x00406810 — abodes are script type 5
    return 5;
}

// ============================================================================
// Overrides of Object virtuals
// ============================================================================

void Abode::DestroyedByBeam() {
    // Original at 0x00402cb0: reduce life to zero and start destruction
    ReduceLife(1.0f, nullptr);
}

void Abode::InsertMapObject() {
    // Original at 0x00403ee0: insert into map, then create surrounding objects
    MultiMapFixed::InsertMapObject();
    CreateAbodeSurroundingObjects();
}

bool Abode::GetPSysFireLocalRndFlamePos(LHPoint* /*point*/, int* /*param2*/) {
    // Original at 0x00402cf0 — complex
    // TODO: implement properly
    return false;
}

void Abode::ReduceLife(float value, GPlayer* player) {
    // Original at 0x00405d90 — reduces life and sets damaged flag
    Object::ReduceLife(value, player);
    if (GetLife() < 1.0f) {
        field_0x58 |= 4;  // Set damaged bit
    }
}

void Abode::IncreaseLife(float value) {
    // Original at 0x00405ed0 — increases life (repair)
    Object::IncreaseLife(value);
}

uint32_t Abode::DestroyedByEffect(GPlayer* player, float param2) {
    // Original at 0x00403f80: applies destruction effects to abode
    ReduceLife(param2, player);
    return 1;
}

uint32_t Abode::Process() {
    // Original at 0x00404440 — abode per-tick update
    // Delegates to building site if under construction
    if (!IsBuilt()) {
        return MultiMapFixed::Process();
    }

    // If functional, process normal abode tick
    // TODO: villager food consumption, pregnancy timer, etc.
    return 1;
}

int Abode::GetMesh() const {
    // Original at 0x00404aa0 — reads mesh from GAbodeInfo at offset 0x100
    if (!info) return 0;
    return *reinterpret_cast<const int*>(
        reinterpret_cast<const char*>(info) + 0x100);
}

void Abode::Draw() {
    // Original at 0x00515f70 — complex rendering
    // TODO: implement properly
}

uint32_t Abode::GetDiscipleStateIfInteractedWith(GInterfaceStatus* /*status*/, Villager* /*villager*/) {
    // Original at 0x00407170 — complex
    // TODO: implement properly
    return 0;
}

void Abode::CallVirtualFunctionsForCreation(const MapCoords& /*coords*/) {
    // Original at 0x00403200 — complex
    // TODO: implement properly
}

uint32_t Abode::InterfaceValidToTap(GInterfaceStatus* /*status*/) {
    // Original at 0x00406820 — complex
    // TODO: implement properly
    return 0;
}

uint32_t Abode::InterfaceTap(GInterfaceStatus* /*status*/) {
    // Original at 0x00406830 — complex
    // TODO: implement properly
    return 0;
}

uint32_t Abode::GetPhysicsConstantsType() {
    // Original at 0x00402dc0: reads from GAbodeInfo at offset 0x160
    if (!info) return 0;
    return *reinterpret_cast<const uint32_t*>(
        reinterpret_cast<const char*>(info) + 0x160);
}

void Abode::SetUpPhysOb(PhysOb* /*param1*/) {
    // Original at 0x00402dd0 — complex
    // TODO: implement properly
}

uint32_t Abode::ChecksVerticesVObjects() {
    // Original at 0x00406230: xor al, al; ret — returns false
    return 0;
}

void Abode::ReactToPhysicsImpact(PhysicsObject* /*param1*/, bool /*param2*/) {
    // Original at 0x00406240 — complex
    // TODO: implement properly
}

bool Abode::CanBecomeAPhysicsObject() {
    // Original at 0x00406800 — abodes can become physics objects when destroyed
    return IsBuilt();
}

bool Abode::GetInspectObjectPos(Villager* /*param1*/, MapCoords* /*pos*/) {
    // Original at 0x00402cd0 — complex
    // TODO: implement properly
    return false;
}

void Abode::DiscipleInHandNear(Villager* /*param1*/, GInterfaceStatus* /*status*/) {
    // Original at 0x00407420 — complex
    // TODO: implement properly
}

size_t Abode::SaveObject(LHOSFile* /*param1*/, const MapCoords* /*param2*/) {
    // Original at 0x00405bb0 — complex serialization
    // TODO: implement properly
    return 0;
}

bool Abode::ShouldFootpathsGoRound() {
    // Original at 0x00403ef0 — abodes should have footpaths go around them
    return true;
}

// ============================================================================
// Overrides of MultiMapFixed virtuals
// ============================================================================

float Abode::GetInfluence() {
    // Original at 0x004072a0 — influence is based on population fullness and build state
    float built = GetPercentBuilt();
    float full = GetPercentAbodeFullWithAdults();
    float base_inf = MultiMapFixed::GetInfluence();
    return base_inf * (0.5f + 0.5f * full) * built;
}

bool Abode::IsRepaired() {
    // Original at 0x004016a0
    // Calls GetPercentRepaired() through vtable (0x884), returns true if >= 1.0f
    return GetPercentRepaired() >= 1.0f;
}

bool Abode::IsBuilt() {
    // Original at 0x004016c0
    // First checks bit 1 of field_0x58 — if set, not built
    if (field_0x58 & 0x02)
        return false;
    // Otherwise checks if GetPercentBuilt() >= 1.0f
    return GetPercentBuilt() >= 1.0f;
}

float Abode::GetPercentRepairedForNonFunctional() {
    // Original at 0x00407290 — threshold below which abode stops functioning
    return 0.5f;
}

float Abode::GetPercentAbodeFullWithAdults() {
    // Original at 0x00407050 — ratio of adults to max capacity
    // GAbodeInfo::maxAdults at offset 0x174
    uint32_t max_adults = *reinterpret_cast<const uint32_t*>(
        reinterpret_cast<const char*>(info) + 0x174);
    if (max_adults == 0) return 0.0f;
    return static_cast<float>(adult_count) / static_cast<float>(max_adults);
}

float Abode::GetPercentAbodeFullWithChildren() {
    // Original at 0x00407090 — ratio of children to max capacity
    // GAbodeInfo::maxChildren at offset 0x178
    uint32_t max_children = *reinterpret_cast<const uint32_t*>(
        reinterpret_cast<const char*>(info) + 0x178);
    if (max_children == 0) return 0.0f;
    return static_cast<float>(field_0xb7) / static_cast<float>(max_children);
}

bool Abode::Built() {
    // Original at 0x00404720 — called when abode finishes construction
    // Delegates to MultiMapFixed::Built then makes functional
    if (!MultiMapFixed::Built()) return false;
    MakeFunctional();
    return true;
}

bool Abode::Repaired() {
    // Original at 0x004047b0 — called when abode finishes repair
    if (!MultiMapFixed::Repaired()) return false;
    return true;
}

LH3DMesh* Abode::GetDestructionMesh() {
    // Original at 0x00401700
    return destruction_mesh;
}

void Abode::RemoveDamage() {
    // Original at 0x00403f40: clears damage state, restores life, resets destruction mesh
    MultiMapFixed::RemoveDamage();
    if (destruction_mesh) {
        destruction_mesh = nullptr;
    }
}

bool Abode::IsCivic() {
    // Original at 0x00405ff0 — checks GAbodeInfo civic flag at offset 0x16C
    uint32_t flags = *reinterpret_cast<const uint32_t*>(
        reinterpret_cast<const char*>(info) + 0x16C);
    return (flags & 1) != 0;
}

ABODE_TYPE Abode::GetAbodeType() {
    // Original at 0x004061f0: mov eax,[ecx+0x28]; mov eax,[eax+0x120]
    // Reads GAbodeInfo::abodeType at offset 0x120 from info base
    return *reinterpret_cast<const ABODE_TYPE*>(
        reinterpret_cast<const char*>(info) + 0x120);
}

float Abode::GetDesireToBeRepaired() {
    // Original at 0x00406970 — desire to be repaired scales with damage
    if (IsRepaired()) return 0.0f;
    return MultiMapFixed::GetDesireToBeRepaired();
}

uint32_t Abode::DoResourceAdding(RESOURCE_TYPE /*type*/, GInterfaceStatus* /*iface*/, bool /*param3*/, MapCoords* /*param4*/, int /*param5*/) {
    // Original at 0x00404df0 — complex
    // TODO: implement properly
    return 0;
}

uint32_t Abode::DoResourceRemoving(RESOURCE_TYPE /*type*/, uint32_t /*param2*/, GInterfaceStatus* /*iface*/, bool /*param4*/) {
    // Original at 0x00404f60 — complex
    // TODO: implement properly
    return 0;
}

void Abode::SetTown(Town* t) {
    // Original at 0x00401690
    town = t;
}

bool Abode::GetShouldNotBeAddedToPlanned() {
    // Original at 0x00401650
    // Reads byte at offset 0x7c, extracts bit 2
    return (field_0x7c >> 2) & 1;
}

void Abode::SetShouldNotBeAddedToPlanned(bool value) {
    // Original at 0x00401660
    // Sets bit 2 of the byte at offset 0x7c
    field_0x7c = (field_0x7c & ~0x04u) | ((static_cast<uint32_t>(value) & 1u) << 2);
}

PlannedMultiMapFixed* Abode::ConvertToPlanned() {
    // Original at 0x00405050 — complex
    // TODO: implement properly
    return nullptr;
}

// ============================================================================
// New virtual methods (vtable 0x90C-0x928)
// ============================================================================

void Abode::MoveAbodeToPlannedAbodes() {
    // Original at 0x00404520: moves to planned list
    RemoveAllVillagersFromAbode();
}

void Abode::DeleteDependancys() {
    // Original at 0x00403f00: clean up surrounding objects
    DeleteAbodeSurroundingObjects();
}

void Abode::MakeFunctional() {
    // Original at 0x004047e0: notifies town that abode is functional
    AddToPlayer();
    if (town) {
        town->AddStructureToTown(this);
    }
}

void Abode::StopBeingFunctional(GPlayer* /*param1*/) {
    // Original at 0x004073c0: removes from player and town
    RemoveFromPlayer();
}

void Abode::RestartBeingFunctional() {
    // Original at 0x00401680: empty function (no-op)
}

bool Abode::CausesTownEmergencyIfDamaged() {
    // Original at 0x004016f0
    return false;
}

bool Abode::CanBeHiddenIn() {
    // Original at 0x00407280 — abode can hide villagers if functional
    return IsFunctional();
}

GTribeInfo* Abode::GetTribe() {
    // Original at 0x00405f50 — get tribe from town
    if (town) return town->GetTribe();
    return nullptr;
}

// ============================================================================
// Non-virtual methods
// ============================================================================

void Abode::CreateAbodeSurroundingObjects() {
    // Original at 0x00403e00 — creates lanterns, fences etc. around abode
    // Complex rendering objects — stub for now
}

void Abode::DeleteAbodeSurroundingObjects() {
    // Original at 0x00403d20 — removes surrounding objects
    // Complex rendering cleanup — stub for now
}

void Abode::RemoveAllVillagersFromAbode() {
    // Original at 0x00404560: removes all villagers from this abode
    villagers.head = nullptr;
    villagers.count = 0;
    male_female_villagers[0] = nullptr;
    male_female_villagers[1] = nullptr;
    adult_count = 0;
}

void Abode::AddVillagerToAbode(Villager* villager) {
    // Original at 0x00404060: adds villager to abode's villager list
    if (!villager) return;
    // Add to count
    adult_count++;
}

void Abode::RemoveDeletedVillagerFromAbode(Villager* villager) {
    // Original at 0x00404220: removes villager that is being deleted
    if (!villager) return;
    if (male_female_villagers[0] == villager) male_female_villagers[0] = nullptr;
    if (male_female_villagers[1] == villager) male_female_villagers[1] = nullptr;
    if (adult_count > 0) adult_count--;
}

void Abode::RemoveAliveVillagerFromAbode(Villager* villager) {
    // Original at 0x00404340: removes living villager from abode
    if (!villager) return;
    if (male_female_villagers[0] == villager) male_female_villagers[0] = nullptr;
    if (male_female_villagers[1] == villager) male_female_villagers[1] = nullptr;
    if (adult_count > 0) adult_count--;
}

uint8_t Abode::GetNumAdultsInAbode() {
    // Original at 0x004070d0
    return adult_count;
}

int Abode::GetRoomLeftForAdults() {
    // Original at 0x00404660: max adults - current adults
    int32_t max_adults = *reinterpret_cast<const int32_t*>(
        reinterpret_cast<const char*>(info) + 0x174);
    return max_adults - static_cast<int>(adult_count);
}

int Abode::GetRoomLeftForChildren() {
    // Original at 0x00404680: max children - current children
    int32_t max_children = *reinterpret_cast<const int32_t*>(
        reinterpret_cast<const char*>(info) + 0x178);
    return max_children - static_cast<int>(field_0xb7);
}
