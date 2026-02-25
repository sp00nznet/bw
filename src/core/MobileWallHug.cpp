// MobileWallHug class implementation
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)
// Cross-referenced with bw1-decomp (v1.20)
//
// MobileWallHug adds wall-hugging pathfinding to Mobile. Its movement system
// uses a state machine (MOVE_TO_STATES) to navigate around obstacles.

#include <black/MobileWallHug.h>
#include <cmath>

// ============================================================================
// New virtual methods (vtable 0x85C-0x870)
// ============================================================================

bool MobileWallHug::AreWeThere(const MapCoords& target, float tolerance) {
    // Distance check: squared distance < (speed + tolerance)^2
    // Original at 0x005c5a20
    float dx = static_cast<float>(coords.x - target.x);
    float dz = static_cast<float>(coords.z - target.z);
    float threshold = static_cast<float>(speed) + tolerance;
    return (dx * dx + dz * dz) < (threshold * threshold);
}

MapCoords* MobileWallHug::GetDestPos() {
    // Returns pointer to goal field at offset 0x80
    return &goal;
}

void MobileWallHug::SetSpeed(int spd) {
    // Clamps speed to [0, 0xFFFF] range (uint16_t)
    // Original at 0x0060fc50
    if (spd < 0) {
        speed = 0;
    } else if (spd > 0xFFFF) {
        speed = 0xFFFF;
    } else {
        speed = static_cast<uint16_t>(spd);
    }
}

void MobileWallHug::SetTowardsAngle(uint16_t /*angle*/) {
    // Calls FUN_005c86b0 (angle interpolation function)
    // TODO: implement when angle interpolation is resolved
}

void MobileWallHug::MoveTo3D() {
    // Height interpolation: moves altitude towards goal altitude by ±0.2 per tick
    // Original at 0x005c5b60
    // offset 0x1C = coords.altitude, offset 0x88 = goal.altitude (0x80 + 0x08)
    if (coords.altitude > goal.altitude) {
        coords.altitude -= 0.2f;
    } else if (coords.altitude < goal.altitude) {
        coords.altitude += 0.2f;
    }
    // Then calls FUN_005c5ba0 (horizontal movement step)
    // TODO: implement horizontal movement
}

void MobileWallHug::SetNewWander(const MapCoords& /*target*/, int /*param2*/, int /*param3*/) {
    // Complex wander direction calculation with angle randomization
    // TODO: implement when sine/cosine lookup tables are resolved
}
