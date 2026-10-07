#pragma once
// LandFeatures -- what kind of place each 8x8-cell block of the map is.
//
// v1.0 keeps one global CreatureGlobalExplorationMap (0xBAEFA0): 64 x 64
// CreatureExplorationRegionEntry records of 28 bytes, built once per level by
// sub_4C1610. Each holds its block's highest cell and a byte of feature bits,
// one per test in the table at 0xB0D7E0 (72-byte records: test, then refiner).
// The creature's actions ask it for the nearest block of a kind (sub_4C1480):
// water to sit by, a coast to drink at, a hill to climb.
//
// Built from the host's landscape: the cell flags (g_cell_flags_func) and
// altitude bytes (g_cell_altitude_func).

#include "types.h"

#include <cstdint>

namespace land {

enum Feature : uint32_t {  // the order of the table at 0xB0D7E0
    kCitadel, kTown, kField, kForest, kCoast, kWater, kHill, kLand,
    kNumFeatures,
};

struct Region {               // CreatureExplorationRegionEntry
    float     height = 0.0f;  // +8: of its highest cell, in metres
    MapCoords top;            // +12: that cell
    uint8_t   features = 0;   // +24: bit per Feature
};

struct FeatureMap {           // CreatureGlobalExplorationMap
    static constexpr int kBlocks = 64;  // of 8 x 8 cells
    Region regions[kBlocks][kBlocks];
    float  max_height = 0.0f;           // +114696

    void Build();  // sub_4C1610
    bool Has(Feature f, int bx, int bz) const;
    // sub_4C1480: spiral out from `from`'s block (4096 steps) to the nearest
    // block with `f`, skipping its own unless `own`, and set `out` to where in
    // it (the feature's refiner, else the block's centre cell). `first` takes
    // the first match even in a block the creature has explored.
    bool Find(Feature f, const MapCoords& from, MapCoords* out, bool first, bool own) const;
};

// The map for the landscape the host has loaded and the level's objects;
// built on first use. ponytail: built once -- call Features().Build() again
// after a new level (v1.0 rebuilds it at each level's load).
FeatureMap& Features();

}  // namespace land
