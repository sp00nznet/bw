// Furniture class implementation
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)
// Cross-referenced with bw1-decomp (v1.20)
//
// All methods at 0x0054a4xx are trivial (packed 16 bytes apart).

#include <black/Furniture.h>

// ============================================================================
// Overrides of GameThing virtuals
// ============================================================================

char* Furniture::GetDebugText() {
    // Original at 0x0054a460
    static char text[] = "Furniture";
    return text;
}

uint32_t Furniture::GetSaveType() {
    // Original at 0x0054a450
    return 0;
}

// ============================================================================
// Overrides of Object virtuals
// ============================================================================

size_t Furniture::SaveObject(LHOSFile* /*param1*/, const MapCoords* /*param2*/) {
    // Original at 0x0054a440
    return 0;
}
