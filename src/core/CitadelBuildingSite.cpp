// CitadelBuildingSite — building site for citadel construction
// Method stubs from bw1-decomp
#include "../include/black/CitadelBuildingSite.h"

// === Overrides of Base virtuals ===

// 0x0043d220
void CitadelBuildingSite::ToBeDeleted(int /*param*/) {}

// === Overrides of GameThing virtuals ===

// 0x0043d320
uint32_t CitadelBuildingSite::GetResource(RESOURCE_TYPE /*type*/) { return 0; }
// 0x0043d360
uint32_t CitadelBuildingSite::AddResource(RESOURCE_TYPE /*type*/, uint32_t /*amount*/, GInterfaceStatus* /*status*/, bool /*param4*/, const MapCoords& /*coords*/, int /*param6*/) { return 0; }
// 0x0043d3f0
uint32_t CitadelBuildingSite::RemoveResource(RESOURCE_TYPE /*type*/, uint32_t /*amount*/, GInterfaceStatus* /*status*/, bool* /*param4*/) { return 0; }
// 0x0043d1a0
char* CitadelBuildingSite::GetDebugText() { return "CitadelBuildingSite"; }
// 0x0043d620
uint32_t CitadelBuildingSite::Load(GameOSFile* /*file*/) { return 0; }
// 0x0043d5e0
uint32_t CitadelBuildingSite::Save(GameOSFile* /*file*/) { return 0; }
// 0x0043d190
uint32_t CitadelBuildingSite::GetSaveType() { return 0; }

// === Overrides of BuildingSite virtuals ===

// 0x0043d660
void CitadelBuildingSite::Process() {}
// 0x0043d500
Pot* CitadelBuildingSite::GetPileWood(const MapCoords& /*coords*/) { return nullptr; }
// 0x0043d180
void CitadelBuildingSite::SetPileWood(Pot* /*pile*/) {}
// 0x0043d460
void CitadelBuildingSite::CreatePileWood() {}
// 0x0043d470
void CitadelBuildingSite::GetResourcePosAndYAngle(uint32_t /*type*/, uint32_t /*param2*/, float* /*out*/) {}
// 0x0043d5b0
void CitadelBuildingSite::RemovePotFromStructure(PotStructure* /*structure*/) {}
// 0x0043d580
bool CitadelBuildingSite::IsLinkedToThisBuildingSite(Pot* /*pot*/) { return false; }
