// MobileStatic class implementation
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)
// Cross-referenced with bw1-decomp (v1.20)
//
// MobileStatic is a moveable multi-cell object (rocks, toys, fences).
// Methods at 0x004396xx are small (~16 bytes each).

#include <black/MobileStatic.h>

// ============================================================================
// Overrides of Base virtuals
// ============================================================================

void MobileStatic::ToBeDeleted(int /*param*/) {
    // Original at 0x00608760 — complex
    // TODO: implement properly
}

// ============================================================================
// Overrides of GameThing virtuals
// ============================================================================

GPlayer* MobileStatic::GetPlayer() {
    // Original at 0x006088b0 — complex
    // TODO: implement properly
    return nullptr;
}

bool MobileStatic::IsFunctional() {
    // Original at 0x004396a0: small method
    return true;
}

char* MobileStatic::GetDebugText() {
    // Original at 0x0055d750: returns "MobileStatic"
    static char text[] = "MobileStatic";
    return text;
}

uint32_t MobileStatic::Load(GameOSFile* /*file*/) {
    // Original at 0x00608590 — complex serialization
    // TODO: implement when save system is available
    return 0;
}

uint32_t MobileStatic::Save(GameOSFile* /*file*/) {
    // Original at 0x00608650 — complex serialization
    // TODO: implement when save system is available
    return 0;
}

uint32_t MobileStatic::GetSaveType() {
    // Original at 0x0055d740
    // TODO: verify return value from Ghidra
    return 0;
}

// ============================================================================
// Overrides of GameThingWithPos virtuals
// ============================================================================

void MobileStatic::PhysicsEditorCreate(int /*param1*/) {
    // Original at 0x0055d720 — complex
    // TODO: implement properly
}

uint32_t MobileStatic::GetCreatureBeliefType() {
    // Original at 0x00608b10 — complex
    // TODO: implement properly
    return 0;
}

bool32_t MobileStatic::IsCastShadowAtNight() {
    // Original at 0x00439700: returns 1
    return 1;
}

bool32_t MobileStatic::CanBeEatenByCreature(Creature* /*creature*/) {
    // Original at 0x004e48d0 — complex
    // TODO: implement properly
    return 0;
}

bool32_t MobileStatic::CanBePlayedWithByCreature(Creature* /*creature*/) {
    // Original at 0x00439640: small method
    // TODO: verify from decompiled code
    return 0;
}

bool32_t MobileStatic::CanBePickedUpByCreature(Creature* /*creature*/) {
    // Original at 0x004e4cc0 — complex
    // TODO: implement properly
    return 0;
}

bool32_t MobileStatic::CanBeStompedOnByCreature(Creature* /*creature*/) {
    // Original at 0x00439630: small method
    return 1;
}

bool32_t MobileStatic::IsToyAwayFromHome(Creature* /*creature*/) {
    // Original at 0x004e4c40 — complex
    // TODO: implement properly
    return 0;
}

bool32_t MobileStatic::IsToy(Creature* /*creature*/) {
    // Original at 0x00609020 — complex
    // TODO: implement properly
    return 0;
}

bool32_t MobileStatic::IsToyBall(Creature* /*creature*/) {
    // Original at 0x00609050 — complex
    // TODO: implement properly
    return 0;
}

bool32_t MobileStatic::IsToyDie(Creature* /*creature*/) {
    // Original at 0x00609070 — complex
    // TODO: implement properly
    return 0;
}

bool32_t MobileStatic::IsToyCuddly(Creature* /*creature*/) {
    // Original at 0x00609090 — complex
    // TODO: implement properly
    return 0;
}

bool32_t MobileStatic::IsFence() {
    // Original at 0x00609110 — complex
    // TODO: implement properly
    return 0;
}

bool32_t MobileStatic::CanBeUsedForThrowingDamageByCreature(Creature* /*creature*/) {
    // Original at 0x004396d0: small method
    return 1;
}

bool32_t MobileStatic::CanBeThrownInTheSeaPlayfully(Creature* /*creature*/) {
    // Original at 0x00439650: small method
    return 1;
}

uint32_t MobileStatic::GetCreatureMimicType() {
    // Original at 0x0055d710
    // TODO: verify return value
    return 0;
}

float MobileStatic::GetHowMuchCreatureWantsToLookAtMe() {
    // Original at 0x004d1af0 — complex
    // TODO: implement properly
    return 0.0f;
}

bool32_t MobileStatic::IsMobileStatic() {
    // Original at 0x004396f0: returns 1
    return 1;
}

uint32_t MobileStatic::GetScriptObjectType() {
    // Original at 0x00609330 — complex
    // TODO: implement properly
    return 0;
}

// ============================================================================
// Overrides of Object virtuals
// ============================================================================

float MobileStatic::GetXAngle() {
    // Original at 0x00439610: reads from field_0x80 area
    // TODO: implement properly
    return 0.0f;
}

float MobileStatic::GetZAngle() {
    // Original at 0x00439620: reads from field_0x80 area
    // TODO: implement properly
    return 0.0f;
}

void MobileStatic::SetXYZAngles(float /*x*/, float /*y*/, float /*z*/) {
    // Original at 0x00608ce0 — complex
    // TODO: implement properly
}

