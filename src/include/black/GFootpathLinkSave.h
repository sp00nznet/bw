#pragma once
// GFootpathLinkSave — serialization wrapper for footpath link state
// Struct layout from bw1-decomp
//
// Size: 0x24 bytes (inherits 0x14 from GameThing)

#include "GameThing.h"

// Forward declarations
struct GFootpathLink;

struct GFootpathLinkSave : public GameThing {
    // === Overrides ===
    char* GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;

    // === Fields ===
    GFootpathLink* link;    // 0x14 — the footpath link being saved
    MapCoords      coords;  // 0x18 — position
};
static_assert(sizeof(GFootpathLinkSave) == 0x24, "GFootpathLinkSave size mismatch");
