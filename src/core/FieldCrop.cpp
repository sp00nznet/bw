// FieldCrop class implementation
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)
// Cross-referenced with bw1-decomp (v1.20)
//
// Simple methods at 0x0055d0xx are packed 16 bytes apart.
// Complex methods at 0x00607dxx-0x006084xx.

#include <black/FieldCrop.h>

// ============================================================================
// Overrides of Base virtuals
// ============================================================================

void FieldCrop::ToBeDeleted(int /*param*/) {
    // Original at 0x00607e20 — complex
}

// ============================================================================
// Overrides of GameThing virtuals
// ============================================================================

bool FieldCrop::IsFunctional() {
    // Original at 0x00608270 — complex
    return false;
}

char* FieldCrop::GetDebugText() {
    static char text[] = "FieldCrop";
    return text;
}

uint32_t FieldCrop::GetSaveType() {
    // Original at 0x0055d0f0
    return 0;
}

// ============================================================================
// Overrides of GameThingWithPos virtuals
// ============================================================================

void FieldCrop::PhysicsEditorCreate(int /*param*/) {
    // Original at 0x0055d0e0
}

// ============================================================================
// Overrides of Object virtuals
// ============================================================================

void FieldCrop::InsertMapObject() {
    // Original at 0x00608260 — complex
}

void FieldCrop::RemoveMapObject() {
    // Original at 0x00608250 — complex
}

HOLD_TYPE FieldCrop::GetHoldType() {
    // Original at 0x00607dc0 — complex
    return HOLD_TYPE_DEFAULT;
}

void FieldCrop::SetLife(float /*life*/) {
    // Original at 0x006081e0 — complex
}

uint32_t FieldCrop::InterfaceSetInMagicHand(GInterfaceStatus* /*status*/) {
    // Original at 0x006083e0 — complex
    return 0;
}

uint32_t FieldCrop::ValidToApplyThisToObject(GInterfaceStatus* /*status*/, Object* /*target*/) {
    // Original at 0x00608360 — complex
    return 0;
}

uint32_t FieldCrop::ApplyThisToObject(GInterfaceStatus* /*status*/, Object* /*target*/,
                                       GestureSystemPacketData* /*data*/) {
    // Original at 0x00608390 — complex
    return 0;
}

uint32_t FieldCrop::ApplyThisToMapCoord(GInterfaceStatus* /*status*/, const MapCoords* /*coords*/,
                                         GestureSystemPacketData* /*data*/) {
    // Original at 0x006082b0 — complex
    return 0;
}

uint32_t FieldCrop::GetPhysicsConstantsType() {
    // Original at 0x006082e0
    return 0;
}

void FieldCrop::SetUpPhysOb(PhysOb* /*physOb*/) {
    // Original at 0x006082f0 — complex
}

bool FieldCrop::InteractsWithPhysicsObjects() {
    // Original at 0x00608340: returns false
    return false;
}

bool FieldCrop::CanBecomeAPhysicsObject() {
    // Original at 0x006082d0: returns false
    return false;
}

bool FieldCrop::CreatureMustAvoid(Creature* /*creature*/) {
    // Original at 0x00608440 — complex
    return false;
}

bool FieldCrop::IsARootedObject() {
    // Original at 0x00608350: returns true
    return true;
}
