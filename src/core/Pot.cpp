// Pot class implementation
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)
// Cross-referenced with bw1-decomp (v1.20)
//
// Pot is a moveable food/wood container. Methods at 0x0055d4xx-0x0055d5xx
// are small (~16 bytes each).

#include <black/Pot.h>

// ============================================================================
// Overrides of Base virtuals
// ============================================================================

void Pot::ToBeDeleted(int /*param*/) {
    // Original at 0x0066d110 — complex
    // TODO: implement properly
}

// ============================================================================
// Overrides of GameThing virtuals
// ============================================================================

uint32_t Pot::JustAddResource(RESOURCE_TYPE /*type*/, uint32_t /*amount*/, bool /*param3*/) {
    // Original at 0x0066d2b0 — complex
    // TODO: implement properly
    return 0;
}

uint32_t Pot::JustRemoveResource(RESOURCE_TYPE /*type*/, uint32_t /*amount*/, bool* /*param3*/) {
    // Original at 0x0066d410 — complex
    // TODO: implement properly
    return 0;
}

uint32_t Pot::JustGetResource(RESOURCE_TYPE /*type*/, uint32_t /*amount*/, bool* /*param3*/) {
    // Original at 0x0066d390 — complex
    // TODO: implement properly
    return 0;
}

uint32_t Pot::GetResource(RESOURCE_TYPE /*type*/) {
    // Original at 0x0066d3d0 — complex
    // TODO: implement properly
    return 0;
}

uint32_t Pot::AddResource(RESOURCE_TYPE /*type*/, uint32_t /*amount*/,
                           GInterfaceStatus* /*status*/, bool /*param4*/,
                           const MapCoords& /*coords*/, int /*param6*/) {
    // Original at 0x0066d290 — complex
    // TODO: implement properly
    return 0;
}

uint32_t Pot::RemoveResource(RESOURCE_TYPE /*type*/, uint32_t /*amount*/,
                              GInterfaceStatus* /*status*/, bool* /*param4*/) {
    // Original at 0x0066d3f0 — complex
    // TODO: implement properly
    return 0;
}

char* Pot::GetDebugText() {
    // Original at 0x0055d5b0: returns "Pot"
    static char text[] = "Pot";
    return text;
}

uint32_t Pot::GetGuidanceResourceType() {
    // Original at 0x0071bde0 — complex
    // TODO: implement properly
    return 0;
}

uint32_t Pot::Load(GameOSFile* /*file*/) {
    // Original at 0x0066d820 — complex serialization
    // TODO: implement when save system is available
    return 0;
}

uint32_t Pot::Save(GameOSFile* /*file*/) {
    // Original at 0x0066d730 — complex serialization
    // TODO: implement when save system is available
    return 0;
}

uint32_t Pot::GetSaveType() {
    // Original at 0x0055d5a0
    // TODO: verify return value
    return 0;
}

// ============================================================================
// Overrides of GameThingWithPos virtuals
// ============================================================================

uint32_t Pot::GetCreatureBeliefType() {
    // Original at 0x0055d580
    // TODO: verify return value
    return 0;
}

uint32_t Pot::GetOverwriteInteractableToolTip() {
    // Original at 0x0066f540 — complex
    // TODO: implement properly
    return 0;
}

bool32_t Pot::IsPoisoned() {
    // Original at 0x0055d4e0: reads flag from field_0x74
    return (field_0x74 & 0x01) ? 1 : 0;
}

bool32_t Pot::IsSpeedUp() {
    // Original at 0x0055d4f0: reads flag from field_0x74
    return (field_0x74 & 0x02) ? 1 : 0;
}

bool32_t Pot::IsPot() {
    // Original at 0x0055d500: returns 1
    return 1;
}

uint32_t Pot::GetScriptObjectType() {
    // Original at 0x0066f530 — complex
    // TODO: implement properly
    return 0;
}

// ============================================================================
// Overrides of Object virtuals
// ============================================================================

void Pot::Draw() {
    // Original at 0x0051bb70 — complex rendering
    // TODO: implement when rendering system is available
}

void Pot::DrawOutOfMap(bool /*param1*/) {
    // Original at 0x0051bbc0 — complex rendering
    // TODO: implement when rendering system is available
}

void Pot::CallVirtualFunctionsForCreation(const MapCoords& coords) {
    // Original at 0x0066d130 — complex
    // TODO: implement properly
    MobileObject::CallVirtualFunctionsForCreation(coords);
}

float Pot::GetFoodValue(FOOD_TYPE /*type*/) {
    // Original at 0x0066f570 — complex
    // TODO: implement properly
    return 0.0f;
}

