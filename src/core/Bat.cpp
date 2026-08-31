// Bat and SpellBat class implementations
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)

#include <black/Bat.h>

// ============================================================================
// Bat
// ============================================================================

char* Bat::GetDebugText() {
    // Original at 0x0041ef10
    static char text[] = "Bat";
    return text;
}

uint32_t Bat::GetSaveType() {
    // Original at 0x0041a100
    return 0x94;
}

bool32_t Bat::CanBeFrighteningToCreature(Creature* /*creature*/) {
    // Original at 0x0041ef20: returns 1
    return 1;
}

uint32_t Bat::StandAnimation() {
    // Original at 0x0041be40 — complex
    return 0;
}

// ============================================================================
// SpellBat
// ============================================================================

char* SpellBat::GetDebugText() {
    // Original at 0x0041eff0
    static char text[] = "SpellBat";
    return text;
}

uint32_t SpellBat::GetSaveType() {
    // Original at 0x0041efe0
    // SpellBat shares the Bat save type infrastructure
    return 149;
}

bool32_t SpellBat::CanBeFrighteningToCreature(Creature* /*creature*/) {
    // Original at 0x0041f000: returns 1
    return 1;
}

uint32_t SpellBat::StandAnimation() {
    // Original at 0x0041bea0 — complex
    return 0;
}
