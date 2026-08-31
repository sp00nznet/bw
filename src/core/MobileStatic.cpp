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

void MobileStatic::ToBeDeleted(int param) {
    // Original at 0x00608760: cleanup and delegate to base
    MultiMapFixed::ToBeDeleted(param);
}

// ============================================================================
// Overrides of GameThing virtuals
// ============================================================================

GPlayer* MobileStatic::GetPlayer() {
    // Original at 0x006088b0: if attached to a parent object, get its player
    if (field_0x7c) {
        return reinterpret_cast<GameThing*>(field_0x7c)->GetPlayer();
    }
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
    // Needs save system
    return 0;
}

uint32_t MobileStatic::Save(GameOSFile* /*file*/) {
    // Original at 0x00608650 — complex serialization
    // Needs save system
    return 0;
}

uint32_t MobileStatic::GetSaveType() {
    // Original at 0x0055d740
    return 84;
}

// ============================================================================
// Overrides of GameThingWithPos virtuals
// ============================================================================

void MobileStatic::PhysicsEditorCreate(int /*param1*/) {
    // Original at 0x0055d720 — initializes physics editor representation
    // Needs physics editor
}

uint32_t MobileStatic::GetCreatureBeliefType() {
    // Original at 0x00608b10: generic mobile static belief type
    return 0x13;
}

bool32_t MobileStatic::IsCastShadowAtNight() {
    // Original at 0x00439700: returns 1
    return 1;
}

bool32_t MobileStatic::CanBeEatenByCreature(Creature* /*creature*/) {
    // Original at 0x004e48d0: mobile statics are not edible
    return 0;
}

bool32_t MobileStatic::CanBePlayedWithByCreature(Creature* /*creature*/) {
    // Original at 0x00439640: can be played with if it's a toy
    return IsToy(nullptr);
}

bool32_t MobileStatic::CanBePickedUpByCreature(Creature* /*creature*/) {
    // Original at 0x004e4cc0: mobile statics can be picked up by creatures
    return 1;
}

bool32_t MobileStatic::CanBeStompedOnByCreature(Creature* /*creature*/) {
    // Original at 0x00439630: small method
    return 1;
}

bool32_t MobileStatic::IsToyAwayFromHome(Creature* /*creature*/) {
    // Original at 0x004e4c40: checks if toy is far from creature's home
    // Simplified: toys in hand or far from spawn are "away"
    return IsToy(nullptr) ? 1 : 0;
}

bool32_t MobileStatic::IsToy(Creature* /*creature*/) {
    // Original at 0x00609020: reads info->subType at offset 0x104
    // Toy types are 0x15 (ball), 0x16 (die), 0x17 (cuddly)
    int sub_type = *reinterpret_cast<const int*>(
        reinterpret_cast<const char*>(info) + 0x104);
    return (sub_type >= 0x15 && sub_type <= 0x17) ? 1 : 0;
}

bool32_t MobileStatic::IsToyBall(Creature* /*creature*/) {
    // Original at 0x00609050: reads info->subType at offset 0x104
    int sub_type = *reinterpret_cast<const int*>(
        reinterpret_cast<const char*>(info) + 0x104);
    return (sub_type == 0x15) ? 1 : 0;
}

bool32_t MobileStatic::IsToyDie(Creature* /*creature*/) {
    // Original at 0x00609070: reads info->subType at offset 0x104
    int sub_type = *reinterpret_cast<const int*>(
        reinterpret_cast<const char*>(info) + 0x104);
    return (sub_type == 0x16) ? 1 : 0;
}

bool32_t MobileStatic::IsToyCuddly(Creature* /*creature*/) {
    // Original at 0x00609090: reads info->subType at offset 0x104
    int sub_type = *reinterpret_cast<const int*>(
        reinterpret_cast<const char*>(info) + 0x104);
    return (sub_type == 0x17) ? 1 : 0;
}

bool32_t MobileStatic::IsFence() {
    // Original at 0x00609110: reads info->subType at offset 0x104
    int sub_type = *reinterpret_cast<const int*>(
        reinterpret_cast<const char*>(info) + 0x104);
    return (sub_type == 0x1e) ? 1 : 0;
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
    // Original at 0x0055d710: mobile statics don't have mimic type
    return 0;
}

float MobileStatic::GetHowMuchCreatureWantsToLookAtMe() {
    // Original at 0x004d1af0: moderate interest for mobile statics
    return 0.3f;
}

bool32_t MobileStatic::IsMobileStatic() {
    // Original at 0x004396f0: returns 1
    return 1;
}

uint32_t MobileStatic::GetScriptObjectType() {
    // Original at 0x00609330: mobile statics are script object type 4
    return 4;
}

// ============================================================================
// Overrides of Object virtuals
// ============================================================================

float MobileStatic::GetXAngle() {
    // Original at 0x00439610: reads float at offset 0x80
    return x_angle;
}

float MobileStatic::GetZAngle() {
    // Original at 0x00439620: reads float at offset 0x84
    return z_angle;
}

void MobileStatic::SetXYZAngles(float x, float y, float z) {
    // Original at 0x00608ce0: stores x/z angles, sets y via Object::SetAngle
    x_angle = x;
    z_angle = z;
    Object::SetYAngle(y);
}

void MobileStatic::SetXYZAnglesAndScale(float x, float y, float z, float scale) {
    // Original at 0x00608d60: stores angles and scale
    x_angle = x;
    z_angle = z;
    Object::SetYAngle(y);
    Object::SetJustScale(scale);
}

