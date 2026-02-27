#include "black/SpecialVillager.h"

char*       SpecialVillager::GetDebugText() { return "SpecialVillager"; }
uint32_t    SpecialVillager::Load(GameOSFile* file) { return 0; }
uint32_t    SpecialVillager::Save(GameOSFile* file) { return 0; }
uint32_t    SpecialVillager::GetSaveType() { return 0; }
void        SpecialVillager::Draw() {}
const char* SpecialVillager::GetVillagerName() { return ""; }
