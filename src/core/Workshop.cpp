// Workshop class implementation
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)
// Cross-referenced with bw1-decomp (v1.20)
//
// Workshop is a crafting building where villagers produce
// scaffolding and building materials. Methods at 0x007792xx
// are small (~16 bytes each), those at 0x0077xxxx are complex.

#include <black/Workshop.h>

// ============================================================================
// Overrides of Base virtuals
// ============================================================================

void Workshop::ToBeDeleted(int /*param*/) {
    // Original at 0x00779480 — complex
    // TODO: implement properly
}

// ============================================================================
// Overrides of GameThing virtuals
// ============================================================================

uint32_t Workshop::AddResource(RESOURCE_TYPE /*type*/, uint32_t /*amount*/,
                               GInterfaceStatus* /*status*/, bool /*param4*/,
                               const MapCoords& /*coords*/, int /*param6*/) {
    // Original at 0x00779e00 — complex resource management
    // TODO: implement properly
    return 0;
}

uint32_t Workshop::RemoveResource(RESOURCE_TYPE /*type*/, uint32_t /*amount*/,
                                  GInterfaceStatus* /*status*/, bool* /*param4*/) {
    // Original at 0x00779ec0 — complex resource management
    // TODO: implement properly
    return 0;
}

char* Workshop::GetDebugText() {
    // Original at 0x00779310: returns pointer to "Workshop" string
    static char text[] = "Workshop";
    return text;
}

uint32_t Workshop::GetShowNeedsPos(uint32_t /*param1*/, MapCoords* /*param2*/) {
    // Original at 0x0077a630 — complex
    // TODO: implement properly
    return 0;
}

uint32_t Workshop::Load(GameOSFile* /*file*/) {
    // Original at 0x0077a130 — complex serialization
    // TODO: implement when save system is available
    return 0;
}

uint32_t Workshop::Save(GameOSFile* /*file*/) {
    // Original at 0x00779f40 — complex serialization
    // TODO: implement when save system is available
    return 0;
}

uint32_t Workshop::GetSaveType() {
    // Original at 0x00779300
    // TODO: verify return value from Ghidra
    return 0;
}

void Workshop::ResolveLoad() {
    // Original at 0x0077a330 — complex
    // TODO: implement when save system is available
}

// ============================================================================
// Overrides of GameThingWithPos virtuals
// ============================================================================

bool32_t Workshop::CanActAsAContainer(Creature* /*creature*/) {
    // Original at 0x007792e0: small method (~16 bytes)
    // Workshops can act as containers for building materials
    return 1;
}

bool32_t Workshop::IsStoragePit(Creature* /*creature*/) {
    // Original at 0x007792f0: small method (~16 bytes)
    // TODO: verify — may return 0 or 1
    return 0;
}

bool32_t Workshop::IsWorkshop_0() {
    // Original at 0x007792c0: returns 1
    return 1;
}

bool32_t Workshop::IsWorkshop_1(Creature* /*creature*/) {
    // Original at 0x007792d0: returns 1
    return 1;
}

bool32_t Workshop::CreateBuildingSite() {
    // Original at 0x0077a6d0 — complex
    // TODO: implement properly
    return 0;
}

// ============================================================================
// Overrides of Object virtuals
// ============================================================================

void Workshop::ScaffoldMoved(Scaffold* /*scaffold*/) {
    // Original at 0x0077a610 — complex
    // TODO: implement properly
}

uint32_t Workshop::Process() {
    // Original at 0x007797f0 — complex processing
    // TODO: implement properly
    return 0;
}

void Workshop::Draw() {
    // Original at 0x0051cbf0 — complex rendering
    // TODO: implement when rendering system is available
}

uint32_t Workshop::GetDiscipleStateIfInteractedWith(GInterfaceStatus* /*status*/,
                                                     Villager* /*villager*/) {
    // Original at 0x0077a340 — complex
    // TODO: implement properly
    return 0;
}

void Workshop::CallVirtualFunctionsForCreation(const MapCoords& coords) {
    // Original at 0x007793e0 — complex
    // TODO: implement properly
    Abode::CallVirtualFunctionsForCreation(coords);
}

LH3DObject_ObjectType Workshop::Get3DType() {
    // Original at 0x007792b0
    // TODO: verify return value from Ghidra
    return LH3D_OBJECT_TYPE_DEFAULT;
}

bool Workshop::IsResourceStore(RESOURCE_TYPE /*type*/) {
    // Original at 0x0077a650 — complex
    // TODO: implement properly
    return false;
}

bool Workshop::DeleteObjectAndTakeResource(Object* /*param1*/, GInterfaceStatus* /*param2*/) {
    // Original at 0x00779f20 — complex
    // TODO: implement properly
    return false;
}

bool Workshop::DoCreatureMimicAfterAddingResource(RESOURCE_TYPE /*type*/,
                                                   GInterfaceStatus* /*status*/) {
    // Original at 0x0077a680 — complex
    // TODO: implement properly
    return false;
}

// ============================================================================
// Non-virtual methods
// ============================================================================

int Workshop::GetSpaceInStore() {
    // Original at 0x00779af0 — complex
    // TODO: implement properly
    return 0;
}

float Workshop::GetDesireToBeSupplied() {
    // Original at 0x00779b60 — complex
    // TODO: implement properly
    return 0.0f;
}

float Workshop::GetVisualWoodDesire() {
    // Original at 0x00779b90 — complex
    // TODO: implement properly
    return 0.0f;
}
