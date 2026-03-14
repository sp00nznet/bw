// GCamera — main game camera
// Method stubs from bw1-decomp
#include "../include/black/GCamera.h"

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
void GCamera::SwitchToViewMode(CameraMode* /*mode*/) {}
// 0x00441d40
void GCamera::CheckStackedModesForValidity() {}
// 0x00441f50
void GCamera::Validate() {}
// 0x00441f80
void GCamera::Update() {}
// 0x00442ef0
void GCamera::UpdateGameThingWithPosData() {}
// 0x00443680
void GCamera::SetCameraFov(float /*fov*/, float /*time*/) {}

// === Static methods ===

// 0x00441f20
float GCamera::GetThingViewingDistance(GameThingWithPos* /*target*/) { return 0.0f; }
// 0x00442810
void GCamera::SetPointFromPointDistanceHeadingAndPitch(LHPoint* /*out*/, const LHPoint& /*point*/,
    float /*distance*/, float /*heading*/, float /*pitch*/) {}
// 0x004428d0
void GCamera::GetHeadingAndPitchFromPoints(const LHPoint& /*origin*/, const LHPoint& /*heading*/,
    float* /*pitch*/, float* /*yaw*/) {}
