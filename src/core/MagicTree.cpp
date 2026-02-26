// MagicTree class implementation
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)
// Cross-referenced with bw1-decomp (v1.20)
//
// Simple methods at 0x005fcfxx are packed 16 bytes apart.
// Complex methods at 0x005fd0xx-0x005fd1xx.

#include <black/MagicTree.h>

// ============================================================================
// Overrides of Base virtuals
// ============================================================================

void MagicTree::ToBeDeleted(int /*param*/) {
    // Original at 0x005fd070 — complex
}

// ============================================================================
// Overrides of GameThing virtuals
// ============================================================================

GPlayer* MagicTree::GetPlayer() {
    // Original at 0x005fd060 — complex
    return nullptr;
}

char* MagicTree::GetDebugText() {
    // Original at 0x005fcf20
    static char text[] = "MagicTree";
    return text;
}

uint32_t MagicTree::Load(GameOSFile* /*file*/) {
    // Original at 0x005fd1c0 — complex serialization
    return 0;
}

uint32_t MagicTree::Save(GameOSFile* /*file*/) {
    // Original at 0x005fd110 — complex serialization
    return 0;
}

uint32_t MagicTree::GetSaveType() {
    // Original at 0x005fcf10
    return 0;
}

// ============================================================================
// Overrides of GameThingWithPos virtuals
// ============================================================================

IMPRESSIVE_TYPE MagicTree::GetImpressiveType() {
    // Original at 0x005fcf00
    return IMPRESSIVE_TYPE_NONE;
}

// ============================================================================
// Overrides of Object virtuals
// ============================================================================

void MagicTree::StartOnFire() {
    // Original at 0x005fd0d0 — complex
}

void MagicTree::EndOnFire() {
    // Original at 0x005fd0e0 — complex
}
