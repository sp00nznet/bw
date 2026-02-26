// PFootball class implementation
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)
// Cross-referenced with bw1-decomp (v1.20)
//
// Simple methods at 0x006438xx-0x006439xx are packed 16 bytes apart.
// Complex methods at 0x00643fxx-0x006442xx.

#include <black/PFootball.h>

// ============================================================================
// Overrides of GameThing virtuals
// ============================================================================

GPlayer* PFootball::GetPlayer() {
    // Original at 0x006438e0 — complex
    return nullptr;
}

// ============================================================================
// Overrides of Object virtuals
// ============================================================================

int PFootball::GetMesh() const {
    // Original at 0x00643940
    return 0;
}

void PFootball::Draw() {
    // Original at 0x00643fd0 — complex rendering
}

void PFootball::CallVirtualFunctionsForCreation(const MapCoords& coords) {
    // Original at 0x00644030 — complex
    MultiMapFixed::CallVirtualFunctionsForCreation(coords);
}

size_t PFootball::SaveObject(LHOSFile* /*param1*/, const MapCoords* /*param2*/) {
    // Original at 0x00643980
    return 0;
}

// ============================================================================
// Overrides of MultiMapFixed virtuals
// ============================================================================

bool PFootball::IsPlaytimeStructure() {
    // Original at 0x00643950: returns true
    return true;
}

bool PFootball::IsPlaytimeStarted() {
    // Original at 0x00643960 — complex
    return false;
}

bool PFootball::AddPlaytimeVillager(Villager* /*villager*/) {
    // Original at 0x00644200 — complex
    return false;
}

bool PFootball::IsRepaired() {
    // Original at 0x006438f0: returns true
    return true;
}

bool PFootball::IsBuilt() {
    // Original at 0x00643910: returns true
    return true;
}
