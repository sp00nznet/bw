// Ball class implementation
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)
// Cross-referenced with bw1-decomp (v1.20)
//
// Trivial methods at 0x00435axx-0x004363xx are packed 16 bytes apart.
// Complex methods at 0x004359xx-0x004363xx.

#include <black/Ball.h>

// ============================================================================
// Overrides of GameThing virtuals
// ============================================================================

GPlayer* Ball::GetPlayer() {
    // Original at 0x00435f60 — complex
    return nullptr;
}

char* Ball::GetDebugText() {
    // Original at 0x00435ad0
    static char text[] = "Ball";
    return text;
}

uint32_t Ball::Load(GameOSFile* /*file*/) {
    // Original at 0x00436260 — complex serialization
    return 0;
}

uint32_t Ball::Save(GameOSFile* /*file*/) {
    // Original at 0x00436110 — complex serialization
    return 0;
}

uint32_t Ball::GetSaveType() {
    // Original at 0x00435ac0
    return 0;
}

// ============================================================================
// Overrides of GameThingWithPos virtuals
// ============================================================================

bool32_t Ball::CanBePickedUpByCreature(Creature* /*creature*/) {
    // Original at 0x00435ab0 — complex
    return 0;
}

bool32_t Ball::IsToy(Creature* /*creature*/) {
    // Original at 0x004363b0: returns 1
    return 1;
}

bool32_t Ball::IsToyBall(Creature* /*creature*/) {
    // Original at 0x004363c0: returns 1
    return 1;
}

uint32_t Ball::GetScriptObjectType() {
    // Original at 0x00436100 — complex
    return 0;
}

// ============================================================================
// Overrides of Object virtuals
// ============================================================================

uint32_t Ball::Process() {
    // Original at 0x00435c30 — complex
    return 0;
}

void Ball::Draw() {
    // Original at 0x00516870 — complex rendering
}

uint32_t Ball::GetPhysicsConstantsType() {
    // Original at 0x004360f0 — complex
    return 0;
}
