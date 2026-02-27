#include "black/MagicFood.h"

GPlayer*        MagicFood::GetPlayer() { return nullptr; }
void            MagicFood::SetPlayer(GPlayer* player) {}
char*           MagicFood::GetDebugText() { return "MagicFood"; }
uint32_t        MagicFood::Load(GameOSFile* file) { return 0; }
uint32_t        MagicFood::Save(GameOSFile* file) { return 0; }
uint32_t        MagicFood::GetSaveType() { return 0; }
IMPRESSIVE_TYPE MagicFood::GetImpressiveType() { return (IMPRESSIVE_TYPE)0; }
bool32_t        MagicFood::IsAFoodPileOutsideStoragePit(Creature* creature) { return 0; }
void            MagicFood::CallVirtualFunctionsForCreation(const MapCoords& coords) {}
