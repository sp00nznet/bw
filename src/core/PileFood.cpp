#include "black/PileFood.h"

void          PileFood::ToBeDeleted(int param) {}
float         PileFood::Get2DRadius() { return 0.0f; }
char*         PileFood::GetDebugText() { return "PileFood"; }
uint32_t      PileFood::Load(GameOSFile* file) { return 0; }
uint32_t      PileFood::Save(GameOSFile* file) { return 0; }
uint32_t      PileFood::GetSaveType() { return 0; }
bool32_t      PileFood::IsPileFood() { return 1; }
HELP_TEXT     PileFood::GetQueryFirstEnumText() { return (HELP_TEXT)0; }
HELP_TEXT     PileFood::GetQueryLastEnumText() { return (HELP_TEXT)0; }
void          PileFood::Draw() {}
void          PileFood::CallVirtualFunctionsForCreation(const MapCoords& coords) {}
LH3DObject_ObjectType PileFood::Get3DType() { return (LH3DObject_ObjectType)0; }
RESOURCE_TYPE PileFood::GetResourceType() { return (RESOURCE_TYPE)0; }
bool          PileFood::CreatureMustAvoid(Creature* creature) { return false; }
