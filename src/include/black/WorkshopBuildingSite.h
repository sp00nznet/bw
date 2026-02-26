#pragma once
// WorkshopBuildingSite — building site for workshop construction
// Struct layout from bw1-decomp
//
// Size: 0x644 bytes (same as BuildingSite, no added fields)
// Only overrides AddResource and RemoveResource.

#include "BuildingSite.h"

struct WorkshopBuildingSite : public BuildingSite {
    // === Overrides of GameThing virtuals ===
    uint32_t AddResource(RESOURCE_TYPE type, uint32_t amount, GInterfaceStatus* status, bool param4, const MapCoords& coords, int param6) override; // 0x0043db20
    uint32_t RemoveResource(RESOURCE_TYPE type, uint32_t amount, GInterfaceStatus* status, bool* param4) override; // 0x0043db60
};
static_assert(sizeof(WorkshopBuildingSite) == 0x644, "WorkshopBuildingSite size mismatch");
