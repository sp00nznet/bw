#pragma once
// GStreetLight — street light illumination object
// Struct layout from bw1-decomp
//
// Size: 0x2C bytes (inherits 0x28 from GameThingWithPos + 4 bytes)
// Simple methods at 0x005613xx-0x005614xx are packed 16 bytes apart.
// Complex methods at 0x007350xx-0x007351xx.

#include "GameThingWithPos.h"

struct GStreetLight : public GameThingWithPos {
    // === Overrides of Base virtuals ===
    void ToBeDeleted(int param) override;

    // === Overrides of GameThing virtuals ===
    GPlayer* GetPlayer() override;
    char* GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;
    void ResolveLoad() override;

    // === Overrides of GameThingWithPos virtuals ===
    float GetDistanceFromObject(const MapCoords& target) override;
    bool32_t IsStreetLight() override;
    const char* GetText() override;

    // === Fields ===
    uint32_t field_0x28;  // 0x28
};
static_assert(sizeof(GStreetLight) == 0x2C, "GStreetLight size mismatch");
