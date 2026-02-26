#pragma once
// GMultiMapFixedInfo — info for multi-map-fixed objects (buildings, etc.)
// Struct layout from bw1-decomp
//
// Size: 0x120 bytes (extends GObjectInfo at 0x100)
// Extended vtable adds: IsOkToCreateAtPos, GetAbodeType, GetAbodeNumber

#include "ObjectInfo.h"

struct GMultiMapFixedInfo : public GObjectInfo {
    uint32_t editorMesh;              // 0x100 — MESH_LIST enum
    uint32_t woodRequiredPerBuild;    // 0x104
    uint32_t timeToBuild;             // 0x108
    uint32_t scaffoldsRequired;       // 0x10C
    uint32_t maxVillagerNeededToBuild; // 0x110
    float    desireToBeBuilt;         // 0x114
    float    desireToBeRepaired;      // 0x118
    float    influence;               // 0x11C
};
static_assert(sizeof(GMultiMapFixedInfo) == 0x120, "GMultiMapFixedInfo size mismatch");
