// CitadelEntrance class implementation
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)
// Cross-referenced with bw1-decomp (v1.20)
//
// Simple methods at 0x00468exx are packed 16 bytes apart.
// Complex methods at 0x00468fxx-0x004693xx.

#include <black/CitadelEntrance.h>

// ============================================================================
// Overrides of GameThing virtuals
// ============================================================================

char* CitadelEntrance::GetDebugText() {
    // Original at 0x00468e70
    static char text[] = "CitadelEntrance";
    return text;
}

uint32_t CitadelEntrance::GetSaveType() {
    // Original at 0x00468e60
    return 0;
}

void CitadelEntrance::ResolveLoad() {
    // Original at 0x00469380 — complex
}

// ============================================================================
// Overrides of GameThingWithPos virtuals
// ============================================================================

HELP_TEXT CitadelEntrance::GetQueryFirstEnumText() {
    // Original at 0x00468f90
    return HELP_TEXT_NONE;
}

HELP_TEXT CitadelEntrance::GetQueryLastEnumText() {
    // Original at 0x00468fa0
    return HELP_TEXT_NONE;
}

// ============================================================================
// Overrides of Object virtuals
// ============================================================================

uint32_t CitadelEntrance::InterfaceValidToTap(GInterfaceStatus* /*status*/) {
    // Original at 0x00468f50 — complex
    return 0;
}

uint32_t CitadelEntrance::InterfaceTap(GInterfaceStatus* /*status*/) {
    // Original at 0x00468ef0 — complex
    return 0;
}

size_t CitadelEntrance::SaveObject(LHOSFile* /*param1*/, const MapCoords* /*param2*/) {
    // Original at 0x00468e50
    return 0;
}
