// StoragePit class implementation
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)

#include <black/StoragePit.h>

void StoragePit::Delete(int param) { Abode::Delete(param); } // 0x00732c10
void StoragePit::ToBeDeleted(int param) { Abode::ToBeDeleted(param); } // 0x00732c30

uint32_t StoragePit::AddResource(RESOURCE_TYPE, uint32_t, GInterfaceStatus*, bool, const MapCoords&, int) { return 0; } // 0x00732f60
uint32_t StoragePit::RemoveResource(RESOURCE_TYPE, uint32_t, GInterfaceStatus*, bool*) { return 0; } // 0x007332a0

char* StoragePit::GetDebugText() { static char t[] = "StoragePit"; return t; } // 0x0055cd40
uint32_t StoragePit::Load(GameOSFile*) { return 0; } // 0x00733920
uint32_t StoragePit::Save(GameOSFile*) { return 0; } // 0x007338d0
uint32_t StoragePit::GetSaveType() { return 0; } // 0x0055cd30

MapCoords* StoragePit::GetArrivePos(MapCoords* out) { return out; } // 0x0055ccb0
bool32_t StoragePit::IsCastShadowAtNight() { return 1; } // 0x0055ccf0
bool32_t StoragePit::CanBeEatenByCreature(Creature*) { return 0; } // 0x0055cd10
bool32_t StoragePit::CanActAsAContainer(Creature*) { return 1; } // 0x0055cd00
bool32_t StoragePit::CanHaveMagicFoodCastOnMe(Creature*) { return 0; } // 0x004e4b50
bool32_t StoragePit::CanHaveMagicWoodCastOnMe(Creature*) { return 0; } // 0x004e4b70
bool32_t StoragePit::IsStoragePit(Creature*) { return 1; } // 0x004e4990
bool32_t StoragePit::IsStoragePitWithFoodInIt(Creature*) { return 0; } // 0x004e4d90
bool32_t StoragePit::IsStoragePitBelongingToAnotherPlayer(Creature*) { return 0; } // 0x004e49a0
bool32_t StoragePit::IsStoragePitBelongingToMyPlayer(Creature*) { return 0; } // 0x004e49e0
bool32_t StoragePit::IsPoisoned() { return 0; } // 0x007336b0

void StoragePit::Draw() { /* 0x00519350 */ }
uint32_t StoragePit::GetDiscipleStateIfInteractedWith(GInterfaceStatus*, Villager*) { return 0; } // 0x00733a20
void StoragePit::CallVirtualFunctionsForCreation(const MapCoords&) { /* 0x00732e80 */ }
LH3DObject_ObjectType StoragePit::Get3DType() { return static_cast<LH3DObject_ObjectType>(0); } // 0x0055ccd0
bool StoragePit::IsResourceStore(RESOURCE_TYPE) { return true; } // 0x0055cd20
bool StoragePit::DeleteObjectAndTakeResource(Object*, GInterfaceStatus*) { return false; } // 0x00733750
bool StoragePit::DoCreatureMimicAfterAddingResource(RESOURCE_TYPE, GInterfaceStatus*) { return false; } // 0x00733810
void StoragePit::SetPoisonedResource(RESOURCE_TYPE, int) { /* 0x007335f0 */ }
void StoragePit::SetPoisoned(int) { /* 0x007335d0 */ }
void StoragePit::ReactToPhysicsImpact(PhysicsObject*, bool) { /* 0x00733730 */ }

bool StoragePit::IsPoisonedResource() { return false; } // 0x00733550
MapCoords* StoragePit::GetResourceNearestEdge(MapCoords* c, RESOURCE_TYPE, Object*, int) { return c; } // 0x00733400
int StoragePit::CalulateAmountOverMaximum(RESOURCE_TYPE) { return 0; } // 0x00733260
void StoragePit::RemovePotFromStructure(PotStructure*) { /* 0x007331d0 */ }

void StoragePit::DeleteDependancys() { /* 0x00732cd0 */ }
void StoragePit::MakeFunctional() { /* 0x00732f30 */ }
void StoragePit::StopBeingFunctional(GPlayer*) { /* 0x00733960 */ }
void StoragePit::RestartBeingFunctional() { /* 0x007339d0 */ }
bool StoragePit::CausesTownEmergencyIfDamaged() { return true; } // 0x0055cce0
