#pragma once
// Seagull — flying bird, derives from Dove
// Size: 0x148 bytes

#include "AnimalDove.h"

struct Seagull : public Dove {
    virtual char*    GetDebugText() override { return nullptr; }
    virtual uint32_t GetSaveType() override { return 0; }
    virtual uint32_t StandAnimation() override { return 0; }
};
static_assert(sizeof(Seagull) == 0x148, "Seagull size mismatch");
