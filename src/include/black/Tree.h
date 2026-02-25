#pragma once
// Tree — tree entity in the game world
// Struct layout from bw1-decomp
//
// Size: 0x6C bytes (inherits 0x5C from SingleMapFixed)
// Vtable: 0x874 bytes (extends SingleMapFixed's 0x868 with 3 methods)

#include "SingleMapFixed.h"

// Forward declarations
struct Forest;

struct Tree : public SingleMapFixed {
    // === New virtual methods (vtable 0x868-0x870) ===
    virtual void GetWoodValueMultiplier();
    virtual Forest* GetForest();
    virtual void SetOnFire(float param1);

    // === Fields ===
    uint32_t field_0x5c;  // 0x5C
    int16_t  field_0x60;  // 0x60
    uint16_t pad_0x62;    // 0x62
    float    field_0x64;  // 0x64
    Forest*  forest;      // 0x68 — owning forest
};
static_assert(sizeof(Tree) == 0x6C, "Tree size mismatch");
