// MobileObject class implementation
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)
// Cross-referenced with bw1-decomp (v1.20)
//
// MobileObject is a moveable single-cell object (pots, mushrooms).
// Methods at 0x00425bxx are small (~16 bytes each).

#include <black/MobileObject.h>

// ============================================================================
// Overrides of Base virtuals
// ============================================================================

void MobileObject::ToBeDeleted(int /*param*/) {
    // Original at 0x00606f00 — complex
    // TODO: implement properly
}

// ============================================================================
// Overrides of GameThing virtuals
// ============================================================================

GPlayer* MobileObject::GetPlayer() {
    // Original at 0x00607230 — complex
    // TODO: implement properly
    return nullptr;
}

char* MobileObject::GetDebugText() {
    // Original at 0x00425be0: returns "MobileObject"
    static char text[] = "MobileObject";
    return text;
}

uint32_t MobileObject::Load(GameOSFile* /*file*/) {
    // Original at 0x00607d00 — complex serialization
    // TODO: implement when save system is available
    return 0;
}

uint32_t MobileObject::Save(GameOSFile* /*file*/) {
    // Original at 0x00607c40 — complex serialization
    // TODO: implement when save system is available
    return 0;
}

uint32_t MobileObject::GetSaveType() {
    // Original at 0x0041fed0
    return 0x53;
}

// ============================================================================
// Overrides of GameThingWithPos virtuals
// ============================================================================

void MobileObject::PhysicsEditorCreate(int /*param1*/) {
    // Original at 0x00607ab0 — complex
    // TODO: implement properly
}

uint32_t MobileObject::GetCreatureBeliefType() {
    // Original at 0x005c2890: dispatches on info->subType at offset 0x104
    int sub_type = *reinterpret_cast<const int*>(
        reinterpret_cast<const char*>(info) + 0x104);
    if (sub_type == 4) return 0xe;
    if (sub_type == 5) return 0xd;
    return 0x13;
}

bool32_t MobileObject::CanBePlayedWithByCreature(Creature* /*creature*/) {
    // Original at 0x00425bb0: small method
    // TODO: verify from decompiled code
    return 0;
}

bool32_t MobileObject::CanBeStompedOnByCreature(Creature* /*creature*/) {
    // Original at 0x00425b90: small method
    return 1;
}

bool32_t MobileObject::IsMushroom(Creature* /*creature*/) {
    // Original at 0x004c5fe0: reads info->subType at offset 0x104
    // Returns true if subType is 0x12 or 0x13 (mushroom variants)
    int sub_type = *reinterpret_cast<const int*>(
        reinterpret_cast<const char*>(info) + 0x104);
    return (sub_type == 0x12 || sub_type == 0x13) ? 1 : 0;
}

bool32_t MobileObject::CanBeUsedToHoldWater(Creature* /*creature*/) {
    // Original at 0x0041feb0: reads info->subType at offset 0x104
    // Returns true if subType == 6 (pot that can hold water)
    int sub_type = *reinterpret_cast<const int*>(
        reinterpret_cast<const char*>(info) + 0x104);
    return sub_type == 6 ? 1 : 0;
}

bool32_t MobileObject::CanBeThrownInTheSeaPlayfully(Creature* /*creature*/) {
    // Original at 0x00425ba0: small method
    return 1;
}

uint32_t MobileObject::GetCreatureMimicType() {
    // Original at 0x0041fea0
    return 8;
}

bool32_t MobileObject::IsMobileObject() {
    // Original at 0x00425bc0: returns 1
    return 1;
}

bool32_t MobileObject::IsPoisoned() {
    // Original at 0x006079e0 — complex
    // TODO: implement properly
    return 0;
}

uint32_t MobileObject::GetScriptObjectType() {
    // Original at 0x00607b60 — complex
    // TODO: implement properly
    return 0;
}

// ============================================================================
// Overrides of Object virtuals
// ============================================================================

float MobileObject::GetXAngle() {
    // Original at 0x00425b10: reads from field area
    // TODO: implement properly
    return 0.0f;
}

float MobileObject::GetZAngle() {
    // Original at 0x0041fe90: return *(float*)(this + 0x60)
    // field_0x60 stores z-angle as a float bit pattern in uint32_t
    return *reinterpret_cast<const float*>(&field_0x60);
}

