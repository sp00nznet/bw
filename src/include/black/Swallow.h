#pragma once
// Swallow — swallow animal entity (Dove subclass)
// Struct layout from bw1-decomp (file: AnimalSwallow.h, struct: Swallow)

#include "Dove.h"

struct Swallow : public Dove {
    char* GetDebugText() override;
    uint32_t GetSaveType() override;
    uint32_t StandAnimation() override;
};
static_assert(sizeof(Swallow) == 0x148, "Swallow size mismatch");
