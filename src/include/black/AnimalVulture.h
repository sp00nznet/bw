#pragma once
// Vulture — flying predator bird, derives from Dove
// Size: 0x148 bytes

#include "AnimalDove.h"

struct Creature;

struct Vulture : public Dove {
    virtual char*    GetDebugText() override { return nullptr; }
    virtual uint32_t GetSaveType() override { return 0; }
    virtual bool32_t CanBeFrighteningToCreature(Creature*) override { return 1; }
};
static_assert(sizeof(Vulture) == 0x148, "Vulture size mismatch");
