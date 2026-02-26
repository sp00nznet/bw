// BuildingSite — building construction management
// Method stubs from bw1-decomp
#include "../include/black/BuildingSite.h"

// === New virtual methods (BuildingSite-specific vtable extensions) ===

// 0x0043b950
void BuildingSite::Init() {}
void BuildingSite::Process() {}
uint32_t BuildingSite::GetWoodForStats() { return 0; }
Pot* BuildingSite::GetPileWood(const MapCoords& /*coords*/) { return nullptr; }
void BuildingSite::SetPileWood(Pot* /*pile*/) {}
void BuildingSite::CreatePileWood() {}
void BuildingSite::GetResourcePosAndYAngle(uint32_t /*type*/, uint32_t /*param2*/, float* /*out*/) {}
void BuildingSite::RemovePotFromStructure(PotStructure* /*structure*/) {}
bool BuildingSite::IsLinkedToThisBuildingSite(Pot* /*pot*/) { return false; }
float BuildingSite::GetNearestEdge(float /*x*/, float /*y*/, int* /*out*/) { return 0.0f; }
void BuildingSite::GetNextPosFromIndex(int* /*index*/) {}
void BuildingSite::GetRandomBuildPos(Object* /*object*/, int* /*out*/) {}

// === Overrides of Base virtuals ===

// 0x0043b7b0
BuildingSite::~BuildingSite() {}
// 0x0043b960
void BuildingSite::ToBeDeleted(int /*param*/) {}

// === Overrides of GameThing virtuals ===

// 0x0043c0b0
Town* BuildingSite::GetTown() { return nullptr; }
// 0x0043d050
float BuildingSite::GetRadius() { return 0.0f; }
// 0x0043c5b0
uint32_t BuildingSite::GetResource(RESOURCE_TYPE /*type*/) { return 0; }
// 0x0043c490
uint32_t BuildingSite::AddResource(RESOURCE_TYPE /*type*/, uint32_t /*amount*/, GInterfaceStatus* /*status*/, bool /*param4*/, const MapCoords& /*coords*/, int /*param6*/) { return 0; }
// 0x0043c530
uint32_t BuildingSite::RemoveResource(RESOURCE_TYPE /*type*/, uint32_t /*amount*/, GInterfaceStatus* /*status*/, bool* /*param4*/) { return 0; }
// 0x0043cad0
uint32_t BuildingSite::Load(GameOSFile* /*file*/) { return 0; }
// 0x0043c830
uint32_t BuildingSite::Save(GameOSFile* /*file*/) { return 0; }
// 0x0043b7a0
uint32_t BuildingSite::GetSaveType() { return 0; }

// === Non-virtual methods ===

// 0x0043bc70
MultiMapFixed* BuildingSite::GetBuilding() { return nullptr; }
// 0x0043bca0
MultiMapFixed* BuildingSite::GetRootBuilding() { return nullptr; }
// 0x0043bde0
float BuildingSite::GetClearAreaRadius() { return 0.0f; }
// 0x0043be00
float BuildingSite::GetDesireToBeRepaired() { return 0.0f; }
// 0x0043c0c0
float BuildingSite::GetWoodValue() { return 0.0f; }
// 0x0043c5f0
float BuildingSite::GetWoodNeededToBuild() { return 0.0f; }
// 0x0043c680
bool32_t BuildingSite::ShouldIGetWood(Villager* /*villager*/) { return 0; }
// 0x0043d080
void BuildingSite::BuildBy(float /*amount*/) {}
