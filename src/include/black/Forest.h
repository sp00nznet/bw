#pragma once
// Forest — collection of trees forming a footpath-linked forest
// Struct layout from bw1-decomp
//
// Size: 0x58 bytes (inherits 0x30 from Container)
// Vtable: 0x500 bytes (same as Container — no new vtable slots)
//
// Forest manages two linked lists of trees, provides footpath
// connections, and holds a forest ID for script references.

#include "Container.h"

// Forward declarations
struct GFootpath;
struct GFootpathLink;
struct Tree;

struct Forest : public Container {
    // === Overrides of Base virtuals ===
    void ToBeDeleted(int param) override;

    // === Overrides of GameThing virtuals ===
    bool IsFootpathLink() override;
    GFootpathLink* GetFootpathLink() override;
    uint32_t GetNearestPathTo(const MapCoords& coords, float param2, int param3) override;
    void UseFootpathIfNecessary(Living* living, const MapCoords* coords, uint8_t param3) override;
    uint32_t AddFootpath(GFootpath* footpath) override;
    uint32_t RemoveFootpath(GFootpath* footpath) override;
    bool IsFunctional() override;
    char* GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;

    // === Overrides of GameThingWithPos virtuals ===
    uint32_t GetCreatureBeliefType() override;
    uint32_t GetCreatureBeliefListType() override;
    bool IsActivityObjectWhichAngerAppliesTo(Creature* creature) override;
    bool32_t IsSuitableForCreatureActivity() override;
    const char* GetText() override;
    bool32_t IsForest() override;

    // === Non-virtual methods ===
    void AddTree(Tree* tree);
    Tree* GetForestCentreTree();

    // === Fields ===
    uint8_t   field_0x30[0x10];   // 0x30 — opaque data
    uint32_t  id;                 // 0x40
    Forest*   next;               // 0x44
    uint32_t  trees_0[2];        // 0x48 — LHLinkedList<Tree>
    uint32_t  trees_1[2];        // 0x50 — LHLinkedList<Tree>
};
static_assert(sizeof(Forest) == 0x58, "Forest size mismatch");
