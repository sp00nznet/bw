#include "../include/black/PSysHandFX.h"

// PSysHandFX statics
PSysHandFX* PSysHandFX::CreateHandFX() { return nullptr; }
void PSysHandFX::CreateTribalPowerColumn() {}

// PHandFX overrides
void PHandFX::RemoveAllPermBands() {}
void PHandFX::DoRemoveFromHandVisual() {}
void PHandFX::AddSpellToHandVisuals() {}
void PHandFX::SetPULevel(uint32_t level) {}
void PHandFX::DrawHandFX() {}
uint32_t PHandFX::GetPULevel() { return 0; }
void PHandFX::StartTribalPowerRing() {}
void PHandFX::StopTribalPowerRing() {}
void PHandFX::ReleaseOrCreateTribalPowerRing() {}
void PHandFX::Release() {}

// PHandFX_Band
PHandFX_Band::~PHandFX_Band() {}
