#pragma once
// CreatureExplorationMap — creature's explored area map
// Struct layout from bw1-decomp (CreatureExplorationMap.h)
//
// Size: 0x2018 bytes (inherits 0x8 from Base)
// Contains a 64x64 grid of uint16_t exploration data.
//
// Also defines CreatureExplorationRegionEntry (0x8)
// and CreatureGlobalExplorationMap (0x8).

#include "Base.h"
#include "types.h"

struct CreatureExplorationMap : public Base {
    uint32_t   field_0x8;              // 0x08
    MapCoords  coords;                 // 0x0C
    uint16_t   field_0x18[0x40][0x40]; // 0x18 — 64x64 exploration grid
};
static_assert(sizeof(CreatureExplorationMap) == 0x2018, "CreatureExplorationMap size mismatch");

struct CreatureExplorationRegionEntry : public Base {
};
static_assert(sizeof(CreatureExplorationRegionEntry) == 0x8, "CreatureExplorationRegionEntry size mismatch");

struct CreatureGlobalExplorationMap : public Base {
    void Dump() override;
};
static_assert(sizeof(CreatureGlobalExplorationMap) == 0x8, "CreatureGlobalExplorationMap size mismatch");
