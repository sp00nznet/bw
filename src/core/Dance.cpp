#include "black/Dance.h"

// GameThing overrides
GFootpathLink* Dance::GetFootpathLink() { return nullptr; }
uint32_t Dance::AddFootpath(GFootpath*) { return 0; }
uint32_t Dance::RemoveFootpath(GFootpath*) { return 0; }
char*    Dance::GetDebugText() { return "Dance"; }
uint32_t Dance::Load(GameOSFile* file) { return 0; }
uint32_t Dance::Save(GameOSFile* file) { return 0; }
uint32_t Dance::GetSaveType() { return 0; }

// GameThingWithPos overrides
MapCoords* Dance::GetArrivePos(MapCoords* out) { return out; }
bool32_t   Dance::IsDance() const { return 1; }
uint32_t   Dance::GetScriptObjectType() { return 0; }

// GroupBehaviour overrides
void  Dance::Process() {}
float Dance::GetAngle() { return 0.0f; }
