#pragma once
// Pigeon — flying bird, derives from Dove
// Size: 0x148 bytes

#include "AnimalDove.h"

struct Pigeon : public Dove {
    virtual char*    GetDebugText() override { return nullptr; }
    virtual uint32_t GetSaveType() override { return 0; }
    virtual uint32_t StandAnimation() override { return 0; }
};
static_assert(sizeof(Pigeon) == 0x148, "Pigeon size mismatch");
