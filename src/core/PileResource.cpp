#include "black/PileResource.h"

uint32_t PileResource::JustAddResource(RESOURCE_TYPE type, uint32_t amount, bool param3) { return 0; }
uint32_t PileResource::Load(GameOSFile* file) { return 0; }
uint32_t PileResource::Save(GameOSFile* file) { return 0; }
float    PileResource::GetLife() { return 0.0f; }
bool32_t PileResource::IsField_1(Creature* creature) { return 0; }
bool32_t PileResource::CanBePickedUpByCreature(Creature* creature) { return 0; }
bool32_t PileResource::IsPileResource() { return 1; }
void     PileResource::SetLife(float life) {}
void     PileResource::CallVirtualFunctionsForCreation(const MapCoords& coords) {}
bool     PileResource::IsLockedInInteract() { return false; }
bool32_t PileResource::ValidForLockedSelectProcess(GInterfaceStatus* status) { return 0; }
bool32_t PileResource::NetworkFriendlyStartLockedSelect(GInterfaceStatus* status) { return 0; }
uint32_t PileResource::NetworkUnfriendlyLockedSelect(ControlHandUpdateInfo* info) { return 0; }
uint32_t PileResource::NetworkUnfriendlyEndLockedSelect() { return 0; }
uint32_t PileResource::NetworkFriendlyEndLockedSelect(GInterfaceStatus* status) { return 0; }
bool32_t PileResource::ValidForPlaceInHand(GInterfaceStatus* status) { return 0; }
bool32_t PileResource::InterfaceSetInMagicHand(GInterfaceStatus* status) { return 0; }
uint32_t PileResource::IsTuggable() { return 0; }
uint32_t PileResource::ProcessInInteract(GInterfaceStatus* status) { return 0; }
