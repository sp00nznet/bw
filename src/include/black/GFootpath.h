#pragma once
// GFootpath — footpath connecting buildings
// Struct layout from bw1-decomp
//
// Size: 0x24 bytes (inherits 0x14 from GameThing)

#include "GameThing.h"

// Forward declarations
struct GFootpathNode;

struct GFootpath : public GameThing {
    // === Overrides ===
    void ToBeDeleted(int param) override;
    char* GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;

    // === Fields ===
    GFootpathNode* nodes;      // 0x14 — linked list of path nodes
    int            node_count; // 0x18
    GFootpath*     next;       // 0x1C — linked list next
    uint32_t       field_0x20; // 0x20
};
static_assert(sizeof(GFootpath) == 0x24, "GFootpath size mismatch");
