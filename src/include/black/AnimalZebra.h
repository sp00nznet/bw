#pragma once
// Zebra — herbivore, derives from Cow
// Size: 0x148 bytes

#include "AnimalCow.h"

struct Zebra : public Cow {
    virtual char*    GetDebugText() override { return nullptr; }
    virtual uint32_t GetSaveType() override { return 0; }
    virtual uint32_t StandAnimation() override { return 0; }
};
static_assert(sizeof(Zebra) == 0x148, "Zebra size mismatch");