void MobileStatic::SetXYZAnglesAndScale(float /*x*/, float /*y*/, float /*z*/, float /*scale*/) {
    // Original at 0x00608d60 — complex
    // TODO: implement properly
}

bool MobileStatic::BlocksTownClearArea() const {
    // Original at 0x006096a0 — complex
    // TODO: implement properly
    return false;
}

HOLD_TYPE MobileStatic::GetHoldType() {
    // Original at 0x006091b0 — complex
    // TODO: implement properly
    return HOLD_TYPE_DEFAULT;
}

float MobileStatic::GetHoldLoweringMultiplier() {
    // Original at 0x00609230 — complex
    // TODO: implement properly
    return 1.0f;
}

int MobileStatic::GetMesh() const {
    // Original at 0x00439680: small method
    // TODO: verify from decompiled code
    return 0;
}

void MobileStatic::Draw() {
    // Original at 0x00517f60 — complex rendering
    // TODO: implement when rendering system is available
}

bool MobileStatic::CanBePickedUp() {
    // Original at 0x00439670: returns true
    return true;
}

void MobileStatic::GetWorldMatrix(LHMatrix* /*out*/) {
    // Original at 0x00608de0 — complex (builds matrix from angles)
    // TODO: implement properly
}

void MobileStatic::CallVirtualFunctionsForCreation(const MapCoords& coords) {
    // Original at 0x00609700 — complex
    // TODO: implement properly
    MultiMapFixed::CallVirtualFunctionsForCreation(coords);
}

RESOURCE_TYPE MobileStatic::GetResourceType() {
    // Original at 0x006096b0 — complex
    // TODO: implement properly
    return RESOURCE_TYPE_FOOD;
}

int MobileStatic::GetDefaultResource() {
    // Original at 0x006096d0 — complex
    // TODO: implement properly
    return 0;
}

bool32_t MobileStatic::ValidForPlaceInHand(GInterfaceStatus* /*status*/) {
    // Original at 0x0055d730: returns 1
    return 1;
}

uint32_t MobileStatic::ValidToApplyThisToObject(GInterfaceStatus* /*status*/, Object* /*param2*/) {
    // Original at 0x00608bb0 — complex
    // TODO: implement properly
    return 0;
}

uint32_t MobileStatic::ApplyThisToObject(GInterfaceStatus* /*status*/, Object* /*param2*/,
                                          GestureSystemPacketData* /*param3*/) {
    // Original at 0x00608c30 — complex
    // TODO: implement properly
    return 0;
}

uint32_t MobileStatic::ValidToApplyThisToMapCoord(GInterfaceStatus* /*status*/,
                                                    const MapCoords* /*param2*/) {
    // Original at 0x004396c0: small method
    // TODO: verify from decompiled code
    return 0;
}

uint32_t MobileStatic::ApplyThisToMapCoord(GInterfaceStatus* /*status*/,
                                            const MapCoords* /*param2*/,
                                            GestureSystemPacketData* /*param3*/) {
    // Original at 0x00608b30 — complex
    // TODO: implement properly
    return 0;
}

uint32_t MobileStatic::ApplyOnlyAfterReleased() {
    // Original at 0x004396b0: returns 1
    return 1;
}

uint32_t MobileStatic::GetPhysicsConstantsType() {
    // Original at 0x00609270 — complex
    // TODO: implement properly
    return 0;
}

void MobileStatic::GetBoundingSphere(LHPoint* /*center*/, float* /*radius*/) {
    // Original at 0x00608f40 — complex
    // TODO: implement properly
}

bool MobileStatic::InteractsWithPhysicsObjects() {
    // Original at 0x006090b0 — complex
    // TODO: implement properly
    return false;
}

uint32_t MobileStatic::ChecksVerticesVObjects() {
    // Original at 0x00609260: returns 1
    return 1;
}

uint32_t MobileStatic::PhysicallyDestroysAbodes() {
    // Original at 0x00609210 — complex
    // TODO: implement properly
    return 0;
}

void MobileStatic::ReactToPhysicsImpact(PhysicsObject* /*param1*/, bool /*param2*/) {
    // Original at 0x00608fc0 — complex
    // TODO: implement properly
}

bool MobileStatic::CanBecomeAPhysicsObject() {
    // Original at 0x00609320 — complex
    // TODO: implement properly
    return false;
}

bool MobileStatic::CreatureMustAvoid(Creature* /*param1*/) {
    // Original at 0x00609010 — complex
    // TODO: implement properly
    return false;
}

void MobileStatic::AddToRoutePlan(RPHolder* /*p1*/, Creature* /*p2*/, int /*p3*/,
                                   void (*/*p4*/)(int, Point2D, float, int)) {
    // Original at 0x00608ac0 — complex
    // TODO: implement properly
}

bool32_t MobileStatic::IsSolidToNewAbode() {
    // Original at 0x00439690: returns 1
    return 1;
}

uint32_t MobileStatic::GetTastiness() {
    // Original at 0x00439660: small method
    // TODO: verify return value
    return 0;
}

size_t MobileStatic::SaveObject(LHOSFile* /*param1*/, const MapCoords* /*param2*/) {
    // Original at 0x006088e0 — complex
    // TODO: implement when save system is available
    return 0;
}
