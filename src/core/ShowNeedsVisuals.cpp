// ShowNeedsVisuals class implementation
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)
// Cross-referenced with bw1-decomp (v1.20)
//
// Simple methods at 0x0055ddxx are packed 16 bytes apart.
// Complex methods at 0x00719dxx-0x0071a4xx.

#include <black/ShowNeedsVisuals.h>

// ============================================================================
// Overrides of Base virtuals
// ============================================================================

void ShowNeedsVisuals::ToBeDeleted(int /*param*/) {
    // Original at 0x00719dd0 — complex
}

// ============================================================================
// Overrides of GameThing virtuals
// ============================================================================

GPlayer* ShowNeedsVisuals::GetPlayer() {
    // Original at 0x0071a1b0 — complex
    return nullptr;
}

char* ShowNeedsVisuals::GetDebugText() {
    // Original at 0x0055ddc0
    static char text[] = "ShowNeedsVisuals";
    return text;
}

uint32_t ShowNeedsVisuals::Load(GameOSFile* /*file*/) {
    // Original at 0x0071a320 — complex serialization
    return 0;
}

uint32_t ShowNeedsVisuals::Save(GameOSFile* /*file*/) {
    // Original at 0x0071a230 — complex serialization
    return 0;
}

uint32_t ShowNeedsVisuals::GetSaveType() {
    // Original at 0x0055ddb0
    return 0;
}

void ShowNeedsVisuals::ResolveLoad() {
    // Original at 0x0071a410 — complex
}

// ============================================================================
// Overrides of GameThingWithPos virtuals
// ============================================================================

float ShowNeedsVisuals::GetScale() {
    // Original at 0x0055dd80
    return 1.0f;
}

void ShowNeedsVisuals::SetScale(float /*scale*/) {
    // Original at 0x0055dd70
}

const char* ShowNeedsVisuals::GetText() {
    // Original at 0x0055dd90
    static char text[] = "ShowNeedsVisuals";
    return text;
}

// ============================================================================
// Overrides of Object virtuals
// ============================================================================

int ShowNeedsVisuals::GetMesh() const {
    // Original at 0x0055dd60
    return 0;
}

void ShowNeedsVisuals::CallVirtualFunctionsForCreation(const MapCoords& coords) {
    // Original at 0x00719e00 — complex
    Object::CallVirtualFunctionsForCreation(coords);
}

size_t ShowNeedsVisuals::SaveObject(LHOSFile* /*param1*/, const MapCoords* /*param2*/) {
    // Original at 0x0055dda0
    return 0;
}
