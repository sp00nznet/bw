#pragma once
// Container — group/collection of game things (towns, flocks, forests)
// Struct layout from bw1-decomp
//
// Size: 0x30 bytes (inherits 0x28 from GameThingWithPos)
// Vtable: 0x500 bytes (same as GameThingWithPos — no new vtable slots)
//
// Container is a positioned entity that owns/manages a group of
// child objects. It adds an info pointer and player ownership.
// Base class for Town, Citadel, Flock, and Forest.

#include "GameThingWithPos.h"

// Forward declarations
struct GContainerInfo;

struct Container : public GameThingWithPos {
    // === Overrides of GameThing virtuals ===
    GPlayer* GetPlayer() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;

    // === Fields ===
    GContainerInfo* info;   // 0x28
    GPlayer*        owner;  // 0x2C
};
static_assert(sizeof(Container) == 0x30, "Container size mismatch");
