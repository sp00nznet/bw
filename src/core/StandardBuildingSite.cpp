// StandardBuildingSite — standard building construction site with wood pile
// Method stubs from bw1-decomp
#include "../include/black/StandardBuildingSite.h"

// === Overrides of GameThing virtuals ===

// 0x0043d710
char* StandardBuildingSite::GetDebugText() { return "StandardBuildingSite"; }
// 0x0043d890
uint32_t StandardBuildingSite::Load(GameOSFile* /*file*/) { return 0; }
// 0x0043d850
uint32_t StandardBuildingSite::Save(GameOSFile* /*file*/) { return 0; }
// 0x0043d700
uint32_t StandardBuildingSite::GetSaveType() { return 0; }

// === Overrides of BuildingSite virtuals ===

// 0x0043d8d0
void StandardBuildingSite::Process() {}
// 0x0043c5e0
uint32_t StandardBuildingSite::GetWoodForStats() { return 0; }
// 0x0043d6e0
Pot* StandardBuildingSite::GetPileWood(const MapCoords& /*coords*/) { return nullptr; }
// 0x0043d6f0
void StandardBuildingSite::SetPileWood(Pot* /*pile*/) {}
// 0x0043d760
void StandardBuildingSite::CreatePileWood() {}
// 0x0043c220
void StandardBuildingSite::GetResourcePosAndYAngle(uint32_t /*type*/, uint32_t /*param2*/, float* /*out*/) {}
// 0x0043d800
void StandardBuildingSite::RemovePotFromStructure(PotStructure* /*structure*/) {}
// 0x0043d830
bool StandardBuildingSite::IsLinkedToThisBuildingSite(Pot* /*pot*/) { return false; }
// 0x0043ce40
float StandardBuildingSite::GetNearestEdge(float /*x*/, float /*y*/, int* /*out*/) { return 0.0f; }
// 0x0043cf40
void StandardBuildingSite::GetNextPosFromIndex(int* /*index*/) {}
// 0x0043cde0
void StandardBuildingSite::GetRandomBuildPos(Object* /*object*/, int* /*out*/) {}
