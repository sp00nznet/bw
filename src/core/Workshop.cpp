// Workshop class implementation
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)

#include <black/Workshop.h>

void Workshop::ToBeDeleted(int param) { Abode::ToBeDeleted(param); } // 0x00779480

uint32_t Workshop::AddResource(RESOURCE_TYPE, uint32_t, GInterfaceStatus*, bool, const MapCoords&, int) { return 0; } // 0x00779e00
uint32_t Workshop::RemoveResource(RESOURCE_TYPE, uint32_t, GInterfaceStatus*, bool*) { return 0; } // 0x00779ec0
char* Workshop::GetDebugText() { static char t[] = "Workshop"; return t; } // 0x00779310
uint32_t Workshop::GetShowNeedsPos(uint32_t, MapCoords*) { return 0; } // 0x0077a630
uint32_t Workshop::Load(GameOSFile*) { return 0; } // 0x0077a130
uint32_t Workshop::Save(GameOSFile*) { return 0; } // 0x00779f40
uint32_t Workshop::GetSaveType() { return 0; } // 0x00779300
void Workshop::ResolveLoad() { /* 0x0077a330 */ }

bool32_t Workshop::CanActAsAContainer(Creature*) { return 0; } // 0x007792e0
bool32_t Workshop::IsStoragePit(Creature*) { return 0; } // 0x007792f0
bool32_t Workshop::IsWorkshop_0() { return 1; } // 0x007792c0
bool32_t Workshop::IsWorkshop_1(Creature*) { return 1; } // 0x007792d0
bool32_t Workshop::CreateBuildingSite() { return 0; } // 0x0077a6d0

void Workshop::ScaffoldMoved(Scaffold*) { /* 0x0077a610 */ }
uint32_t Workshop::Process() { return 0; } // 0x007797f0
void Workshop::Draw() { /* 0x0051cbf0 */ }
uint32_t Workshop::GetDiscipleStateIfInteractedWith(GInterfaceStatus*, Villager*) { return 0; } // 0x0077a340
void Workshop::CallVirtualFunctionsForCreation(const MapCoords&) { /* 0x007793e0 */ }
LH3DObject_ObjectType Workshop::Get3DType() { return static_cast<LH3DObject_ObjectType>(0); } // 0x007792b0
bool Workshop::IsResourceStore(RESOURCE_TYPE) { return false; } // 0x0077a650
bool Workshop::DeleteObjectAndTakeResource(Object*, GInterfaceStatus*) { return false; } // 0x00779f20
bool Workshop::DoCreatureMimicAfterAddingResource(RESOURCE_TYPE, GInterfaceStatus*) { return false; } // 0x0077a680
