// Dove class implementation
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)
// Cross-referenced with bw1-decomp (v1.20)
//
// Simple methods at 0x0041ddxx are packed 16 bytes apart.
// Complex methods at 0x0041bdxx-0x0041f6xx.

#include <black/Dove.h>

// ============================================================================
// Overrides of GameThing virtuals
// ============================================================================

char* Dove::GetDebugText() {
    // Original at 0x0041dd90
    static char text[] = "Dove";
    return text;
}

uint32_t Dove::Load(GameOSFile* /*file*/) {
    // Original at 0x0041f130 — complex serialization
    return 0;
}

uint32_t Dove::Save(GameOSFile* /*file*/) {
    // Original at 0x0041f110 — complex serialization
    return 0;
}

uint32_t Dove::GetSaveType() {
    // Original at 0x0041dd80
    return 0;
}

// ============================================================================
// Overrides of GameThingWithPos virtuals
// ============================================================================

bool32_t Dove::CanBePickedUpByCreature(Creature* /*creature*/) {
    // Original at 0x0041f190 — complex
    return 0;
}

bool32_t Dove::CanBeStompedOnByCreature(Creature* /*creature*/) {
    // Original at 0x0041f150 — complex
    return 0;
}

bool32_t Dove::CanBePoodOn(Creature* /*creature*/) {
    // Original at 0x0041dd70: returns 0
    return 0;
}

float Dove::GetHowMuchCreatureWantsToLookAtMe() {
    // Original at 0x004d1b10 — complex
    return 0.0f;
}

uint32_t Dove::GetScriptObjectType() {
    // Original at 0x0041eaa0 — complex
    return 0;
}

// ============================================================================
// Overrides of Object virtuals
// ============================================================================

void Dove::Draw() {
    // Original at 0x0041f680 — complex rendering
}

void Dove::CallVirtualFunctionsForCreation(const MapCoords& coords) {
    // Original at 0x0041f240 — complex
    Animal::CallVirtualFunctionsForCreation(coords);
}

uint32_t Dove::StandAnimation() {
    // Original at 0x0041bd80 — complex
    return 0;
}
