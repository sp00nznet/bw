#pragma once
#include "DeadTree.h"

struct FelledTree : public DeadTree {
    // === Overrides ===
    char*    GetDebugText() override;
    uint32_t GetSaveType() override;
};
static_assert(sizeof(FelledTree) == 0xA0, "FelledTree size mismatch");
