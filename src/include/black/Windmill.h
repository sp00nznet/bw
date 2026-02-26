#pragma once
// Windmill — Abode subclass with animated windmill blades
// Struct layout from bw1-decomp
//
// Size: 0xC4 bytes (same as Abode — no new fields)
// Vtable: 0x92C bytes (same as Abode, overrides 3 methods)
//
// Windmill adds no data beyond Abode. It overrides Draw for
// blade animation, GetSaveType/GetDebugText for identity, and
// CallVirtualFunctionsForCreation for sound setup.

#include "Abode.h"

struct Windmill : public Abode {
    // === Overrides ===
    char* GetDebugText() override;
    uint32_t GetSaveType() override;
    void Draw() override;
    void CallVirtualFunctionsForCreation(const MapCoords& coords) override;

    // No new fields — sizeof(Windmill) == sizeof(Abode) == 0xC4
};
static_assert(sizeof(Windmill) == 0xC4, "Windmill size mismatch");
