// GBelief class implementation
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)

#include <black/GBelief.h>
#include <black/Player.h>

// ============================================================================
// Static methods
// ============================================================================

float GBelief::DistanceChangeToBelief(float distance, float max_distance) {
    // Original at 0x00438770: belief change inversely proportional to distance
    // Closer events have more impact on belief
    if (max_distance <= 0.0f) return 0.0f;
    if (distance >= max_distance) return 0.0f;
    return 1.0f - (distance / max_distance);
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

void GBelief::SetBeliefInPlayerCap(GPlayer* player, float cap) {
    // Original at 0x00438a00: sets the maximum belief a town can have in a player
    if (!player) return;
    uint8_t index = player->GetPlayerNumber();
    if (index >= BELIEF_MAX_PLAYERS) return;
    if (cap < 0.0f) cap = 0.0f;
    if (cap > 1.0f) cap = 1.0f;
    belief_in_player_max[index] = cap;
    // Clamp current belief to new cap
    if (belief_in_player[index] > cap) {
        belief_in_player[index] = cap;
    }
}
