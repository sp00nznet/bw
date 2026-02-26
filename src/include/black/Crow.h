#pragma once
// Crow — crow animal entity (Dove subclass)
// Struct layout from bw1-decomp (file: AnimalCrow.h, struct: Crow)

#include "Dove.h"

struct Crow : public Dove {
    char* GetDebugText() override;
    uint32_t GetSaveType() override;
    uint32_t StandAnimation() override;
};
static_assert(sizeof(Crow) == 0x148, "Crow size mismatch");
