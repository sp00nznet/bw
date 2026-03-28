// GBelief class implementation
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)

#include <black/GBelief.h>

// ============================================================================
// Static methods
// ============================================================================

float GBelief::DistanceChangeToBelief(float /*param1*/, float /*param2*/) {
    // Original at 0x00438770 — complex
    return 0.0f;
}

// ============================================================================
// Non-virtual methods
// ============================================================================

float GBelief::GetBeliefInPlayer(unsigned long index) {
    // Original at 0x00437e70 — returns belief value for a player
    if (index >= BELIEF_MAX_PLAYERS) return 0.0f;
    return belief_in_player[index];
}

void GBelief::SetBelief(unsigned long index, float value) {
    // Original at 0x004387d0 — set belief value, clamped to max cap
    if (index >= BELIEF_MAX_PLAYERS) return;
    if (value > belief_in_player_max[index]) {
        value = belief_in_player_max[index];
    }
    if (value < 0.0f) value = 0.0f;
    belief_in_player[index] = value;
}

void GBelief::SetBeliefInPlayerCap(GPlayer* /*player*/, float /*cap*/) {
    // Original at 0x00438a00 — complex
}
