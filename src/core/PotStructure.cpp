#include "black/PotStructure.h"

void     PotStructure::ToBeDeleted(int param) {}
GPlayer* PotStructure::GetPlayer() { return nullptr; }
void     PotStructure::SetPlayer(GPlayer* player) {}
Town*    PotStructure::GetTown() { return nullptr; }
uint32_t PotStructure::JustRemoveResource(RESOURCE_TYPE type, uint32_t amount, bool* param3) { return 0; }
uint32_t PotStructure::GetResource(RESOURCE_TYPE type) { return 0; }
uint32_t PotStructure::AddResource(RESOURCE_TYPE type, uint32_t amount, GInterfaceStatus* status, bool param4, const MapCoords& coords, int param6) { return 0; }
uint32_t PotStructure::RemoveResource(RESOURCE_TYPE type, uint32_t amount, GInterfaceStatus* status, bool* param4) { return 0; }
uint32_t PotStructure::Load(GameOSFile* file) { return 0; }
uint32_t PotStructure::Save(GameOSFile* file) { return 0; }
bool32_t PotStructure::CanBeThrownByPlayer() { return 0; }
void     PotStructure::CallVirtualFunctionsForCreation(const MapCoords& coords) {}
bool     PotStructure::IsResourceStore(RESOURCE_TYPE type) { return false; }
void     PotStructure::SetSize() {}
bool     PotStructure::IsPartOfStructure() { return false; }
void     PotStructure::SetSpeedUp(int speed) {}
void     PotStructure::SetMultiMapFixed(MultiMapFixed* multiMapFixed) {}
