// GStreetLantern class implementation
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)
// Cross-referenced with bw1-decomp (v1.20)
//
// Simple methods at 0x005614xx are packed 16 bytes apart.
// Complex methods at 0x007348xx-0x00734dxx.

#include <black/GStreetLantern.h>

// ============================================================================
// Overrides of Base virtuals
// ============================================================================

void GStreetLantern::ToBeDeleted(int /*param*/) {
    // Original at 0x00734ab0 — complex
}

// ============================================================================
// Overrides of GameThing virtuals
// ============================================================================

char* GStreetLantern::GetDebugText() {
    // Original at 0x00561460
    static char text[] = "GStreetLantern";
    return text;
}

uint32_t GStreetLantern::Load(GameOSFile* /*file*/) {
    // Original at 0x00734be0 — complex serialization
    return 0;
}

uint32_t GStreetLantern::Save(GameOSFile* /*file*/) {
    // Original at 0x00734c90 — complex serialization
    return 0;
}

uint32_t GStreetLantern::GetSaveType() {
    // Original at 0x00561450
    return 0;
}

// ============================================================================
// Overrides of GameThingWithPos virtuals
// ============================================================================

bool32_t GStreetLantern::IsStreetLantern() {
    // Original at 0x00561440: returns 1
    return 1;
}

uint32_t GStreetLantern::GetScriptObjectType() {
    // Original at 0x00734d40 — complex
    return 0;
}

// ============================================================================
// Overrides of Object virtuals
// ============================================================================

void GStreetLantern::Draw() {
    // Original at 0x00734a70 — complex rendering
}

void GStreetLantern::CallVirtualFunctionsForCreation(const MapCoords& coords) {
    // Original at 0x00734810 — complex
    Object::CallVirtualFunctionsForCreation(coords);
}

bool GStreetLantern::InteractsWithPhysicsObjects() {
    // Original at 0x007349d0 — complex
    return false;
}

bool GStreetLantern::CreatureMustAvoid(Creature* /*param1*/) {
    // Original at 0x00734d50 — complex
    return false;
}

size_t GStreetLantern::SaveObject(LHOSFile* /*param1*/, const MapCoords* /*param2*/) {
    // Original at 0x00734b10 — complex
    return 0;
}
