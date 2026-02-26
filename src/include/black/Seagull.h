#pragma once
// Seagull — seagull animal entity (Dove subclass)
// Struct layout from bw1-decomp (file: AnimalSeagull.h, struct: Seagull)

#include "Dove.h"

struct Seagull : public Dove {
    char* GetDebugText() override;
    uint32_t GetSaveType() override;
    uint32_t StandAnimation() override;
};
static_assert(sizeof(Seagull) == 0x148, "Seagull size mismatch");
