// HelpSpirit class implementation
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)
// Cross-referenced with bw1-decomp (v1.20)
//
// Simple methods at 0x005c4axx are packed 16 bytes apart.
// Complex methods at 0x005c4bxx-0x005c52xx.

#include <black/HelpSpirit.h>

// ============================================================================
// Overrides of Object virtuals
// ============================================================================

void HelpSpirit::Create3DObject() {
    // Original at 0x005c4b00 — complex
}

uint32_t HelpSpirit::Process() {
    // Original at 0x005c5270 — complex
    return 0;
}

void HelpSpirit::CallVirtualFunctionsForCreation(const MapCoords& coords) {
    // Original at 0x005c4b90 — complex
    Object::CallVirtualFunctionsForCreation(coords);
}

bool32_t HelpSpirit::ValidForPlaceInHand(GInterfaceStatus* /*status*/) {
    // Original at 0x005c4af0: returns 0
    return 0;
}

size_t HelpSpirit::SaveObject(LHOSFile* /*param1*/, const MapCoords* /*param2*/) {
    // Original at 0x005c4ae0: returns 0
    return 0;
}
