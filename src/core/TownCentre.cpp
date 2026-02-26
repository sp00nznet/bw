// TownCentre class implementation
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)
// Cross-referenced with bw1-decomp (v1.20)
//
// TownCentre is the administrative hub for a town. Methods at
// 0x0055dbxx are small (~16 bytes each).

#include <black/TownCentre.h>

// ============================================================================
// Overrides of Base virtuals
// ============================================================================

void TownCentre::ToBeDeleted(int /*param*/) {
    // Original at 0x00743b40 — complex
}

// ============================================================================
// Overrides of GameThing virtuals
// ============================================================================

char* TownCentre::GetDebugText() {
    static char text[] = "TownCentre";
    return text;
}

uint32_t TownCentre::Load(GameOSFile* /*file*/) {
    // Original at 0x00744880 — complex
    return 0;
}

uint32_t TownCentre::Save(GameOSFile* /*file*/) {
    // Original at 0x00744830 — complex
    return 0;
}

uint32_t TownCentre::GetSaveType() {
    // Original at 0x0055db90
    return 0;
}

void TownCentre::ResolveLoad() {
    // Original at 0x007448c0 — complex
}

// ============================================================================
// Overrides of GameThingWithPos virtuals
// ============================================================================

MapCoords* TownCentre::GetArrivePos(MapCoords* out) {
    // Original at 0x007449e0: calls GetDoorPos
    return GetDoorPos(out);
}

bool32_t TownCentre::IsCastShadowAtNight() {
    // Original at 0x0055db60: returns 1
    return 1;
}

bool32_t TownCentre::IsTownCentre() {
    // Original at 0x0055db70: returns 1
    return 1;
}

bool32_t TownCentre::CanActAsAContainer(Creature* /*creature*/) {
    // Original at 0x0055db40
    return 1;
}

bool32_t TownCentre::IsStoragePit(Creature* /*creature*/) {
    // Original at 0x0055db50
    return 0;
}

// ============================================================================
// Overrides of Object virtuals
// ============================================================================

void TownCentre::ReduceLife(float /*value*/, GPlayer* /*player*/) {
    // Original at 0x007445d0 — complex
}

void TownCentre::IncreaseLife(float /*value*/) {
    // Original at 0x00744320 — complex
}

uint32_t TownCentre::Process() {
    // Original at 0x00743df0 — complex
    return 0;
}

void TownCentre::Draw() {
    // Original at 0x00516450 — complex rendering
}

uint32_t TownCentre::GetDiscipleStateIfInteractedWith(GInterfaceStatus* /*status*/,
                                                       Villager* /*villager*/) {
    // Original at 0x007448e0 — complex
    return 0;
}

void TownCentre::CallVirtualFunctionsForCreation(const MapCoords& coords) {
    // Original at 0x00743cf0 — complex
    Abode::CallVirtualFunctionsForCreation(coords);
}

LH3DObject_ObjectType TownCentre::Get3DType() {
    // Original at 0x0055db20
    return LH3D_OBJECT_TYPE_DEFAULT;
}

uint32_t TownCentre::InterfaceValidToTap(GInterfaceStatus* /*status*/) {
    // Original at 0x0055db10: returns 1
    return 1;
}

bool TownCentre::InteractsWithPhysicsObjects() {
    // Original at 0x00743bc0: returns false
    return false;
}

void TownCentre::ReactToPhysicsImpact(PhysicsObject* /*param1*/, bool /*param2*/) {
    // Original at 0x00744380 — complex
}

size_t TownCentre::SaveObject(LHOSFile* /*param1*/, const MapCoords* /*param2*/) {
    // Original at 0x00744140 — complex
    return 0;
}

// ============================================================================
// Overrides of MultiMapFixed virtuals
// ============================================================================

MapCoords* TownCentre::GetDoorPos(MapCoords* pos) {
    // Original at 0x00744940 — complex
    *pos = coords;
    return pos;
}

void TownCentre::AddToPlayer() {
    // Original at 0x007443a0 — complex
}

PlannedMultiMapFixed* TownCentre::ConvertToPlanned() {
    // Original at 0x007443c0 — complex
    return nullptr;
}

// ============================================================================
// Overrides of Abode virtuals
// ============================================================================

void TownCentre::DeleteDependancys() {
    // Original at 0x00743be0 — complex
}

void TownCentre::MakeFunctional() {
    // Original at 0x00743e80 — complex
}

void TownCentre::StopBeingFunctional(GPlayer* /*param1*/) {
    // Original at 0x00744a00 — complex
}

bool TownCentre::CausesTownEmergencyIfDamaged() {
    // Original at 0x0055db30: returns true
    return true;
}

bool TownCentre::CanBeHiddenIn() {
    // Original at 0x0055db80: returns true
    return true;
}
