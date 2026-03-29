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

void MobileWallHug::SetTowardsAngle(uint16_t angle) {
    // Sets the game angle toward a target direction
    // Original at 0x005c86b0
    game_angle = angle;
}

void MobileWallHug::MoveTo3D() {
    // Height interpolation: moves altitude towards goal altitude by ±0.2 per tick
    // Original at 0x005c5b60
    if (coords.altitude > goal.altitude) {
        coords.altitude -= 0.2f;
        if (coords.altitude < goal.altitude) coords.altitude = goal.altitude;
    } else if (coords.altitude < goal.altitude) {
        coords.altitude += 0.2f;
        if (coords.altitude > goal.altitude) coords.altitude = goal.altitude;
    }

    // Horizontal movement: apply step vector to position
    // Original at 0x005c5ba0
    coords.x = static_cast<int32_t>(static_cast<float>(coords.x) + step.x);
    coords.z = static_cast<int32_t>(static_cast<float>(coords.z) + step.z);
}

void MobileWallHug::SetNewWander(const MapCoords& target, int /*param2*/, int /*param3*/) {
    // Set a wander destination
    goal = target;
    move_state = MOVE_TO_STATES_LINEAR;
}

// ============================================================================
// Non-virtual movement methods
// ============================================================================

void MobileWallHug::MoveToGoal() {
    // Core movement loop — compute step vector and advance toward goal
    // This is a simplified version of the original wall-hugging pathfinder.

    if (move_state == MOVE_TO_STATES_ARRIVED) return;

    // Check if we've arrived
    if (AreWeThere(goal, 0.0f)) {
        move_state = MOVE_TO_STATES_ARRIVED;
        step.x = 0.0f;
        step.z = 0.0f;
        return;
    }

    // Compute direction to goal
    float dx = static_cast<float>(goal.x - coords.x);
    float dz = static_cast<float>(goal.z - coords.z);
    float dist = sqrtf(dx * dx + dz * dz);

    if (dist < 0.001f) {
        move_state = MOVE_TO_STATES_ARRIVED;
        return;
    }

    // Normalize and scale by speed
    float spd = static_cast<float>(speed);
    if (spd > dist) spd = dist;  // Don't overshoot

    step.x = (dx / dist) * spd;
    step.z = (dz / dist) * spd;
    step.altitude = 0.0f;

    // Compute facing angle (game angle units: 0-65535 = 0-2PI)
    float angle = atan2f(dx, dz);
    game_angle = static_cast<uint16_t>(angle * (32768.0f / 3.14159265f));

    // Apply movement
    MoveTo3D();

    // Update obj_coords for map tracking
    obj_coords = coords;
}

void MobileWallHug::SetGoalPos(const MapCoords& target) {
    goal = target;
    move_state = MOVE_TO_STATES_LINEAR;
}
