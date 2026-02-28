#include "black/PSysInterface.h"

PSysInterface::~PSysInterface() {}
uint32_t PSysInterface::Process_1(const PSysProcessInfo* info, uint32_t param_3) { return 0; }
void PSysInterface::Process_2(PSysProcessInfo* info) {}
void PSysInterface::Draw_1(float param_1, bool param_2) {}
void PSysInterface::Draw_2(bool param_1) {}
void PSysInterface::AddDrawing(float param_1, const LHPoint* param_2) {}
void PSysInterface::AddTarget_1(const LHPoint* target) {}
void PSysInterface::AddTarget_2(GameThing* target) {}
void PSysInterface::CloseDown() {}
void PSysInterface::SetMagnitude(float value) {}
void PSysInterface::SetAge(float value) {}
void PSysInterface::SetOrigin(const LHPoint* value) {}
void PSysInterface::SetOriginAndMoveAllAtoms(const LHPoint* value) {}
void PSysInterface::SetAlpha(uint8_t value) {}
LHPoint* PSysInterface::GetOrigin() { return nullptr; }
