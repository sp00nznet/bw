#pragma once
// GFootpathNode — individual node along a footpath
// Struct layout from bw1-decomp
//
// Size: 0x30 bytes (inherits 0x14 from GameThing)

#include "GameThing.h"
#include "types.h"

// Lionhead linked list of Living (LHLinkedList<Living>)
struct LHLinkedList_Living {
    void*    head;   // 0x0
    uint32_t count;  // 0x4
};
static_assert(sizeof(LHLinkedList_Living) == 0x8, "LHLinkedList_Living size mismatch");

struct GFootpathNode : public GameThing {
    // === Overrides ===
    void ToBeDeleted(int param) override;
    char* GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;
    void ResolveLoad() override;

    // === Fields ===
    uint8_t              field_0x14;  // 0x14
    // 3 bytes padding
    MapCoords            coords;     // 0x18 — position on map
    GFootpathNode*       next;       // 0x24 — next node in path
    LHLinkedList_Living  followers;  // 0x28 — living entities following this node
};
static_assert(sizeof(GFootpathNode) == 0x30, "GFootpathNode size mismatch");
