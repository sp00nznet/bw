#pragma once
// Pigeon — pigeon animal entity (Dove subclass)
// Struct layout from bw1-decomp (file: AnimalPigeon.h, struct: Pigeon)

#include "Dove.h"

struct Pigeon : public Dove {
    char* GetDebugText() override;
    uint32_t GetSaveType() override;
    uint32_t StandAnimation() override;
};
static_assert(sizeof(Pigeon) == 0x148, "Pigeon size mismatch");
