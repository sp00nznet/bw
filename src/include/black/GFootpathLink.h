#pragma once
// GFootpathLink — manages footpath connections for a building
// Struct layout from bw1-decomp
//
// Size: 0x1C bytes (inherits 0x14 from GameThing)

#include "GameThing.h"

// Lionhead linked list of GFootpath (LHLinkedList<GFootpath>)
struct LHLinkedList_GFootpath {
    void*    head;   // 0x0
    uint32_t count;  // 0x4
};
static_assert(sizeof(LHLinkedList_GFootpath) == 0x8, "LHLinkedList_GFootpath size mismatch");

struct GFootpathLink : public GameThing {
    // === Overrides ===
    void ToBeDeleted(int param) override;
    uint32_t AddFootpath(GFootpath* footpath) override;
    uint32_t RemoveFootpath(GFootpath* footpath) override;
    char* GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;

    // === Fields ===
    LHLinkedList_GFootpath footpath_list; // 0x14 — connected footpaths
};
static_assert(sizeof(GFootpathLink) == 0x1C, "GFootpathLink size mismatch");
