#pragma once
// SetupHSBarGraph — horizontal stacked bar graph (extends SetupVBarGraph)
// Size: 0x284 bytes (same as SetupVBarGraph)

#include "SetupVBarGraph.h"

struct SetupHSBarGraph : public SetupVBarGraph {
    // No new fields
};
static_assert(sizeof(SetupHSBarGraph) == 0x284, "SetupHSBarGraph size mismatch");
