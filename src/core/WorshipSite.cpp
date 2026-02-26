// WorshipSite — worship site building (CitadelPart subclass)
// Method stubs from bw1-decomp
#include "../include/black/WorshipSite.h"

// === Overrides of Base virtuals ===

// 0x0077aa60
void WorshipSite::ToBeDeleted(int /*param*/) {}

// === Overrides of GameThing virtuals ===

// 0x0055dc50
void WorshipSite::RemoveDance() {}
// 0x0077bd80
uint32_t WorshipSite::GetResource(RESOURCE_TYPE /*type*/) { return 0; }
// 0x0077c5f0
uint32_t WorshipSite::AddResource(RESOURCE_TYPE /*type*/, uint32_t /*amount*/, GInterfaceStatus* /*status*/, bool /*param4*/, const MapCoords& /*coords*/, int /*param6*/) { return 0; }
// 0x0077c670
uint32_t WorshipSite::RemoveResource(RESOURCE_TYPE /*type*/, uint32_t /*amount*/, GInterfaceStatus* /*status*/, bool* /*param4*/) { return 0; }
// 0x0055dce0
char* WorshipSite::GetDebugText() { return "WorshipSite"; }
// 0x0077cd70
uint32_t WorshipSite::GetShowNeedsPos(uint32_t /*param1*/, MapCoords* /*param2*/) { return 0; }
// 0x0077d700
uint32_t WorshipSite::Load(GameOSFile* /*file*/) { return 0; }
// 0x0077d2f0
uint32_t WorshipSite::Save(GameOSFile* /*file*/) { return 0; }
// 0x0055dcd0
uint32_t WorshipSite::GetSaveType() { return 0; }
// 0x0077daf0
void WorshipSite::ResolveLoad() {}

// === Overrides of GameThingWithPos virtuals ===

// 0x0077ced0
MapCoords* WorshipSite::GetArrivePos(MapCoords* /*out*/) { return nullptr; }
// 0x0055dc30
void WorshipSite::GetInteractPos(LHPoint* /*pos*/) {}
// 0x0055dc80
uint32_t WorshipSite::IsSuitableForCreatureAction() { return 0; }
// 0x004e4b60
uint32_t WorshipSite::CanHaveMagicFoodCastOnMe(Creature* /*creature*/) { return 0; }
// 0x0055dc90
bool32_t WorshipSite::IsWorshipSite_0(Creature* /*creature*/) { return 1; }
// 0x0055dca0
bool32_t WorshipSite::IsWorshipSite_1() { return 1; }
// 0x0055dcb0
WorshipSite* WorshipSite::GetWorshipSite() { return this; }
// 0x0077c310
float WorshipSite::CalculateDesireForFood() { return 0.0f; }
// 0x0077c390
float WorshipSite::CalculateDesireForRest() { return 0.0f; }
// 0x0077c3d0
float WorshipSite::CalculatePeopleHidingIndicator() { return 0.0f; }
// 0x0077d2e0
uint32_t WorshipSite::GetScriptObjectType() { return 0; }

// === Overrides of Object virtuals ===

// 0x0077d030
void WorshipSite::UpdateFrom3DPosition() {}
// 0x0077dde0
LHPoint* WorshipSite::GetDefaultFireCentrePos(LHPoint* /*pos*/) { return nullptr; }
// 0x0077de10
float WorshipSite::GetDefaultFireRadius() { return 0.0f; }
// 0x0077b1d0
uint32_t WorshipSite::Process() { return 0; }
// 0x0055dcc0
int WorshipSite::GetMesh() const { return 0; }
// 0x005193d0
void WorshipSite::Draw() {}
// 0x0077de70
uint32_t WorshipSite::GetDiscipleStateIfInteractedWith(GInterfaceStatus* /*status*/, Villager* /*villager*/) { return 0; }
// 0x0077b9d0
void WorshipSite::CallVirtualFunctionsForCreation(const MapCoords& /*coords*/) {}
// 0x0077dec0
bool WorshipSite::IsResourceStore(RESOURCE_TYPE /*type*/) { return false; }
// 0x0077e7b0
bool WorshipSite::DeleteObjectAndTakeResource(Object* /*object*/, GInterfaceStatus* /*status*/) { return false; }
// 0x0077e480
float WorshipSite::GetRadiusMultiplierForApplyingPotToPos() { return 0.0f; }
// 0x0077def0
bool WorshipSite::DoCreatureMimicAfterAddingResource(RESOURCE_TYPE /*type*/, GInterfaceStatus* /*status*/) { return false; }
// 0x0077de20
float WorshipSite::GetDistanceFromObject_1(Object* /*object*/) { return 0.0f; }
// 0x0055dc60
bool WorshipSite::InteractsWithPhysicsObjects() { return false; }
// 0x0077ae30
bool WorshipSite::GetInspectObjectPos(Villager* /*villager*/, MapCoords* /*coords*/) { return false; }
// 0x0077cc90
uint32_t WorshipSite::GetSpecialPos(uint32_t /*param1*/, MapCoords* /*param2*/) { return 0; }
// 0x0077d000
uint32_t WorshipSite::GetObjectCollide() { return 0; }
// 0x0077c120
size_t WorshipSite::SaveObject(LHOSFile* /*param1*/, const MapCoords* /*param2*/) { return 0; }
// 0x0077dc90
void WorshipSite::GetNearestEdgeOfObject(Object* /*object*/) {}

// === Overrides of MultiMapFixed virtuals ===

// 0x0077e460
void WorshipSite::GetResourceDropPosForComputerPlayer(MapCoords* /*coords*/) {}
// 0x0077bdd0
bool WorshipSite::IsBuilt() { return false; }
// 0x0077ac10
bool WorshipSite::Built() { return false; }
// 0x0055dc70
ABODE_TYPE WorshipSite::GetAbodeType() { return static_cast<ABODE_TYPE>(0); }
// 0x0077c5d0
MapCoords* WorshipSite::GetResourcePos(RESOURCE_TYPE /*type*/, int /*param*/) { return nullptr; }
// 0x0077c6d0
MapCoords* WorshipSite::GetResourceNearestEdge(MapCoords* /*out*/, RESOURCE_TYPE /*type*/, Object* /*object*/, int /*param*/) { return nullptr; }
// 0x0077ae10
void WorshipSite::RemovePotFromStructure(PotStructure* /*structure*/) {}

// === Non-virtual methods ===

// 0x0077afc0
MapCoords* WorshipSite::GetSpellIconPosFromSlot(MapCoords* /*coords*/, uint32_t /*slot*/, float /*angle*/) { return nullptr; }
// 0x0077b080
MapCoords* WorshipSite::GetSpellIconPos(MapCoords* /*coords*/, int16_t* /*slot*/) { return nullptr; }
// 0x0077c430
void WorshipSite::AddSpellIcon(WorshipSpellIcon* /*icon*/) {}
// 0x0077c910
void WorshipSite::AddTownSpells(Town* /*town*/) {}
// 0x0077c9e0
void WorshipSite::AddSpellIconIfNecessary(SPELL_SEED_TYPE /*seed_type*/) {}
// 0x0077cf30
MapCoords* WorshipSite::GetTotemPos(MapCoords* /*coords*/) { return nullptr; }
// 0x0077d0a0
void WorshipSite::RemoveVillagerFromWorshipCount(Villager* /*villager*/) {}
// 0x0077e1d0
void WorshipSite::RemoveVillagerRequestingToGoHome(Villager* /*villager*/) {}
// 0x0077e260
int WorshipSite::GetNumVillagersRequestingToGoHome() { return 0; }
