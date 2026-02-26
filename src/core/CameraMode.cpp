// CameraMode — abstract base for camera behavior modes
// Method stubs from bw1-decomp
#include "../include/black/CameraMode.h"

CameraMode::~CameraMode() {}
bool CameraMode::CanPlayerGestureWhenCameraMoving() { return false; }
void CameraMode::Update() {}
void CameraMode::Validate() {}
void CameraMode::Restart() {}
bool CameraMode::IsStillValid() { return true; }
void CameraMode::Cleanup() {}
bool CameraMode::CanExist() { return true; }
bool CameraMode::MouseIsLocked() { return false; }
void CameraMode::GetMousePos(LHCoord* /*pos*/) {}
void CameraMode::ProcessKeyMovement(uint16_t /*key*/) {}
void CameraMode::ProcessMouseMovement() {}
void CameraMode::Delete() {}
bool CameraMode::Arrived() { return true; }
uint32_t CameraMode::GetSaveID() { return 0; }
void CameraMode::Load(GameOSFile* /*file*/) {}
void CameraMode::Save(GameOSFile* /*file*/) {}
const char* CameraMode::GetDebugName() { return "CameraMode"; }
