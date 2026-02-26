// StoragePit class implementation
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)
// Cross-referenced with bw1-decomp (v1.20)
//
// StoragePit is a resource storage building that manages food and
// wood piles. Methods at 0x0055ccxx-0x0055cdxx are small (~16 bytes).

#include <black/StoragePit.h>

// ============================================================================
// Overrides of Base virtuals
// ============================================================================

void StoragePit::Delete(int /*param*/) {
    // Original at 0x00732c10
    // TODO: implement properly
}

void StoragePit::ToBeDeleted(int /*param*/) {
    // Original at 0x00732c30 — complex
    // TODO: implement properly
}

// ============================================================================
// Overrides of GameThing virtuals
// ============================================================================

uint32_t StoragePit::AddResource(RESOURCE_TYPE /*type*/, uint32_t /*amount*/,
                                  GInterfaceStatus* /*status*/, bool /*param4*/,
                                  const MapCoords& /*coords*/, int /*param6*/) {
    // Original at 0x00732f60 — complex
    // TODO: implement properly
    return 0;
}

uint32_t StoragePit::RemoveResource(RESOURCE_TYPE /*type*/, uint32_t /*amount*/,
                                     GInterfaceStatus* /*status*/, bool* /*param4*/) {
    // Original at 0x007332a0 — complex
    // TODO: implement properly
    return 0;
}

char* StoragePit::GetDebugText() {
    // Original at 0x0055cd40: returns "StoragePit"
    static char text[] = "StoragePit";
    return text;
}

uint32_t StoragePit::Load(GameOSFile* /*file*/) {
    // Original at 0x00733920 — complex serialization
    // TODO: implement when save system is available
    return 0;
}

uint32_t StoragePit::Save(GameOSFile* /*file*/) {
    // Original at 0x007338d0 — complex serialization
    // TODO: implement when save system is available
    return 0;
}

uint32_t StoragePit::GetSaveType() {
    // Original at 0x0055cd30
    // TODO: verify return value
    return 0;
}

// ============================================================================
// Overrides of GameThingWithPos virtuals
// ============================================================================

MapCoords* StoragePit::GetArrivePos(MapCoords* out) {
    // Original at 0x0055ccb0: calls GetDoorPos
    return GetDoorPos(out);
}

bool32_t StoragePit::IsCastShadowAtNight() {
    // Original at 0x0055ccf0: returns 1
    return 1;
}

bool32_t StoragePit::CanBeEatenByCreature(Creature* /*creature*/) {
    // Original at 0x0055cd10: small method
    // TODO: verify return value
    return 1;
}

bool32_t StoragePit::CanActAsAContainer(Creature* /*creature*/) {
    // Original at 0x0055cd00: returns 1
    return 1;
}

bool32_t StoragePit::CanHaveMagicFoodCastOnMe(Creature* /*creature*/) {
    // Original at 0x004e4b50 — complex
    // TODO: implement properly
    return 0;
}

bool32_t StoragePit::CanHaveMagicWoodCastOnMe(Creature* /*creature*/) {
    // Original at 0x004e4b70 — complex
    // TODO: implement properly
    return 0;
}

bool32_t StoragePit::IsStoragePit(Creature* /*creature*/) {
    // Original at 0x004e4990 — complex
    // TODO: implement properly
    return 1;
}

bool32_t StoragePit::IsStoragePitWithFoodInIt(Creature* /*creature*/) {
    // Original at 0x004e4d90 — complex
    // TODO: implement properly
    return 0;
}

bool32_t StoragePit::IsStoragePitBelongingToAnotherPlayer(Creature* /*creature*/) {
    // Original at 0x004e49a0 — complex
    // TODO: implement properly
    return 0;
}

bool32_t StoragePit::IsStoragePitBelongingToMyPlayer(Creature* /*creature*/) {
    // Original at 0x004e49e0 — complex
    // TODO: implement properly
    return 0;
}

bool32_t StoragePit::IsPoisoned() {
    // Original at 0x007336b0 — complex
    // TODO: implement properly
    return 0;
}

// ============================================================================
// Overrides of Object virtuals
// ============================================================================

void StoragePit::Draw() {
    // Original at 0x00519350 — complex rendering
    // TODO: implement when rendering system is available
}

uint32_t StoragePit::GetDiscipleStateIfInteractedWith(GInterfaceStatus* /*status*/,
                                                       Villager* /*villager*/) {
    // Original at 0x00733a20 — complex
    // TODO: implement properly
    return 0;
}

void StoragePit::CallVirtualFunctionsForCreation(const MapCoords& coords) {
    // Original at 0x00732e80 — complex
    // TODO: implement properly
    Abode::CallVirtualFunctionsForCreation(coords);
}

LH3DObject_ObjectType StoragePit::Get3DType() {
    // Original at 0x0055ccd0
    // TODO: verify return value
    return LH3D_OBJECT_TYPE_DEFAULT;
}

bool StoragePit::IsResourceStore(RESOURCE_TYPE /*type*/) {
    // Original at 0x0055cd20: returns true
    return true;
}

bool StoragePit::DeleteObjectAndTakeResource(Object* /*param1*/, GInterfaceStatus* /*param2*/) {
    // Original at 0x00733750 — complex
    // TODO: implement properly
    return false;
}

bool StoragePit::DoCreatureMimicAfterAddingResource(RESOURCE_TYPE /*type*/,
                                                     GInterfaceStatus* /*status*/) {
    // Original at 0x00733810 — complex
    // TODO: implement properly
    return false;
}

void StoragePit::SetPoisonedResource(RESOURCE_TYPE /*type*/, int /*param2*/) {
    // Original at 0x007335f0 — complex
    // TODO: implement properly
}

void StoragePit::SetPoisoned(int /*param1*/) {
    // Original at 0x007335d0 — complex
    // TODO: implement properly
}

void StoragePit::ReactToPhysicsImpact(PhysicsObject* /*param1*/, bool /*param2*/) {
    // Original at 0x00733730 — complex
    // TODO: implement properly
}

// ============================================================================
// Overrides of MultiMapFixed virtuals
// ============================================================================

bool StoragePit::IsPoisonedResource() {
    // Original at 0x00733550 — complex
    // TODO: implement properly
    return false;
}

MapCoords* StoragePit::GetResourceNearestEdge(MapCoords* /*coords*/, RESOURCE_TYPE /*type*/,
                                               Object* /*param3*/, int /*param4*/) {
    // Original at 0x00733400 — complex
    // TODO: implement properly
    return nullptr;
}

int StoragePit::CalulateAmountOverMaximum(RESOURCE_TYPE /*type*/) {
    // Original at 0x00733260 — complex
    // TODO: implement properly
    return 0;
}

void StoragePit::RemovePotFromStructure(PotStructure* /*structure*/) {
    // Original at 0x007331d0 — complex
    // TODO: implement properly
}

// ============================================================================
// Overrides of Abode virtuals
// ============================================================================

void StoragePit::DeleteDependancys() {
    // Original at 0x00732cd0 — complex
    // TODO: implement properly
}

void StoragePit::MakeFunctional() {
    // Original at 0x00732f30 — complex
    // TODO: implement properly
}

void StoragePit::StopBeingFunctional(GPlayer* /*param1*/) {
    // Original at 0x00733960 — complex
    // TODO: implement properly
}

void StoragePit::RestartBeingFunctional() {
    // Original at 0x007339d0 — complex
    // TODO: implement properly
}

bool StoragePit::CausesTownEmergencyIfDamaged() {
    // Original at 0x0055cce0: returns true
    return true;
}
