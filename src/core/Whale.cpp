// Whale class implementation
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)
// Cross-referenced with bw1-decomp (v1.20)
//
// Simple methods at 0x005612xx are packed 16 bytes apart.
// Complex methods at 0x00774cxx-0x007752xx.

#include <black/Whale.h>

// ============================================================================
// Overrides of Base virtuals
// ============================================================================

void Whale::ToBeDeleted(int /*param*/) {
    // Original at 0x00774c00 — complex
}

// ============================================================================
// Overrides of GameThing virtuals
// ============================================================================

char* Whale::GetDebugText() {
    static char text[] = "Whale";
    return text;
}

uint32_t Whale::Load(GameOSFile* /*file*/) {
    // Original at 0x007752c0 — complex serialization
    return 0;
}

uint32_t Whale::Save(GameOSFile* /*file*/) {
    // Original at 0x007752a0 — complex serialization
    return 0;
}

uint32_t Whale::GetSaveType() {
    // Original at 0x005612a0
    return 0;
}

void Whale::ResolveLoad() {
    // Original at 0x007752e0 — complex
}

// ============================================================================
// Overrides of GameThingWithPos virtuals
// ============================================================================

void Whale::PhysicsEditorCreate(int /*param*/) {
    // Original at 0x00561280
}

// ============================================================================
// Overrides of Object virtuals
// ============================================================================

uint32_t Whale::Process() {
    // Original at 0x00775280 — complex
    return 0;
}

void Whale::Draw() {
    // Original at 0x00774e10 — complex rendering
}

void Whale::CallVirtualFunctionsForCreation(const MapCoords& coords) {
    // Original at 0x00774ca0 — complex
    MobileObject::CallVirtualFunctionsForCreation(coords);
}

bool Whale::InteractsWithPhysicsObjects() {
    // Original at 0x00561270: returns false
    return false;
}

bool Whale::CanBecomeAPhysicsObject() {
    // Original at 0x00561290: returns false
    return false;
}