void MobileObject::SetXYZAngles(float /*x*/, float /*y*/, float /*z*/) {
    // Original at 0x00607460 — complex
    // TODO: implement properly
}

void MobileObject::SetXYZAnglesAndScale(float /*x*/, float /*y*/, float /*z*/, float /*scale*/) {
    // Original at 0x006074e0 — complex
    // TODO: implement properly
}

uint32_t MobileObject::MoveAlongPath() {
    // Original at 0x00607790 — complex
    // TODO: implement properly
    return 0;
}

void MobileObject::Create3DObject() {
    // Original at 0x00607210 — complex
    // TODO: implement when rendering system is available
}

void MobileObject::InsertMapObjectToCell(MapCell* /*cell*/) {
    // Original at 0x00607250 — complex
    // TODO: implement properly
}

void MobileObject::RemoveMapObjectFromCell(MapCell* cell) {
    // Original at 0x00505600: delegates to Object base class
    Object::RemoveMapObjectFromCell(cell);
}

HOLD_TYPE MobileObject::GetHoldType() {
    // Original at 0x00607120 — complex
    // TODO: implement properly
    return HOLD_TYPE_DEFAULT;
}

float MobileObject::GetHoldLoweringMultiplier() {
    // Original at 0x005c2600: depends on hold type
    if (GetHoldType() == 6) return 0.7f;
    return -0.3f;
}

int MobileObject::GetMesh() const {
    // Original at 0x00425b40: small method
    // TODO: verify from decompiled code
    return 0;
}

void MobileObject::Draw() {
    // Original at 0x00518150 — complex rendering
    // TODO: implement when rendering system is available
}

bool MobileObject::CanBePickedUp() {
    // Original at 0x00425b30: returns true
    return true;
}

void MobileObject::GetWorldMatrix(LHMatrix* /*out*/) {
    // Original at 0x00607560 — complex (builds matrix from angles)
    // TODO: implement properly
}

void MobileObject::CallVirtualFunctionsForCreation(const MapCoords& coords) {
    // Original at 0x00607150 — complex
    // TODO: implement properly
    Object::CallVirtualFunctionsForCreation(coords);
}

RESOURCE_TYPE MobileObject::GetResourceType() {
    // Original at 0x005c3020: mushroom types (0x11, 0x12, 0x13) are food, others invalid
    int sub_type = *reinterpret_cast<const int*>(
        reinterpret_cast<const char*>(info) + 0x104);
    if (sub_type != 0x11 && sub_type != 0x12 && sub_type != 0x13) {
        return static_cast<RESOURCE_TYPE>(0xFFFFFFFF);  // RESOURCE_TYPE_NONE
    }
    return RESOURCE_TYPE_FOOD;
}

int MobileObject::GetDefaultResource() {
    // Original at 0x00607bf0 — complex
    // TODO: implement properly
    return 0;
}

uint32_t MobileObject::ValidToApplyThisToObject(GInterfaceStatus* /*status*/, Object* /*param2*/) {
    // Original at 0x00607b70 — complex
    // TODO: implement properly
    return 0;
}

uint32_t MobileObject::ApplyThisToObject(GInterfaceStatus* /*status*/, Object* /*param2*/,
                                          GestureSystemPacketData* /*param3*/) {
    // Original at 0x00607bc0 — complex
    // TODO: implement properly
    return 0;
}

uint32_t MobileObject::GetPhysicsConstantsType() {
    // Original at 0x006079f0 — complex
    // TODO: implement properly
    return 0;
}

void MobileObject::ReactToPhysicsImpact(PhysicsObject* /*param1*/, bool /*param2*/) {
    // Original at 0x00607a20 — complex
    // TODO: implement properly
}

bool MobileObject::CanBecomeAPhysicsObject() {
    // Original at 0x00607aa0 — complex
    // TODO: implement properly
    return false;
}

void MobileObject::AddToRoutePlan(RPHolder* /*p1*/, Creature* /*p2*/, int /*p3*/,
                                   void (*/*p4*/)(int, Point2D, float, int)) {
    // Original at 0x00607410 — complex
    // TODO: implement properly
}

uint32_t MobileObject::GetTastiness() {
    // Original at 0x00425b50
    return 2;
}

size_t MobileObject::SaveObject(LHOSFile* /*param1*/, const MapCoords* /*param2*/) {
    // Original at 0x00607270 — complex
    // TODO: implement when save system is available
    return 0;
}
