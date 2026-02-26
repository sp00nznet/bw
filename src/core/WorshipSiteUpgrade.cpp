// WorshipSiteUpgrade class implementation
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)
// Cross-referenced with bw1-decomp (v1.20)
//
// Simple methods at 0x004220xx and 0x00527790.
// Complex methods at 0x0077ecxx-0x0077efxx.

#include <black/WorshipSiteUpgrade.h>

// ============================================================================
// Overrides of Base virtuals
// ============================================================================

void WorshipSiteUpgrade::ToBeDeleted(int /*param*/) {
    // Original at 0x0077eca0 — complex
}

// ============================================================================
// Overrides of GameThing virtuals
// ============================================================================

GPlayer* WorshipSiteUpgrade::GetPlayer() {
    // Original at 0x0077ed80 — complex
    return nullptr;
}

// ============================================================================
// Overrides of GameThingWithPos virtuals
// ============================================================================

WorshipSite* WorshipSiteUpgrade::GetWorshipSite() {
    // Original at 0x0077ec60 — complex
    return nullptr;
}

// ============================================================================
// Overrides of Object virtuals
// ============================================================================

size_t WorshipSiteUpgrade::SaveObject(LHOSFile* /*param1*/, const MapCoords* /*param2*/) {
    // Original at 0x0077ef30 — complex
    return 0;
}

// ============================================================================
// Overrides of MultiMapFixed virtuals
// ============================================================================

bool WorshipSiteUpgrade::IsRepaired() {
    // Original at 0x004220f0
    return true;
}

bool WorshipSiteUpgrade::IsBuilt() {
    // Original at 0x00422110
    return true;
}

bool WorshipSiteUpgrade::IsDrawBuilding() {
    // Original at 0x00527790
    return false;
}

PlannedMultiMapFixed* WorshipSiteUpgrade::ConvertToPlanned() {
    // Original at 0x0077edd0 — complex
    return nullptr;
}
