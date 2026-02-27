#include "black/MagicWood.h"

GPlayer*        MagicWood::GetPlayer() { return nullptr; }
char*           MagicWood::GetDebugText() { return "MagicWood"; }
uint32_t        MagicWood::Load(GameOSFile* file) { return 0; }
uint32_t        MagicWood::Save(GameOSFile* file) { return 0; }
uint32_t        MagicWood::GetSaveType() { return 0; }
IMPRESSIVE_TYPE MagicWood::GetImpressiveType() { return (IMPRESSIVE_TYPE)0; }
bool32_t        MagicWood::IsAWoodPileOutsideStoragePit(Creature* creature) { return 0; }
void            MagicWood::CallVirtualFunctionsForCreation(const MapCoords& coords) {}
