// Scaffold class implementation
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)
// Cross-referenced with bw1-decomp (v1.20)
//
// Scaffold is the construction framework at building sites.
// Simple methods at 0x0055e0xx-0x0055e1xx are 16 bytes apart.
// Complex methods at 0x006e83xx-0x006eafxx.

#include <black/Scaffold.h>

// ============================================================================
// Overrides of Base virtuals
// ============================================================================

void Scaffold::ToBeDeleted(int /*param*/) {
    // Original at 0x006e83e0 — complex
}

// ============================================================================
// Overrides of GameThing virtuals
// ============================================================================

Town* Scaffold::GetTown() {
    // Original at 0x0055e120: returns town from internal data
    return nullptr;
}

uint32_t Scaffold::AddResource(RESOURCE_TYPE /*type*/, uint32_t /*amount*/,
                                GInterfaceStatus* /*status*/, bool /*param4*/,
                                const MapCoords& /*coords*/, int /*param6*/) {
    // Original at 0x006eaef0 — complex
    return 0;
}

void Scaffold::DrawInHand(GInterfaceStatus* /*status*/) {
    // Original at 0x005181a0 — complex rendering
}

char* Scaffold::GetDebugText() {
    static char text[] = "Scaffold";
    return text;
}

uint32_t Scaffold::Load(GameOSFile* /*file*/) {
    // Original at 0x006ea3d0 — complex serialization
    return 0;
}

uint32_t Scaffold::Save(GameOSFile* /*file*/) {
    // Original at 0x006ea240 — complex serialization
    return 0;
}

uint32_t Scaffold::GetSaveType() {
    // Original at 0x0055e130
    return 0;
}

void Scaffold::ResolveLoad() {
    // Original at 0x006ea560 — complex
}

// ============================================================================
// Overrides of GameThingWithPos virtuals
// ============================================================================

uint32_t Scaffold::GetOverwritePickUpToolTip() {
    // Original at 0x006ea9d0 — complex
    return 0;
}

uint32_t Scaffold::GetOverwriteDropToolTip() {
    // Original at 0x006e9860 — complex
    return 0;
}

float Scaffold::GetImpressiveValue(Living* /*param1*/, Reaction* /*param2*/) {
    // Original at 0x006ea770 — complex
    return 0.0f;
}

float Scaffold::GetUpdateOfBoredomValue(Reaction* /*param1*/, GameThingWithPos* /*param2*/) {
    // Original at 0x006ea9e0 — complex
    return 0.0f;
}

bool32_t Scaffold::CanBePickedUpByCreature(Creature* /*creature*/) {
    // Original at 0x004e3fc0 — complex
    return 0;
}

bool32_t Scaffold::CanBeStolenByCreature(Creature* /*creature*/) {
    // Original at 0x004e3ff0 — complex
    return 0;
}

bool32_t Scaffold::IsStealableScaffold(Creature* /*creature*/) {
    // Original at 0x004e4070 — complex
    return 0;
}

bool32_t Scaffold::IsScaffold() {
    // Original at 0x0055e100: returns 1
    return 1;
}

uint32_t Scaffold::GetScriptObjectType() {
    // Original at 0x006eab60 — complex
    return 0;
}

// ============================================================================
// Overrides of Object virtuals
// ============================================================================

void Scaffold::ActualMoveMapObject(const MapCoords& /*coords*/) {
    // Original at 0x006e9890 — complex
}

void Scaffold::Draw() {
    // Original at 0x006ea5c0 — complex rendering
}

void Scaffold::CallVirtualFunctionsForCreation(const MapCoords& coords) {
    // Original at 0x006e8540 — complex
    MobileObject::CallVirtualFunctionsForCreation(coords);
}

bool Scaffold::IsResourceStore(RESOURCE_TYPE /*type*/) {
    // Original at 0x006eaea0 — complex
    return false;
}

bool Scaffold::DeleteObjectAndTakeResource(Object* /*obj*/, GInterfaceStatus* /*status*/) {
    // Original at 0x006eaec0 — complex
    return false;
}

RESOURCE_TYPE Scaffold::GetResourceType() {
    // Original at 0x0055e0f0: returns resource type
    return RESOURCE_TYPE(0);
}

int Scaffold::GetDefaultResource() {
    // Original at 0x006e9d30 — complex
    return 0;
}

uint32_t Scaffold::ValidForPlaceInHand(GInterfaceStatus* /*status*/) {
    // Original at 0x006e96a0 — complex
    return 0;
}

uint32_t Scaffold::InterfaceSetInMagicHand(GInterfaceStatus* /*status*/) {
    // Original at 0x006e96e0 — complex
    return 0;
}

uint32_t Scaffold::InterfaceSetOutMagicHand(GInterfaceStatus* /*status*/) {
    // Original at 0x006e9770 — complex
    return 0;
}

uint32_t Scaffold::ValidToApplyThisToObject(GInterfaceStatus* /*status*/, Object* /*target*/) {
    // Original at 0x006e9900 — complex
    return 0;
}

uint32_t Scaffold::ApplyThisToObject(GInterfaceStatus* /*status*/, Object* /*target*/,
                                      GestureSystemPacketData* /*data*/) {
    // Original at 0x006e99e0 — complex
    return 0;
}

uint32_t Scaffold::InterfaceValidToTap(GInterfaceStatus* /*status*/) {
    // Original at 0x006e9d80 — complex
    return 0;
}

uint32_t Scaffold::InterfaceTap(GInterfaceStatus* /*status*/) {
    // Original at 0x006e9dd0 — complex
    return 0;
}

uint32_t Scaffold::ThrowObjectFromHand(GInterfaceStatus* /*status*/, int /*param*/) {
    // Original at 0x006eab70 — complex
    return 0;
}

uint32_t Scaffold::InitialisePhysicsFromHand(LHPoint* /*param1*/, LHPoint* /*param2*/,
                                              GInterfaceStatus* /*status*/,
                                              Object* /*param4*/, int /*param5*/) {
    // Original at 0x006ea8a0 — complex
    return 0;
}

uint32_t Scaffold::InitialisePhysics(const LHPoint* /*param1*/, const LHPoint* /*param2*/,
                                      Object* /*param3*/, bool /*param4*/,
                                      GInterfaceStatus* /*status*/) {
    // Original at 0x006ea840 — complex
    return 0;
}

uint32_t Scaffold::GetPhysicsConstantsType() {
    // Original at 0x006e8770 — complex
    return 0;
}

void Scaffold::EndPhysics(PhysicsObject* /*param1*/, bool /*param2*/) {
    // Original at 0x006e8780 — complex
}

bool Scaffold::InteractsWithPhysicsObjects() {
    // Original at 0x0055e110: returns true
    return true;
}

void Scaffold::ReactToPhysicsImpact(PhysicsObject* /*param1*/, bool /*param2*/) {
    // Original at 0x006ea940 — complex
}

bool Scaffold::CanBecomeAPhysicsObject() {
    // Original at 0x006ea910 — complex
    return false;
}

bool Scaffold::ProcessInHand() {
    // Original at 0x006e8570 — complex
    return false;
}

size_t Scaffold::SaveObject(LHOSFile* /*param1*/, const MapCoords* /*param2*/) {
    // Original at 0x006eaf30 — complex
    return 0;
}
