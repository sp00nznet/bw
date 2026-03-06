#pragma once
// Crow — flying bird, derives from Dove
// Size: 0x148 bytes

#include "AnimalDove.h"

struct Crow : public Dove {
    virtual char*    GetDebugText() override { return nullptr; }
    virtual uint32_t GetSaveType() override { return 0; }
    virtual uint32_t StandAnimation() override { return 0; }
};
static_assert(sizeof(Crow) == 0x148, "Crow size mismatch");
