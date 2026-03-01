#include "../include/black/GInterface.h"

GInterface::~GInterface() {}
void GInterface::ToBeDeleted(int param) {}
int GInterface::Get3DSoundPos(LHPoint* pos) { return 0; }
GPlayer* GInterface::GetPlayer() { return nullptr; }
char* GInterface::GetDebugText() { return nullptr; }
uint32_t GInterface::Load(GameOSFile* file) { return 0; }
uint32_t GInterface::Save(GameOSFile* file) { return 0; }
uint32_t GInterface::GetSaveType() { return 0; }
void GInterface::SaveExtraData(GameOSFile* file) {}
void GInterface::ResolveLoad() {}
bool32_t GInterface::IsActive() const { return 0; }
const char* GInterface::GetText() { return nullptr; }

void GInterface::SetToZero() {}
void GInterface::Init(uint8_t param) {}
void GInterface::InitLeash() {}
void GInterface::SetupHand() {}
void GInterface::PreDrawProcess() {}
void GInterface::PostDrawProcess() {}
void GInterface::Process() {}
void GInterface::UpdateHandRenderCollide() {}
void GInterface::UpdateAllLeashes() {}
void GInterface::SendMessage(INTERFACE_MESSAGE_TYPES type, LHCoord* coord) {}
