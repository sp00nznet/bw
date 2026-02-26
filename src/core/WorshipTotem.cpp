// WorshipTotem — totem statue at worship site
// Method stubs from bw1-decomp
#include "../include/black/WorshipTotem.h"

// === Overrides of Base virtuals ===

// 0x007808e0
void WorshipTotem::ToBeDeleted(int /*param*/) {}

// === Overrides of GameThing virtuals ===

// 0x00780800
char* WorshipTotem::GetDebugText() { return "WorshipTotem"; }
// 0x00780f10
uint32_t WorshipTotem::Load(GameOSFile* /*file*/) { return 0; }
// 0x00780f90
uint32_t WorshipTotem::Save(GameOSFile* /*file*/) { return 0; }
// 0x007807f0
uint32_t WorshipTotem::GetSaveType() { return 0; }
// 0x00780f00
void WorshipTotem::ResolveLoad() {}

// === Overrides of GameThingWithPos virtuals ===

// 0x00780ad0
float WorshipTotem::GetPSysPower() const { return 0.0f; }
// 0x00780a80
float WorshipTotem::CalculateDesireForFood() { return 0.0f; }
// 0x00780a90
float WorshipTotem::CalculateDesireForRest() { return 0.0f; }
// 0x00780aa0
float WorshipTotem::CalculatePeopleHidingIndicator() { return 0.0f; }
// 0x007807e0
uint32_t WorshipTotem::IsSacrificeAltar() { return 0; }

// === Overrides of Object virtuals ===

// 0x007807b0
void WorshipTotem::SetSpecularColor(LH3DColor /*color*/) {}
// 0x007807c0
LH3DColor WorshipTotem::GetSpecularColor() { return LH3DColor{}; }
// 0x00780a70
int WorshipTotem::GetMesh() const { return 0; }
// 0x00519360
void WorshipTotem::Draw() {}
// 0x00780ab0
void WorshipTotem::CallVirtualFunctionsForCreation(const MapCoords& /*coords*/) {}
// 0x007807d0
LH3DObject_ObjectType WorshipTotem::Get3DType() { return static_cast<LH3DObject_ObjectType>(0); }
// 0x00780790
bool WorshipTotem::IsSpellSeedReturnPoint() const { return false; }
// 0x007807a0
uint32_t WorshipTotem::IsEffectReceiver(EffectValues* /*values*/) { return 0; }

// === Static methods ===

// 0x00780930
WorshipTotem* WorshipTotem::Create(WorshipSite* /*site*/) { return nullptr; }
