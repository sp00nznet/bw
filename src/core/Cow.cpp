// Cow class implementation
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)
// Cross-referenced with bw1-decomp (v1.20)
//
// Simple methods at 0x0041d0xx are packed 16 bytes apart.

#include <black/Cow.h>

// ============================================================================
// Overrides of GameThing virtuals
// ============================================================================

char* Cow::GetDebugText() {
    // Original at 0x0041d100
    static char text[] = "Cow";
    return text;
}

uint32_t Cow::GetSaveType() {
    // Original at 0x0041d0f0
    return 0;
}

// ============================================================================
// Overrides of GameThingWithPos virtuals
// ============================================================================

bool32_t Cow::IsCow(Creature* /*creature*/) {
    // Original at 0x0041d110: returns 1
    return 1;
}

// ============================================================================
// Overrides of Living virtuals
// ============================================================================

bool Cow::DecideWhatToDo() {
    // Original at 0x0041d1b0 — complex AI decision
    return false;
}
