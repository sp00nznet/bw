#pragma once
// Swallow — flying bird, derives from Dove
// Size: 0x148 bytes

#include "AnimalDove.h"

struct Swallow : public Dove {
    virtual char*    GetDebugText() override { return nullptr; }
    virtual uint32_t GetSaveType() override { return 0; }
    virtual uint32_t StandAnimation() override { return 0; }
};
static_assert(sizeof(Swallow) == 0x148, "Swallow size mismatch");
