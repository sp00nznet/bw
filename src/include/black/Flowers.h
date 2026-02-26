#pragma once
// Flowers — decorative landscape flowers
// Struct layout from bw1-decomp
//
// Size: 0x7C bytes (same as Feature — no new fields)
// Vtable: uses MultiMapFixed's vtable layout

#include "Feature.h"

struct Flowers : public Feature {
    // === Overrides of GameThing virtuals ===
    char* GetDebugText() override;
    uint32_t GetSaveType() override;

    // === Overrides of Object virtuals ===
    void CallVirtualFunctionsForCreation(const MapCoords& coords) override;
    LH3DObject_ObjectType Get3DType() override;
    size_t SaveObject(LHOSFile* param1, const MapCoords* param2) override;
};
static_assert(sizeof(Flowers) == 0x7C, "Flowers size mismatch");