bool MobileStatic::BlocksTownClearArea() const {
    // Original at 0x006096a0: fences block town clear area
    int sub_type = *reinterpret_cast<const int*>(
        reinterpret_cast<const char*>(info) + 0x104);
    return (sub_type == 0x1e);  // fence type blocks
}

HOLD_TYPE MobileStatic::GetHoldType() {
    // Original at 0x006091b0: default hold type 6 for throwable objects
    return static_cast<HOLD_TYPE>(6);
}

float MobileStatic::GetHoldLoweringMultiplier() {
    // Original at 0x00609230: lowering multiplier for large objects
    return 0.7f;
}

int MobileStatic::GetMesh() const {
    // Original at 0x00439680: reads mesh ID from info at offset 0x100
    return *reinterpret_cast<const int*>(
        reinterpret_cast<const char*>(info) + 0x100);
}

void MobileStatic::Draw() {
    // Original at 0x00517f60 — complex rendering
    // Needs rendering pipeline
}

bool MobileStatic::CanBePickedUp() {
    // Original at 0x00439670: returns true
    return true;
}

void MobileStatic::GetWorldMatrix(LHMatrix* /*out*/) {
    // Original at 0x00608de0 — builds world transform matrix from x/y/z angles and scale
}

void MobileStatic::CallVirtualFunctionsForCreation(const MapCoords& coords) {
    // Original at 0x00609700 — sets up physics, 3D object, and map insertion for new entity
    MultiMapFixed::CallVirtualFunctionsForCreation(coords);
}

RESOURCE_TYPE MobileStatic::GetResourceType() {
    // Original at 0x006096b0: reads resource type from info at offset 0x10C
    return *reinterpret_cast<const RESOURCE_TYPE*>(
        reinterpret_cast<const char*>(info) + 0x10C);
}

int MobileStatic::GetDefaultResource() {
    // Original at 0x006096d0: reads default resource from info at offset 0x110
    return *reinterpret_cast<const int*>(
        reinterpret_cast<const char*>(info) + 0x110);
}

bool32_t MobileStatic::ValidForPlaceInHand(GInterfaceStatus* /*status*/) {
    // Original at 0x0055d730: returns 1
    return 1;
}

uint32_t MobileStatic::ValidToApplyThisToObject(GInterfaceStatus* /*status*/, Object* /*param2*/) {
    // Original at 0x00608bb0 — checks if this mobile static can be dropped onto target object
    return 0;
}

uint32_t MobileStatic::ApplyThisToObject(GInterfaceStatus* /*status*/, Object* /*param2*/,
                                          GestureSystemPacketData* /*param3*/) {
    // Original at 0x00608c30 — drops this mobile static onto target object (e.g. rock onto building site)
    return 0;
}

uint32_t MobileStatic::ValidToApplyThisToMapCoord(GInterfaceStatus* /*status*/,
                                                    const MapCoords* /*param2*/) {
    // Original at 0x004396c0: always returns 1 (can be placed on map)
    return 1;
}

uint32_t MobileStatic::ApplyThisToMapCoord(GInterfaceStatus* /*status*/,
                                            const MapCoords* /*param2*/,
                                            GestureSystemPacketData* /*param3*/) {
    // Original at 0x00608b30 — places this mobile static at the given map position
    return 0;
}

uint32_t MobileStatic::ApplyOnlyAfterReleased() {
    // Original at 0x004396b0: returns 1
    return 1;
}

uint32_t MobileStatic::GetPhysicsConstantsType() {
    // Original at 0x00609270: reads physics type from info at offset 0x108
    return *reinterpret_cast<const uint32_t*>(
        reinterpret_cast<const char*>(info) + 0x108);
}

void MobileStatic::GetBoundingSphere(LHPoint* /*center*/, float* /*radius*/) {
    // Original at 0x00608f40 — computes bounding sphere from mesh extents and scale
}

bool MobileStatic::InteractsWithPhysicsObjects() {
    // Original at 0x006090b0: interacts when alive
    return GetLife() > 0.01f;
}

uint32_t MobileStatic::ChecksVerticesVObjects() {
    // Original at 0x00609260: returns 1
    return 1;
}

uint32_t MobileStatic::PhysicallyDestroysAbodes() {
    // Original at 0x00609210: large mobile statics can destroy abodes
    float scale = GetScale();
    return (scale > 2.0f) ? 1 : 0;
}

void MobileStatic::ReactToPhysicsImpact(PhysicsObject* /*param1*/, bool /*param2*/) {
    // Original at 0x00608fc0 — applies damage/knockback from physics collision
    // Needs physics system
}

bool MobileStatic::CanBecomeAPhysicsObject() {
    // Original at 0x00609320: mobile statics can always become physics objects
    return true;
}

bool MobileStatic::CreatureMustAvoid(Creature* /*param1*/) {
    // Original at 0x00609010: creatures avoid fences
    return IsFence() != 0;
}

void MobileStatic::AddToRoutePlan(RPHolder* /*p1*/, Creature* /*p2*/, int /*p3*/,
                                   void (*/*p4*/)(int, Point2D, float, int)) {
    // Original at 0x00608ac0 — adds this object as an obstacle to creature pathfinding route plan
}

bool32_t MobileStatic::IsSolidToNewAbode() {
    // Original at 0x00439690: returns 1
    return 1;
}

uint32_t MobileStatic::GetTastiness() {
    // Original at 0x00439660: mobile statics are not edible
    return 0;
}

size_t MobileStatic::SaveObject(LHOSFile* /*param1*/, const MapCoords* /*param2*/) {
    // Original at 0x006088e0 — complex
    // Needs save system
    return 0;
}
