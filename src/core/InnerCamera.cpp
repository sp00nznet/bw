#include "black/InnerCamera.h"

void InnerCamera::ReloadCamera(char* param_1) {}
void InnerCamera::PreDraw() {}
void InnerCamera::Init(char* param_1) {}
void InnerCamera::Reinit() {}
void InnerCamera::Close() {}
uint32_t InnerCamera::CalcDoorHit(InnerRoom* room, LHCoord coord, float param_3, bool param_4) { return 0; }
void InnerCamera::Update(InnerRoom* room, float param_2, int param_3, int param_4, const LHCoord* coord, bool param_6) {}
void InnerCamera::UpdateMain(InnerRoom* room, float param_2, int param_3, int param_4, const LHCoord* coord, bool param_6) {}
void InnerCamera::UpdateState(InnerRoom* room, float param_2, int param_3, int param_4, const LHCoord* coord, bool param_6) {}
void InnerCamera::FocusOnSubMesh(LH3DMesh* mesh, int param_2, float param_3, float param_4, float param_5) {}
void InnerCamera::TriggerIntro(bool param_1, Zoomer3d* zoomer1, Zoomer3d* zoomer2) {}
InnerCamera::~InnerCamera() {}
