// Abode class implementation
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)
// Cross-referenced with bw1-decomp (v1.20)
//
// Residential building class — houses villagers, manages food/wood
// resources, handles building/repair lifecycle.

#include <black/Abode.h>

// ============================================================================
// Overrides of Base virtuals
// ============================================================================

void Abode::Delete(int /*param*/) {
    // Original at 0x00402c10 — complex (removes from town, cleans up)
    // TODO: implement properly
}

void Abode::ToBeDeleted(int /*param*/) {
    // Original at 0x00402c60 — complex
    // TODO: implement properly
}

// ============================================================================
// Overrides of GameThing virtuals
// ============================================================================

GPlayer* Abode::GetPlayer() {
    // Original at 0x00405f70 — reads player from town
    // TODO: implement when Town/GPlayer system is available
    return nullptr;
}

Town* Abode::GetTown() {
    // Original at 0x00401730
    return town;
}

uint32_t Abode::JustAddResource(RESOURCE_TYPE type, uint32_t amount, bool /*param3*/) {
    // Original at 0x00404d40
    // TODO: implement properly (likely resources[type] += amount)
    return 0;
}

uint32_t Abode::JustRemoveResource(RESOURCE_TYPE type, uint32_t amount, bool* /*param3*/) {
    // Original at 0x00404d60 — complex (clamping logic)
    // TODO: implement properly
    return 0;
}

uint32_t Abode::GetResource(RESOURCE_TYPE type) {
    // Original at 0x00404d30: mov eax,[ecx+0x28]; mov eax,[eax+type*4+0xBC]
    // Reads directly from the resources array
    return resources[type];
}

uint32_t Abode::AddResource(RESOURCE_TYPE /*type*/, uint32_t /*amount*/, GInterfaceStatus* /*status*/, bool /*param4*/, const MapCoords& /*coords*/, int /*param6*/) {
    // Original at 0x00404d90 — complex resource system
    // TODO: implement when resource system is available
    return 0;
}

uint32_t Abode::RemoveResource(RESOURCE_TYPE /*type*/, uint32_t /*amount*/, GInterfaceStatus* /*status*/, bool* /*param4*/) {
    // Original at 0x00404f10 — complex resource system
    // TODO: implement when resource system is available
    return 0;
}

Abode* Abode::CastAbode() {
    // Original at 0x00401640
    return this;
}

uint16_t Abode::GetNumberOfInstanceForGlobalList() {
    // Original at 0x00403f10 — complex
    // TODO: implement properly
    return 1;
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
    // Original at 0x00407200 — complex
    // TODO: implement properly
    return false;
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
    // Original at 0x004d1b60 — complex
    // TODO: implement properly
    return 0.0f;
}

void Abode::CalculateWhereIWillBeAfterNSeconds(float /*seconds*/, LHPoint* /*outPos*/) {
    // Original at 0x0063b940 — complex
    // TODO: implement properly
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
    // Original at 0x00406810 — complex
    // TODO: implement properly
    return 0;
}

// ============================================================================
// Overrides of Object virtuals
// ============================================================================

void Abode::DestroyedByBeam() {
    // Original at 0x00402cb0 — complex
    // TODO: implement properly
}

void Abode::InsertMapObject() {
    // Original at 0x00403ee0 — complex
    // TODO: implement properly
}

bool Abode::GetPSysFireLocalRndFlamePos(LHPoint* /*point*/, int* /*param2*/) {
    // Original at 0x00402cf0 — complex
    // TODO: implement properly
    return false;
}

void Abode::ReduceLife(float /*value*/, GPlayer* /*player*/) {
    // Original at 0x00405d90 — complex (damage system)
    // TODO: implement properly
}

void Abode::IncreaseLife(float /*value*/) {
    // Original at 0x00405ed0 — complex
    // TODO: implement properly
}

uint32_t Abode::DestroyedByEffect(GPlayer* /*player*/, float /*param2*/) {
    // Original at 0x00403f80 — complex
    // TODO: implement properly
    return 0;
}

uint32_t Abode::Process() {
    // Original at 0x00404440 — complex building process loop
    // TODO: implement properly
    return 0;
}

int Abode::GetMesh() const {
    // Original at 0x00404aa0 — complex
    // TODO: implement properly
    return 0;
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
    // Original at 0x00402dc0 — complex
    // TODO: implement properly
    return 0;
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
    // Original at 0x00406800 — complex
    // TODO: implement properly
    return false;
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
    // Original at 0x00403ef0 — complex
    // TODO: implement properly
    return false;
}

// ============================================================================
// Overrides of MultiMapFixed virtuals
// ============================================================================

float Abode::GetInfluence() {
    // Original at 0x004072a0 — complex
    // TODO: implement properly
    return 0.0f;
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
    // Original at 0x00407290 — complex
    // TODO: implement properly
    return 0.0f;
}

float Abode::GetPercentAbodeFullWithAdults() {
    // Original at 0x00407050 — complex
    // TODO: implement properly
    return 0.0f;
}

float Abode::GetPercentAbodeFullWithChildren() {
    // Original at 0x00407090 — complex
    // TODO: implement properly
    return 0.0f;
}

bool Abode::Built() {
    // Original at 0x00404720 — complex
    // TODO: implement properly
    return false;
}

bool Abode::Repaired() {
    // Original at 0x004047b0 — complex
    // TODO: implement properly
    return false;
}

LH3DMesh* Abode::GetDestructionMesh() {
    // Original at 0x00401700
    return destruction_mesh;
}

void Abode::RemoveDamage() {
    // Original at 0x00403f40 — complex
    // TODO: implement properly
}

bool Abode::IsCivic() {
    // Original at 0x00405ff0 — complex
    // TODO: implement properly
    return false;
}

ABODE_TYPE Abode::GetAbodeType() {
    // Original at 0x004061f0: mov eax,[ecx+0x28]; mov eax,[eax+0x120]
    // Reads GAbodeInfo::abodeType at offset 0x120 from info base
    return *reinterpret_cast<const ABODE_TYPE*>(
        reinterpret_cast<const char*>(info) + 0x120);
}

float Abode::GetDesireToBeRepaired() {
    // Original at 0x00406970 — complex
    // TODO: implement properly
    return 0.0f;
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
    // Original at 0x00404520 — complex
    // TODO: implement properly
}

void Abode::DeleteDependancys() {
    // Original at 0x00403f00 — complex
    // TODO: implement properly
}

void Abode::MakeFunctional() {
    // Original at 0x004047e0 — complex
    // TODO: implement properly
}

void Abode::StopBeingFunctional(GPlayer* /*param1*/) {
    // Original at 0x004073c0 — complex
    // TODO: implement properly
}

void Abode::RestartBeingFunctional() {
    // Original at 0x00401680: empty function (no-op)
}

bool Abode::CausesTownEmergencyIfDamaged() {
    // Original at 0x004016f0
    return false;
}

bool Abode::CanBeHiddenIn() {
    // Original at 0x00407280 — complex
    // TODO: implement properly
    return false;
}

GTribeInfo* Abode::GetTribe() {
    // Original at 0x00405f50 — complex
    // TODO: implement properly
    return nullptr;
}
