#pragma once
// Furniture — interior/decorative furniture object
// Struct layout from bw1-decomp
//
// Size: 0x54 bytes (same as Object — no new fields)
// All methods at 0x0054a4xx are trivial (16 bytes apart).

#include "Object.h"

struct Furniture : public Object {
    // === Overrides of GameThing virtuals ===
    char* GetDebugText() override;
    uint32_t GetSaveType() override;

    // === Overrides of Object virtuals ===
    size_t SaveObject(LHOSFile* param1, const MapCoords* param2) override;
};
static_assert(sizeof(Furniture) == 0x54, "Furniture size mismatch");
