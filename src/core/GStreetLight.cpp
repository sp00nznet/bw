// GStreetLight class implementation
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)
// Cross-referenced with bw1-decomp (v1.20)
//
// Simple methods at 0x005613xx-0x005614xx are packed 16 bytes apart.
// Complex methods at 0x00734exx-0x007351xx.

#include <black/GStreetLight.h>

// ============================================================================
// Overrides of Base virtuals
// ============================================================================

void GStreetLight::ToBeDeleted(int /*param*/) {
    // Original at 0x00734e00 — complex
}

// ============================================================================
// Overrides of GameThing virtuals
// ============================================================================

GPlayer* GStreetLight::GetPlayer() {
    // Original at 0x005613d0
    return nullptr;
}

char* GStreetLight::GetDebugText() {
    // Original at 0x00561410
    static char text[] = "GStreetLight";
    return text;
}

uint32_t GStreetLight::Load(GameOSFile* /*file*/) {
    // Original at 0x00735160 — complex serialization
    return 0;
}

uint32_t GStreetLight::Save(GameOSFile* /*file*/) {
    // Original at 0x00735140 — complex serialization
    return 0;
}

uint32_t GStreetLight::GetSaveType() {
    // Original at 0x00561400
    return 0;
}

void GStreetLight::ResolveLoad() {
    // Original at 0x00735180 — complex
}

// ============================================================================
// Overrides of GameThingWithPos virtuals
// ============================================================================

float GStreetLight::GetDistanceFromObject(const MapCoords& /*target*/) {
    // Original at 0x00735110 — complex
    return 0.0f;
}

bool32_t GStreetLight::IsStreetLight() {
    // Original at 0x005613f0: returns 1
    return 1;
}

const char* GStreetLight::GetText() {
    // Original at 0x005613e0
    static char text[] = "StreetLight";
    return text;
}
