// Bonfire class implementation
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)
// Cross-referenced with bw1-decomp (v1.20)
//
// Simple methods at 0x004397xx are packed 16 bytes apart.
// Complex methods at 0x00439840-0x00439a90.

#include <black/Bonfire.h>

// ============================================================================
// Overrides of GameThing virtuals
// ============================================================================

char* Bonfire::GetDebugText() {
    // Original at 0x004397f0
    static char text[] = "Bonfire";
    return text;
}

uint32_t Bonfire::Load(GameOSFile* /*file*/) {
    // Original at 0x00439a00 — complex serialization
    return 0;
}

uint32_t Bonfire::Save(GameOSFile* /*file*/) {
    // Original at 0x00439990 — complex serialization
    return 0;
}

uint32_t Bonfire::GetSaveType() {
    // Original at 0x004397e0
    return 0;
}

// ============================================================================
// Overrides of GameThingWithPos virtuals
// ============================================================================

void Bonfire::PhysicsEditorCreate(int /*param1*/) {
    // Original at 0x004397c0
}

uint32_t Bonfire::GetScriptObjectType() {
    // Original at 0x00439a70 — complex
    return 0;
}

// ============================================================================
// Overrides of Object virtuals
// ============================================================================

void Bonfire::Draw() {
    // Original at 0x00439a90 — complex rendering
}

void Bonfire::CallVirtualFunctionsForCreation(const MapCoords& coords) {
    // Original at 0x00439840 — complex
    Rock::CallVirtualFunctionsForCreation(coords);
}

bool32_t Bonfire::ValidForPlaceInHand(GInterfaceStatus* /*status*/) {
    // Original at 0x00439790
    return 0;
}

uint32_t Bonfire::InterfaceValidToTap(GInterfaceStatus* /*status*/) {
    // Original at 0x00439780
    return 0;
}

bool Bonfire::InteractsWithPhysicsObjects() {
    // Original at 0x004397b0: returns true
    return true;
}

void Bonfire::ReactToPhysicsImpact(PhysicsObject* /*param1*/, bool /*param2*/) {
    // Original at 0x00439a80 — complex
}

bool Bonfire::CanBecomeAPhysicsObject() {
    // Original at 0x004397a0: returns true
    return true;
}

size_t Bonfire::SaveObject(LHOSFile* /*param1*/, const MapCoords* /*param2*/) {
    // Original at 0x004398a0 — complex
    return 0;
}

IMMERSION_EFFECT_TYPE Bonfire::GetInHandImmersionTexture() {
    // Original at 0x004397d0
    return IMMERSION_EFFECT_TYPE_NONE;
}
