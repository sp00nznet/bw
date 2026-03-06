#pragma once
// Sheep — herbivore, derives from Cow
// Size: 0x148 bytes

#include "AnimalCow.h"

struct Sheep : public Cow {
    virtual char*    GetDebugText() override { return nullptr; }
    virtual uint32_t GetSaveType() override { return 0; }
    virtual uint32_t StandAnimation() override { return 0; }
};
static_assert(sizeof(Sheep) == 0x148, "Sheep size mismatch");