bool Pot::IsResourceStore(RESOURCE_TYPE /*type*/) {
    // Original at 0x0066f560 — complex
    // TODO: implement properly
    return false;
}

bool Pot::DeleteObjectAndTakeResource(Object* /*param1*/, GInterfaceStatus* /*param2*/) {
    // Original at 0x0066dd30 — complex
    // TODO: implement properly
    return false;
}

float Pot::GetRadiusMultiplierForApplyingPotToPos() {
    // Original at 0x0066f520
    // TODO: verify return value
    return 1.0f;
}

RESOURCE_TYPE Pot::GetResourceType() {
    // Original at 0x0055d4c0: returns field_0x68
    return field_0x68;
}

int Pot::GetDefaultResource() {
    // Original at 0x0055d4d0
    // TODO: verify return value
    return 0;
}

void Pot::SetPoisonedResource(RESOURCE_TYPE /*type*/, int /*param2*/) {
    // Original at 0x0055d550 — complex
    // TODO: implement properly
}

void Pot::SetPoisoned(int /*param1*/) {
    // Original at 0x0055d510: sets flag in field_0x74
    // TODO: verify exact implementation
}

void Pot::StartOnFire() {
    // Original at 0x0066d6c0 — complex
    // TODO: implement properly
}

void Pot::EndOnFire() {
    // Original at 0x0066d6d0 — complex
    // TODO: implement properly
}

bool32_t Pot::InterfaceSetInMagicHand(GInterfaceStatus* /*status*/) {
    // Original at 0x0066d710 — complex
    // TODO: implement properly
    return 0;
}

uint32_t Pot::ValidToApplyThisToObject(GInterfaceStatus* /*status*/, Object* /*param2*/) {
    // Original at 0x0066dd50 — complex
    // TODO: implement properly
    return 0;
}

uint32_t Pot::ApplyThisToObject(GInterfaceStatus* /*status*/, Object* /*param2*/,
                                 GestureSystemPacketData* /*param3*/) {
    // Original at 0x0066ddd0 — complex
    // TODO: implement properly
    return 0;
}

uint32_t Pot::ApplyThisToMapCoord(GInterfaceStatus* /*status*/, const MapCoords* /*param2*/,
                                   GestureSystemPacketData* /*param3*/) {
    // Original at 0x0066de70 — complex
    // TODO: implement properly
    return 0;
}

bool32_t Pot::IsEffectReceiver(EffectValues* /*param1*/) {
    // Original at 0x0066d650 — complex
    // TODO: implement properly
    return 0;
}

uint32_t Pot::InitialisePhysicsFromHand(LHPoint* /*p1*/, LHPoint* /*p2*/,
                                         GInterfaceStatus* /*p3*/, Object* /*p4*/, int /*p5*/) {
    // Original at 0x0066df00 — complex
    // TODO: implement properly
    return 0;
}

uint32_t Pot::GetPhysicsConstantsType() {
    // Original at 0x0066cef0 — complex
    // TODO: implement properly
    return 0;
}

void Pot::EndPhysics(PhysicsObject* /*param1*/, bool /*param2*/) {
    // Original at 0x0066dbd0 — complex
    // TODO: implement properly
}

bool Pot::InteractsWithPhysicsObjects() {
    // Original at 0x0066ced0: returns true
    return true;
}

void Pot::ReactToPhysicsImpact(PhysicsObject* /*param1*/, bool /*param2*/) {
    // Original at 0x0066dc90 — complex
    // TODO: implement properly
}

bool Pot::CanBecomeAPhysicsObject() {
    // Original at 0x0066e8f0 — complex
    // TODO: implement properly
    return false;
}

size_t Pot::SaveObject(LHOSFile* /*param1*/, const MapCoords* /*param2*/) {
    // Original at 0x0066d550 — complex
    // TODO: implement when save system is available
    return 0;
}

bool Pot::IsAPotFromABuildingSite() {
    // Original at 0x0055d590
    // TODO: verify return value
    return false;
}

// ============================================================================
// New virtual methods
// ============================================================================

void Pot::SetSize() {
    // Original at inlined — complex
    // TODO: implement properly
}

bool Pot::IsPartOfStructure() {
    // Original at inlined — complex
    // TODO: implement properly
    return false;
}

void Pot::SetSpeedUp(int /*speed*/) {
    // Original at inlined — complex
    // TODO: implement properly
}

void Pot::SetMultiMapFixed(MultiMapFixed* /*multiMapFixed*/) {
    // Original at inlined — complex
    // TODO: implement properly
}
