// Lion class implementation
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)
// Cross-referenced with bw1-decomp (v1.20)
//
// Simple methods at 0x0041fdxx are packed 16 bytes apart.
// Complex methods at 0x0041c1a0, 0x0041fc70.

#include <black/Lion.h>

// ============================================================================
// Overrides of GameThing virtuals
// ============================================================================

char* Lion::GetDebugText() {
    // Original at 0x0041fd80
    static char text[] = "Lion";
    return text;
}

uint32_t Lion::GetSaveType() {
    // Original at 0x0041ad90
    return 0x89;
}

// ============================================================================
// Overrides of GameThingWithPos virtuals
// ============================================================================

bool32_t Lion::CanBeFrighteningToCreature(Creature* /*creature*/) {
    // Original at 0x0041fc70 — complex
    return 0;
}

// ============================================================================
// Overrides of Object virtuals
// ============================================================================

uint32_t Lion::StandAnimation() {
    // Original at 0x004182e0
    return 0x6a;
}
