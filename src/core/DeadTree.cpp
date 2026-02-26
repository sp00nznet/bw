// DeadTree class implementation
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)
// Cross-referenced with bw1-decomp (v1.20)
//
// Trivial methods at 0x005109xx are packed 16 bytes apart.
// Complex methods at 0x00510axx-0x00511axx.

#include <black/DeadTree.h>

// ============================================================================
// Overrides of Base virtuals
// ============================================================================

void DeadTree::ToBeDeleted(int /*param*/) {
    // Original at 0x00510c90 — complex
}

// ============================================================================
// Overrides of GameThing virtuals
// ============================================================================

uint32_t DeadTree::RemoveResource(RESOURCE_TYPE /*type*/, uint32_t /*amount*/,
                                   GInterfaceStatus* /*status*/, bool* /*param4*/) {
    // Original at 0x00511370 — complex
    return 0;
}

char* DeadTree::GetDebugText() {
    // Original at 0x005109f0
    static char text[] = "DeadTree";
    return text;
}

uint32_t DeadTree::GetGuidanceResourceType() {
    // Original at 0x0071be30 — complex
    return 0;
}

uint32_t DeadTree::Load(GameOSFile* /*file*/) {
    // Original at 0x00511630 — complex serialization
    return 0;
}

uint32_t DeadTree::Save(GameOSFile* /*file*/) {
    // Original at 0x005115c0 — complex serialization
    return 0;
}

uint32_t DeadTree::GetSaveType() {
    // Original at 0x005109e0
    return 0;
}

// ============================================================================
// Overrides of GameThingWithPos virtuals
// ============================================================================

bool32_t DeadTree::IsRock_0() {
    // Original at 0x005109d0: returns 0
    return 0;
}

bool32_t DeadTree::IsAnyKindOfTree() {
    // Original at 0x00510980: returns 1
    return 1;
}

bool32_t DeadTree::IsDeadTree() {
    // Original at 0x00510990: returns 1
    return 1;
}

uint32_t DeadTree::GetScriptObjectType() {
    // Original at 0x005115b0 — complex
    return 0;
}

// ============================================================================
// Overrides of Object virtuals
// ============================================================================

HOLD_TYPE DeadTree::GetHoldType() {
    // Original at 0x005110d0 — complex
    return HOLD_TYPE_DEFAULT;
}

float DeadTree::GetHoldRadius() {
    // Original at 0x005110e0 — complex
    return 0.0f;
}

float DeadTree::GetHoldLoweringMultiplier() {
    // Original at 0x005110f0 — complex
    return 0.0f;
}

bool32_t DeadTree::HandShouldFeelWithMeshIntersect() {
    // Original at 0x005109c0: returns 0
    return 0;
}

LHPoint* DeadTree::GetDefaultFireCentrePos(LHPoint* pos) {
    // Original at 0x00510ce0 — complex
    return pos;
}

float DeadTree::GetDefaultFireRadius() {
    // Original at 0x00510e10 — complex
    return 0.0f;
}

void DeadTree::Draw() {
    // Original at 0x005107f0 — complex rendering
}

float DeadTree::GetWeight() {
    // Original at 0x00511590 — complex
    return 0.0f;
}

void DeadTree::CallVirtualFunctionsForCreation(const MapCoords& coords) {
    // Original at 0x00510a90 — complex
    Rock::CallVirtualFunctionsForCreation(coords);
}

float DeadTree::GetWoodValue() {
    // Original at 0x00511ad0 — complex
    return 0.0f;
}

RESOURCE_TYPE DeadTree::GetResourceType() {
    // Original at 0x005110c0 — complex
    return RESOURCE_TYPE_WOOD;
}

int DeadTree::GetDefaultResource() {
    // Original at 0x00511330 — complex
    return 0;
}

void DeadTree::StartOnFire() {
    // Original at 0x00510e20 — complex
}

void DeadTree::EndOnFire() {
    // Original at 0x00510e60 — complex
}

uint32_t DeadTree::ValidToApplyThisToObject(GInterfaceStatus* /*status*/, Object* /*param2*/) {
    // Original at 0x00510e90 — complex
    return 0;
}

uint32_t DeadTree::ApplyThisToObject(GInterfaceStatus* /*status*/, Object* /*param2*/,
                                      GestureSystemPacketData* /*param3*/) {
    // Original at 0x00510ee0 — complex
    return 0;
}

uint32_t DeadTree::ApplyThisToMapCoord(GInterfaceStatus* /*status*/, const MapCoords* /*param2*/,
                                        GestureSystemPacketData* /*param3*/) {
    // Original at 0x00511050 — complex
    return 0;
}

uint32_t DeadTree::InterfaceValidToTap(GInterfaceStatus* /*status*/) {
    // Original at 0x005109a0 — complex
    return 0;
}

uint32_t DeadTree::InterfaceTap(GInterfaceStatus* /*status*/) {
    // Original at 0x005109b0 — complex
    return 0;
}

uint32_t DeadTree::GetPhysicsConstantsType() {
    // Original at 0x00511100 — complex
    return 0;
}

void DeadTree::SetUpPhysOb(PhysOb* /*param1*/) {
    // Original at 0x00511170 — complex
}

void DeadTree::EndPhysics(PhysicsObject* /*param1*/, bool /*param2*/) {
    // Original at 0x005113f0 — complex
}

bool DeadTree::InteractsWithPhysicsObjects() {
    // Original at 0x005111f0 — complex
    return false;
}

void DeadTree::ReactToPhysicsImpact(PhysicsObject* /*param1*/, bool /*param2*/) {
    // Original at 0x00510ca0 — complex
}

bool DeadTree::CanBecomeAPhysicsObject() {
    // Original at 0x00511a10 — complex
    return false;
}

bool DeadTree::CreatureMustAvoid(Creature* /*param1*/) {
    // Original at 0x00510e30 — complex
    return false;
}

bool DeadTree::IsARootedObject() {
    // Original at 0x00511200 — complex
    return false;
}

SOUND_COLLISION_TYPE DeadTree::GetCollideSoundType() {
    // Original at 0x00511130 — complex
    return SOUND_COLLISION_TYPE_NONE;
}

uint32_t DeadTree::GetCarriedTreeType() {
    // Original at 0x00511a20 — complex
    return 0;
}

size_t DeadTree::SaveObject(LHOSFile* /*param1*/, const MapCoords* /*param2*/) {
    // Original at 0x00511430 — complex
    return 0;
}

IMMERSION_EFFECT_TYPE DeadTree::GetInHandImmersionTexture() {
    // Original at 0x00510970
    return IMMERSION_EFFECT_TYPE_NONE;
}
