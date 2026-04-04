// GCamera — main game camera
// Method stubs from bw1-decomp
#include "../include/black/GCamera.h"
#include <cmath>

// === Overrides of Base virtuals ===

// 0x00441b30
GCamera::~GCamera() {}
// 0x00441ee0
void GCamera::ToBeDeleted(int /*param*/) {}

// === Overrides of GameThing virtuals ===

// 0x00443840
char* GCamera::GetDebugText() { return "GCamera"; }
// 0x004433a0
uint32_t GCamera::Load(GameOSFile* /*file*/) { return 0; }
// 0x004430e0
uint32_t GCamera::Save(GameOSFile* /*file*/) { return 0; }
// 0x00441b20
uint32_t GCamera::GetSaveType() { return 0x77; }

// === Overrides of GameThingWithPos virtuals ===

// 0x00439a20: returns camera_dirty field at 0x74
bool GCamera::IsMoving() const { return camera_dirty != 0; }
// 0x00439a10: returns "Camera"
const char* GCamera::GetText() { return "Camera"; }
// 0x00439a30: returns coords.altitude at offset 0x1c
float GCamera::GetHeight() { return coords.altitude; }

// === Non-virtual methods ===

// 0x00441b70
bool GCamera::CantExitCurrentMode() { return false; }
// 0x00441cd0
void GCamera::SwitchToViewMode(CameraMode* mode) {
    // Push new mode onto the camera mode stack
    if (mode_current_index < 11) {
        mode_current_index++;
        modes[mode_current_index] = mode;
    }
}
// 0x00441d40 — checks all stacked camera modes and removes invalid ones
void GCamera::CheckStackedModesForValidity() {
    // Iterate from bottom of mode stack to current index
    int i = 0;
    bool found_invalid = false;
    while (i <= mode_current_index) {
        CameraMode* mode = modes[i];
        if (!mode) { i++; continue; }

        // Check if mode is valid through its vtable (offset 0x14 = IsValid)
        // For now, assume all modes are valid — proper vtable dispatch comes later
        // Needs CameraMode::IsValid() vtable dispatch
        i++;
    }
}

// 0x00441f50 — validates camera state, snaps to ground if needed
void GCamera::Validate() {
    // Camera bounds checking: map limits, terrain height, heading/origin ranges
    // - Ensure camera is within map bounds
    // - Ensure camera height is above terrain
    // - Snap heading/origin to valid ranges
    camera_dirty = 0;
}

// 0x00441f80 — main camera update tick
void GCamera::Update() {
    // Update current camera mode
    if (mode_current_index >= 0 && mode_current_index < 12) {
        CameraMode* mode = modes[mode_current_index];
        if (mode) {
            // Needs CameraMode::Update() vtable dispatch
            // This drives the camera position/focus each frame
        }
    }

    // Interpolate heading zoomer
    // camera_heading_zoomer.Update(time_delta)

    // Interpolate origin zoomer
    // camera_origin_zoomer.Update(time_delta)

    // Interpolate FOV zoomer
    // fov_zoomer.Update(time_delta)

    // Sync GameThingWithPos position from camera state
    UpdateGameThingWithPosData();

    camera_dirty = 1;
}

// 0x00442ef0 — syncs GameThingWithPos coords from camera position
void GCamera::UpdateGameThingWithPosData() {
    // Copy camera position into the GameThingWithPos coordinate fields
    coords.x = static_cast<int32_t>(pos.x);
    coords.z = static_cast<int32_t>(pos.z);
    coords.altitude = pos.y;
}

// 0x00443680 — sets camera FOV with interpolation time
void GCamera::SetCameraFov(float fov, float /*time*/) {
    // Set up fov_zoomer to interpolate to target FOV over time
    // For now, snap immediately
    fov_zoomer.current_value = fov;
    fov_zoomer.destination = fov;
}

// === Static methods ===

// 0x00441f20
float GCamera::GetThingViewingDistance(GameThingWithPos* /*target*/) { return 0.0f; }

// 0x00442810 — compute a point at (distance, heading, pitch) from a source point
void GCamera::SetPointFromPointDistanceHeadingAndPitch(LHPoint* out, const LHPoint& point,
    float distance, float heading, float pitch) {
    // Standard spherical-to-cartesian: heading is rotation about Y, pitch is elevation
    float cos_pitch = cosf(pitch);
    out->x = point.x + distance * sinf(heading) * cos_pitch;
    out->y = point.y + distance * sinf(pitch);
    out->z = point.z + distance * cosf(heading) * cos_pitch;
}

// 0x004428d0 — extract heading and pitch from two points
void GCamera::GetHeadingAndPitchFromPoints(const LHPoint& origin, const LHPoint& target,
    float* out_pitch, float* out_heading) {
    float dx = target.x - origin.x;
    float dy = target.y - origin.y;
    float dz = target.z - origin.z;
    float horizontal_dist = sqrtf(dx * dx + dz * dz);
    if (out_heading) *out_heading = atan2f(dx, dz);
    if (out_pitch) *out_pitch = atan2f(dy, horizontal_dist);
}
