// Fragment class implementation
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)
// Cross-referenced with bw1-decomp (v1.20)
//
// Trivial methods at 0x0076e9xx are packed 16 bytes apart.
// Complex methods at 0x0076eaxx-0x0076f8xx.

#include <black/Fragment.h>

// ============================================================================
// Overrides of Base virtuals
// ============================================================================

void Fragment::ToBeDeleted(int /*param*/) {
    // Original at 0x0076ea70 — complex
}

// ============================================================================
// Overrides of GameThing virtuals
// ============================================================================

char* Fragment::GetDebugText() {
    // Original at 0x0076e990
    static char text[] = "Fragment";
    return text;
}

uint32_t Fragment::Load(GameOSFile* /*file*/) {
    // Original at 0x0076f6a0 — complex serialization
    return 0;
}

uint32_t Fragment::Save(GameOSFile* /*file*/) {
    // Original at 0x0076f5d0 — complex serialization
    return 0;
}

uint32_t Fragment::GetSaveType() {
    // Original at 0x0076e980
    return 0;
}

void Fragment::ResolveLoad() {
    // Original at 0x0076f7b0 — complex
}

// ============================================================================
// Overrides of GameThingWithPos virtuals
// ============================================================================

bool32_t Fragment::CanBePickedUpByCreature(Creature* /*creature*/) {
    // Original at 0x0076e930: returns 0
    return 0;
}

bool32_t Fragment::CanBeThrownByPlayer() {
    // Original at 0x0076e960: returns 0
    return 0;
}

uint32_t Fragment::GetScriptObjectType() {
    // Original at 0x0076f7c0 — complex
    return 0;
}

// ============================================================================
// Overrides of Object virtuals
// ============================================================================

void Fragment::Draw() {
    // Original at 0x0076ec00 — complex rendering
}

bool32_t Fragment::ValidForPlaceInHand(GInterfaceStatus* /*status*/) {
    // Original at 0x0076e940: returns 0
    return 0;
}

uint32_t Fragment::InterfaceValidToTap(GInterfaceStatus* /*status*/) {
    // Original at 0x0076e950: returns 0
    return 0;
}

uint32_t Fragment::GetPhysicsConstantsType() {
    // Original at 0x0076ec40 — complex
    return 0;
}

void Fragment::SetUpPhysOb(PhysOb* /*param1*/) {
    // Original at 0x0076ec50 — complex
}

void Fragment::EndPhysics(PhysicsObject* /*param1*/, bool /*param2*/) {
    // Original at 0x0076f3f0 — complex
}

bool Fragment::InteractsWithPhysicsObjects() {
    // Original at 0x0076f3d0 — complex
    return false;
}

void Fragment::ReactToPhysicsImpact(PhysicsObject* /*param1*/, bool /*param2*/) {
    // Original at 0x0076f3e0 — complex
}

bool Fragment::CreatureMustAvoid(Creature* /*param1*/) {
    // Original at 0x0076f7f0 — complex
    return false;
}

SOUND_COLLISION_TYPE Fragment::GetCollideSoundType() {
    // Original at 0x0076f7d0 — complex
    return SOUND_COLLISION_TYPE_NONE;
}

IMMERSION_EFFECT_TYPE Fragment::GetInHandImmersionTexture() {
    // Original at 0x0076e970
    return IMMERSION_EFFECT_TYPE_NONE;
}

bool Fragment::ShouldFootpathsGoRound() {
    // Original at 0x0076f7e0 — complex
    return false;
}
