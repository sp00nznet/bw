// Zoomer / Zoomer3d — smooth interpolation primitives
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)
// Cross-referenced with bw1-decomp (lionhead/lh3dlib/development/Zoomer.h)
//
// Zoomer provides smooth cubic Hermite interpolation between a start
// and destination value over a duration. Used for camera movement,
// FOV transitions, and other smooth parameter changes.

#include <black/Zoomer.h>
#include <cmath>

// 0x00441ac0 — snaps zoomer to a specific position immediately
void Zoomer::SetPosition(float position) {
    current_value = position;
    destination = position;
    current_speed = 0.0f;
    destination_speed = 0.0f;
    current_time = 0.0f;
    duration = 0.0f;
    start_value = position;
    start_speed = 0.0f;
}

// Inlined — sets destination without interpolation params
void Zoomer::SetDestination(float dest) {
    destination = dest;
}

// Inlined — returns current interpolated value
float Zoomer::GetCurrentValue() const {
    return current_value;
}

// Inlined — returns target destination
float Zoomer::GetDestination() const {
    return destination;
}

// 0x00407d60 — sets destination with arrival speed and duration
void Zoomer::SetDestinationWithSpeedAndTime(float dest, float speed, float time) {
    destination = dest;
    destination_speed = speed;
    duration = time;
    current_time = 0.0f;
    start_value = current_value;
    start_speed = current_speed;

    // Pre-compute non-linear acceleration coefficients for cubic Hermite interpolation
    // These allow smooth ease-in/ease-out between start and destination
    if (duration > 0.0f) {
        float inv_t = 1.0f / duration;
        float inv_t2 = inv_t * inv_t;
        float delta = destination - start_value;
        // Hermite basis coefficients
        non_linear_acceleration.x = start_value;
        non_linear_acceleration.y = start_speed;
        non_linear_acceleration.z = (3.0f * delta - (2.0f * start_speed + destination_speed) * duration) * inv_t2;
    }
}

// 0x00442720 — advances the zoomer by dt seconds
void Zoomer::Update(float dt) {
    if (duration <= 0.0f) {
        // No interpolation — snap to destination
        current_value = destination;
        current_speed = 0.0f;
        return;
    }

    current_time += dt;

    if (current_time >= duration) {
        // Arrived at destination
        current_value = destination;
        current_speed = destination_speed;
        duration = 0.0f;
        current_time = 0.0f;
        return;
    }

    // Cubic Hermite interpolation
    float t = current_time;
    float t2 = t * t;
    float t3 = t2 * t;
    float inv_dur = 1.0f / duration;
    float inv_dur2 = inv_dur * inv_dur;
    float inv_dur3 = inv_dur2 * inv_dur;

    float delta = destination - start_value;
    float a = 2.0f * delta * inv_dur3 - (start_speed + destination_speed) * inv_dur2;
    float b = -3.0f * delta * inv_dur2 + (2.0f * start_speed + destination_speed) * inv_dur;

    current_value = start_value + start_speed * t + b * t2 + a * t3;
    current_speed = start_speed + 2.0f * b * t + 3.0f * a * t2;
}

// === Zoomer3d methods ===

// Inlined — returns current 3D position
LHPoint Zoomer3d::GetCurrentValue() const {
    LHPoint out;
    out.x = x.GetCurrentValue();
    out.y = y.GetCurrentValue();
    out.z = z.GetCurrentValue();
    return out;
}

// Inlined — returns destination 3D position
LHPoint Zoomer3d::GetDestination() const {
    LHPoint out;
    out.x = x.GetDestination();
    out.y = y.GetDestination();
    out.z = z.GetDestination();
    return out;
}

// Inlined — snaps all axes to position
void Zoomer3d::SetPosition(const LHPoint& pos) {
    x.SetPosition(pos.x);
    y.SetPosition(pos.y);
    z.SetPosition(pos.z);
}

// Inlined — sets destination with speed and time on all axes
void Zoomer3d::SetDestinationWithSpeedAndTime(const LHPoint& dest, float speed, float time) {
    x.SetDestinationWithSpeedAndTime(dest.x, speed, time);
    y.SetDestinationWithSpeedAndTime(dest.y, speed, time);
    z.SetDestinationWithSpeedAndTime(dest.z, speed, time);
}

// 0x0044e760 — sets destination with time on all axes (zero arrival speed)
void Zoomer3d::SetDestinationWithTime(const LHPoint& dest, float time) {
    x.SetDestinationWithSpeedAndTime(dest.x, 0.0f, time);
    y.SetDestinationWithSpeedAndTime(dest.y, 0.0f, time);
    z.SetDestinationWithSpeedAndTime(dest.z, 0.0f, time);
}

// Inlined — advances all three axes
void Zoomer3d::Update(float dt) {
    x.Update(dt);
    y.Update(dt);
    z.Update(dt);
}
