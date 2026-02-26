// HanoiBlock class implementation
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)
// Cross-referenced with bw1-decomp (v1.20)
//
// Simple methods at 0x005617xx-0x005618xx are packed 16 bytes apart.
// Complex methods at 0x006db9xx-0x006de4xx.

#include <black/HanoiBlock.h>

// ============================================================================
// Overrides of GameThing virtuals
// ============================================================================

char* HanoiBlock::GetDebugText() {
    // Original at 0x00561840
    static char text[] = "HanoiBlock";
    return text;
}

uint32_t HanoiBlock::Load(GameOSFile* /*file*/) {
    // Original at 0x006db960 — complex serialization
    return 0;
}

uint32_t HanoiBlock::Save(GameOSFile* /*file*/) {
    // Original at 0x006db9f0 — complex serialization
    return 0;
}

uint32_t HanoiBlock::GetSaveType() {
    // Original at 0x00561830
    return 0;
}

// ============================================================================
// Overrides of GameThingWithPos virtuals
// ============================================================================

bool HanoiBlock::IsCannotBePickedUp() const {
    // Original at 0x006de440 — complex
    return false;
}

// ============================================================================
// Overrides of Object virtuals
// ============================================================================

bool32_t HanoiBlock::InterfaceSetInMagicHand(GInterfaceStatus* /*status*/) {
    // Original at 0x006de3f0 — complex
    return 0;
}

bool HanoiBlock::CanBecomeAPhysicsObject() {
    // Original at 0x00561800: returns false
    return false;
}

size_t HanoiBlock::SaveObject(LHOSFile* /*param1*/, const MapCoords* /*param2*/) {
    // Original at 0x005617f0
    return 0;
}

IMMERSION_EFFECT_TYPE HanoiBlock::GetInHandImmersionTexture() {
    // Original at 0x00561820
    return IMMERSION_EFFECT_TYPE_NONE;
}
