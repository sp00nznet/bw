#pragma once
// GWaterfall — waterfall visual/audio effect object
// Struct layout from bw1-decomp
//
// Size: 0x58 bytes (inherits 0x54 from Object + 4 bytes)
// Simple methods at 0x0055dexx are packed 16 bytes apart.
// Complex methods at 0x007341xx-0x007346xx.

#include "Object.h"

struct GWaterfall : public Object {
    // === Overrides of Base virtuals ===
    void ToBeDeleted(int param) override;

    // === Overrides of GameThing virtuals ===
    char* GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;

    // === Overrides of Object virtuals ===
    void CallVirtualFunctionsForCreation(const MapCoords& coords) override;
    size_t SaveObject(LHOSFile* param1, const MapCoords* param2) override;

    // === Fields ===
    uint8_t field_0x54[0x4];  // 0x54
};
static_assert(sizeof(GWaterfall) == 0x58, "GWaterfall size mismatch");
