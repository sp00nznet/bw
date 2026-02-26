// TownCentre class implementation
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)

#include <black/TownCentre.h>

void TownCentre::ToBeDeleted(int param) { Abode::ToBeDeleted(param); } // 0x00743b40
char* TownCentre::GetDebugText() { static char t[] = "TownCentre"; return t; } // 0x0055dba0
uint32_t TownCentre::Load(GameOSFile*) { return 0; } // 0x00744880
uint32_t TownCentre::Save(GameOSFile*) { return 0; } // 0x00744830
uint32_t TownCentre::GetSaveType() { return 0; } // 0x0055db90
void TownCentre::ResolveLoad() { /* 0x007448c0 */ }

MapCoords* TownCentre::GetArrivePos(MapCoords* out) { return out; } // 0x007449e0
bool32_t TownCentre::IsCastShadowAtNight() { return 1; } // 0x0055db60
bool32_t TownCentre::IsTownCentre() { return 1; } // 0x0055db70
bool32_t TownCentre::CanActAsAContainer(Creature*) { return 0; } // 0x0055db40
bool32_t TownCentre::IsStoragePit(Creature*) { return 0; } // 0x0055db50

void TownCentre::ReduceLife(float v, GPlayer* p) { Abode::ReduceLife(v, p); } // 0x007445d0
void TownCentre::IncreaseLife(float v) { Abode::IncreaseLife(v); } // 0x00744320
uint32_t TownCentre::Process() { return 0; } // 0x00743df0
void TownCentre::Draw() { /* 0x00516450 */ }
uint32_t TownCentre::GetDiscipleStateIfInteractedWith(GInterfaceStatus*, Villager*) { return 0; } // 0x007448e0
void TownCentre::CallVirtualFunctionsForCreation(const MapCoords& c) { Abode::CallVirtualFunctionsForCreation(c); } // 0x00743cf0
LH3DObject_ObjectType TownCentre::Get3DType() { return static_cast<LH3DObject_ObjectType>(0); } // 0x0055db20
uint32_t TownCentre::InterfaceValidToTap(GInterfaceStatus*) { return 0; } // 0x0055db10
bool TownCentre::InteractsWithPhysicsObjects() { return true; } // 0x00743bc0
void TownCentre::ReactToPhysicsImpact(PhysicsObject*, bool) { /* 0x00744380 */ }
size_t TownCentre::SaveObject(LHOSFile*, const MapCoords*) { return 0; } // 0x00744140

MapCoords* TownCentre::GetDoorPos(MapCoords* out) { return out; } // 0x00744940
void TownCentre::AddToPlayer() { /* 0x007443a0 */ }
PlannedMultiMapFixed* TownCentre::ConvertToPlanned() { return nullptr; } // 0x007443c0

void TownCentre::DeleteDependancys() { /* 0x00743be0 */ }
void TownCentre::MakeFunctional() { /* 0x00743e80 */ }
void TownCentre::StopBeingFunctional(GPlayer*) { /* 0x00744a00 */ }
bool TownCentre::CausesTownEmergencyIfDamaged() { return true; } // 0x0055db30
bool TownCentre::CanBeHiddenIn() { return true; } // 0x0055db80
