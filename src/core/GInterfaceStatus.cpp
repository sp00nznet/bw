#include "../include/black/GInterfaceStatus.h"

GInterfaceStatus::~GInterfaceStatus() {}
void GInterfaceStatus::ToBeDeleted(int param) {}
GPlayer* GInterfaceStatus::GetPlayer() { return nullptr; }
void GInterfaceStatus::UpdateSpellInfo(Spell* spell, PSysProcessInfo* info) {}
char* GInterfaceStatus::GetDebugText() { return nullptr; }
uint32_t GInterfaceStatus::Load(GameOSFile* file) { return 0; }
uint32_t GInterfaceStatus::Save(GameOSFile* file) { return 0; }
uint32_t GInterfaceStatus::GetSaveType() { return 0; }
void GInterfaceStatus::SaveExtraData(GameOSFile* file) {}
void GInterfaceStatus::ResolveLoad() {}
const char* GInterfaceStatus::GetText() { return nullptr; }

void GInterfaceStatus::SetActive(int param) {}
void GInterfaceStatus::ResetActionState() {}
void GInterfaceStatus::SetToZero(GInterface* iface) {}
void* GInterfaceStatus::GetFirstObjectInCurrentHand() { return nullptr; }
bool GInterfaceStatus::IsSpaceInHands() { return false; }
GInterface* GInterfaceStatus::GetInterface() { return nullptr; }
void GInterfaceStatus::Init(uint8_t player_number, GInterface* iface) {}
