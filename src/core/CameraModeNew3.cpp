#include "../include/black/CameraModeNew3.h"

// CameraMode overrides
void CameraModeNew3::Update() {}

// New virtuals
void CameraModeNew3::Initialise() {}
void CameraModeNew3::Reinitialise(bool param_2) {}
void CameraModeNew3::FlyToPosFoc(LHPoint* param_2, LHPoint* param_3, float param_4) {}
void CameraModeNew3::SetupVia(const LHPoint* param_2, const LHPoint* param_3, const LHPoint* param_4, float param_5) {}
uint32_t CameraModeNew3::GetCameraFeatures() { return 0; }
void CameraModeNew3::ForceRotateAboutPoint(LHPoint* point) {}

// Non-virtual methods
void CameraModeNew3::UpdateTricons() {}
void CameraModeNew3::UpdateClickParams(const LHPoint* param_1, const LHPoint* param_2, bool param_3) {}
float CameraModeNew3::GetAltitude(LHPoint* param_1) { return 0.0f; }
void CameraModeNew3::SetAltitudeAndNormal(LHPoint* param_1, LHPoint* normal) {}
void CameraModeNew3::DragFocusOntoLand(LHPoint* param_1, LHPoint* param_2) {}
bool CameraModeNew3::UpdateStrafe(LHPoint* param_1, LHPoint* param_2, float* param_3, float* param_4, float param_5, uint32_t param_6) { return false; }
bool CameraModeNew3::WantToQuitFight(LHPoint param_1, LHPoint param_2, float param_3) { return false; }
void CameraModeNew3::StartFight(GArena* arena) {}
void CameraModeNew3::EndFightNow(int param_1) {}

// Static methods
float CameraModeNew3::CalcPerpDistance(LHPoint* param_1, LHPoint* param_2, LHPoint* param_3) { return 0.0f; }
float CameraModeNew3::FindBestAngle(float param_1, float param_2, float* param_3, float* param_4, float* param_5) { return 0.0f; }
