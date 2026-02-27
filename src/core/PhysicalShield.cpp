#include "black/PhysicalShield.h"

void     PhysicalShield::ToBeDeleted(int param) {}
char*    PhysicalShield::GetDebugText() { return "PhysicalShield"; }
uint32_t PhysicalShield::Load(GameOSFile* file) { return 0; }
uint32_t PhysicalShield::Save(GameOSFile* file) { return 0; }
uint32_t PhysicalShield::GetSaveType() { return 0; }
float    PhysicalShield::GetImpressiveValue(Living* living, Reaction* reaction) { return 0.0f; }
void     PhysicalShield::ApplyEffect(EffectValues* effect, int param2) {}
uint32_t PhysicalShield::DestroyedByEffect(GPlayer* player, float param2) { return 0; }
void     PhysicalShield::Draw() {}
void     PhysicalShield::CallVirtualFunctionsForCreation(const MapCoords& coords) {}
LH3DObject_ObjectType PhysicalShield::Get3DType() { return (LH3DObject_ObjectType)0; }
bool     PhysicalShield::SetDying() { return false; }
bool32_t PhysicalShield::IsEffectReceiver(EffectValues* param1) { return 0; }
uint32_t PhysicalShield::GetPhysicsConstantsType() { return 0; }
void     PhysicalShield::SetUpPhysOb(PhysOb* physOb) {}
bool     PhysicalShield::InteractsWithPhysicsObjects() { return false; }
void     PhysicalShield::ReactToPhysicsImpact(PhysicsObject* param1, bool param2) {}
bool     PhysicalShield::GetAlwaysRemainsInPhysicsInternalSystem() { return false; }
void     PhysicalShield::ProcessShield() {}
void     PhysicalShield::DrawShield() {}
bool     PhysicalShield::IsPointDefinietlyWithinShieldVolume(const MapCoords* point) { return false; }
