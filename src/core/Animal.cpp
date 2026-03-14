// Animal class implementation
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)
// Cross-referenced with bw1-decomp (v1.20)
//
// Animals are non-player living entities (cows, sheep, wolves, etc.)
// that roam the landscape. They can be eaten by creatures, sacrificed,
// and interact with the village economy.

#include <black/Animal.h>

// ============================================================================
// Overrides of GameThingWithPos virtuals
// ============================================================================

uint32_t Animal::GetCreatureBeliefType() {
    // Original at 0x00414070
    return 7;
}

uint32_t Animal::GetCreatureMimicType() {
    // Original at 0x004cb7a0: returns 4 if info->field_0x14 == 1, else 3
    int field = *reinterpret_cast<const int*>(
        reinterpret_cast<const char*>(info) + 0x14);
    return 4 - static_cast<uint32_t>(field != 1);
}

float Animal::GetHowMuchCreatureWantsToLookAtMe() {
    // Original at 0x004b5330
    return 0.7f;
}

uint32_t Animal::GetScriptObjectType() {
    // Original at 0x004176a0
    return 6;
}

// ============================================================================
// Overrides of Object virtuals
// ============================================================================

HOLD_TYPE Animal::GetHoldType() {
    // Original at 0x004159d0
    return static_cast<HOLD_TYPE>(7);
}

float Animal::GetHoldLoweringMultiplier() {
    // Original at 0x006e0580
    return 0.65f;
}

uint32_t Animal::GetTastiness() {
    // Original at 0x00414090
    return 2;
}

uint32_t Animal::GetPhysicsConstantsType() {
    // Original at 0x004180b0
    return 8;
}
