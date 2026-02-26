// TownCentreSpellIcon — town centre spell icon with power-up levels
// Method stubs from bw1-decomp
#include "../include/black/TownCentreSpellIcon.h"

// === Overrides of Base virtuals ===

// 0x00748c80
void TownCentreSpellIcon::ToBeDeleted(int /*param*/) {}

// === Overrides of GameThing virtuals ===

// 0x0055e0b0
char* TownCentreSpellIcon::GetDebugText() { return "TownCentreSpellIcon"; }
// 0x007490e0
uint32_t TownCentreSpellIcon::Load(GameOSFile* /*file*/) { return 0; }
// 0x00748ff0
uint32_t TownCentreSpellIcon::Save(GameOSFile* /*file*/) { return 0; }
// 0x0055e0a0
uint32_t TownCentreSpellIcon::GetSaveType() { return 0; }

// === Overrides of Object virtuals ===

// 0x00519640
void TownCentreSpellIcon::Draw() {}
// 0x00748d20
void TownCentreSpellIcon::CallVirtualFunctionsForCreation(const MapCoords& /*coords*/) {}

// === Non-virtual methods ===

// 0x00748eb0
void TownCentreSpellIcon::SetPULevel(POWER_UP_TYPE /*power_up_type*/, bool /*enabled*/) {}
// 0x00748ed0
void TownCentreSpellIcon::UpdateGraphicWithPULevels() {}
