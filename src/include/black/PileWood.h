#pragma once
#include "PileResource.h"

struct PileWood : public PileResource {
    // === Overrides of GameThing virtuals ===
    char* GetDebugText() override;
    uint32_t GetSaveType() override;

    // === Overrides of Object virtuals ===
    void Draw() override;
    RESOURCE_TYPE GetResourceType() override;
};
static_assert(sizeof(PileWood) == 0xB4, "PileWood size mismatch");
