// TownSpellIcon — spell icon linked to a town's worship site
// Method stubs from bw1-decomp
#include "../include/black/TownSpellIcon.h"

// === Overrides of Base virtuals ===

// 0x00748ae0
void TownSpellIcon::ToBeDeleted(int /*param*/) {}

// === Overrides of GameThing virtuals ===

// 0x00748b90
GPlayer* TownSpellIcon::GetPlayer() { return nullptr; }
// 0x0055e040
Town* TownSpellIcon::GetTown() { return nullptr; }
// 0x0055e060
char* TownSpellIcon::GetDebugText() { return "TownSpellIcon"; }
// 0x00748fb0
uint32_t TownSpellIcon::Load(GameOSFile* /*file*/) { return 0; }
// 0x00748f70
uint32_t TownSpellIcon::Save(GameOSFile* /*file*/) { return 0; }
// 0x0055e050
uint32_t TownSpellIcon::GetSaveType() { return 0; }

// === Overrides of GameThingWithPos virtuals ===

// 0x00748f00
WorshipSite* TownSpellIcon::GetWorshipSite() { return nullptr; }

// === Overrides of Object virtuals ===

// 0x00748be0
size_t TownSpellIcon::SaveObject(LHOSFile* /*param1*/, const MapCoords* /*param2*/) { return 0; }
