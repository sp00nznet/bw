#pragma once
// Tiger — predator, derives from Lion
// Size: 0x148 bytes

#include "AnimalLion.h"

struct Tiger : public Lion {
    virtual char*    GetDebugText() override { return nullptr; }
    virtual uint32_t GetSaveType() override { return 0; }
    virtual uint32_t StandAnimation() override { return 0; }
};
static_assert(sizeof(Tiger) == 0x148, "Tiger size mismatch");
