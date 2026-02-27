#pragma once
#include "GameThing.h"

struct VortexSave : public GameThing {
    // === Overrides ===
    char*    GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;
};
static_assert(sizeof(VortexSave) == 0x14, "VortexSave size mismatch");
