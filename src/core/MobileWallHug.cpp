// MobileWallHug class implementation
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)
// Cross-referenced with bw1-decomp (v1.20)
//
// MobileWallHug adds wall-hugging pathfinding to Mobile. Its movement system
// uses a state machine (MOVE_TO_STATES) to navigate around obstacles.

#include <black/MobileWallHug.h>

// ============================================================================
// New virtual methods (vtable 0x85C-0x870)
// ============================================================================

bool MobileWallHug::AreWeThere() {
    // Compares current position with goal, using speed as threshold
    // Original checks: abs(coords.x - goal.x) < speed && abs(coords.z - goal.z) < speed
    return false;
}

MapCoords* MobileWallHug::GetDestPos() {
    // Returns pointer to goal field at offset 0x80
    return &goal;
}

void MobileWallHug::SetSpeed(float /*speed*/) {}

void MobileWallHug::SetTowardsAngle() {}

void MobileWallHug::MoveTo3D() {}

void MobileWallHug::SetNewWander() {}
