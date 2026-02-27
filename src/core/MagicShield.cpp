#include "black/MagicShield.h"

char*    MagicShield::GetDebugText() { return "MagicShield"; }
uint32_t MagicShield::Load(GameOSFile* file) { return 0; }
uint32_t MagicShield::Save(GameOSFile* file) { return 0; }
uint32_t MagicShield::GetSaveType() { return 0; }
void     MagicShield::Draw() {}
void     MagicShield::CallVirtualFunctionsForCreation(const MapCoords& coords) {}
LH3DObject_ObjectType MagicShield::Get3DType() { return (LH3DObject_ObjectType)0; }
bool     MagicShield::SetDying() { return false; }
bool32_t MagicShield::IsEffectReceiver(EffectValues* param1) { return 0; }
bool     MagicShield::InteractsWithPhysicsObjects() { return false; }
void     MagicShield::ProcessShield() {}
void     MagicShield::DrawShield() {}
bool     MagicShield::IsPointDefinietlyWithinShieldVolume(const MapCoords* point) { return false; }
