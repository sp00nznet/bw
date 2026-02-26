#pragma once
// AnimatedStatic — static map feature with animation
// Struct layout from bw1-decomp
//
// Size: 0x98 bytes (inherits 0x7C from Feature)
// Vtable: uses MultiMapFixed's vtable layout

#include "Feature.h"

struct AnimatedStatic : public Feature {
    // === Overrides of Base virtuals ===
    void ToBeDeleted(int param) override;

    // === Overrides of Object virtuals ===
    void CallVirtualFunctionsForCreation(const MapCoords& coords) override;
    size_t SaveObject(LHOSFile* param1, const MapCoords* param2) override;

    // === Fields ===
    uint8_t field_0x7c[0x1c];   // 0x7C — animation state data
};
static_assert(sizeof(AnimatedStatic) == 0x98, "AnimatedStatic size mismatch");
