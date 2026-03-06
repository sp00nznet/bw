#pragma once
// Tortoise — herbivore, derives from Cow
// Size: 0x148 bytes

#include "AnimalCow.h"

struct Tortoise : public Cow {
    virtual char*    GetDebugText() override { return nullptr; }
    virtual uint32_t GetSaveType() override { return 0; }
    virtual uint32_t StandAnimation() override { return 0; }
};
static_assert(sizeof(Tortoise) == 0x148, "Tortoise size mismatch");
