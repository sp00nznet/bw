// WorshipSpellIcon — spell icon on worship site totem
// Method stubs from bw1-decomp
#include "../include/black/WorshipSpellIcon.h"

// === Overrides of Base virtuals ===

// 0x0077f230
void WorshipSpellIcon::ToBeDeleted(int /*param*/) {}

// === Overrides of GameThing virtuals ===

// 0x0077f6f0
void WorshipSpellIcon::MaintainSpell(uint32_t /*param1*/, float /*param2*/) {}
// 0x0077f750
void WorshipSpellIcon::UpdateSpellInfo(Spell* /*spell*/, PSysProcessInfo* /*info*/) {}
// 0x0077f100
char* WorshipSpellIcon::GetDebugText() { return "WorshipSpellIcon"; }
// 0x007801f0
uint32_t WorshipSpellIcon::Load(GameOSFile* /*file*/) { return 0; }
// 0x0077ff80
uint32_t WorshipSpellIcon::Save(GameOSFile* /*file*/) { return 0; }
// 0x0077f0f0
uint32_t WorshipSpellIcon::GetSaveType() { return 0; }

// === Overrides of GameThingWithPos virtuals ===

// 0x0077f0a0
WorshipSite* WorshipSpellIcon::GetWorshipSite() { return nullptr; }

// === Overrides of Object virtuals ===

// 0x0077f0e0
void WorshipSpellIcon::ApplyEffect(EffectValues* /*values*/, int /*param*/) {}
// 0x0077f390
uint32_t WorshipSpellIcon::Process() { return 0; }
// 0x0077f290
void WorshipSpellIcon::CallVirtualFunctionsForCreation(const MapCoords& /*coords*/) {}
// 0x0077f0b0
uint32_t WorshipSpellIcon::IsEffectReceiver(EffectValues* /*values*/) { return 0; }
// 0x0077f0d0
size_t WorshipSpellIcon::SaveObject(LHOSFile* /*param1*/, const MapCoords* /*param2*/) { return 0; }

// === Non-virtual methods ===

// 0x0077f1f0
void WorshipSpellIcon::SetZero() {}
// 0x0077f320
void WorshipSpellIcon::UpdateGraphicsWithPULevels() {}
// 0x0077ff40
void WorshipSpellIcon::StopRemoveFromPlayer() {}

// === Static methods ===

// 0x0077f2b0
WorshipSpellIcon* WorshipSpellIcon::Create(const MapCoords& /*coords*/, const GSpellIconInfo* /*icon_info*/,
    const GSpellSeedInfo* /*seed_info*/, WorshipSite* /*site*/, int16_t /*slot*/, float /*param6*/, int /*param7*/) {
    return nullptr;
}
