#pragma once
// Leopard — predator, derives from Lion
// Size: 0x148 bytes

#include "AnimalLion.h"

struct Leopard : public Lion {
    virtual char*    GetDebugText() override { return nullptr; }
    virtual uint32_t GetSaveType() override { return 0; }
    virtual uint32_t StandAnimation() override { return 0; }
};
static_assert(sizeof(Leopard) == 0x148, "Leopard size mismatch");
