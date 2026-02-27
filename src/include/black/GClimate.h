#pragma once
#include "GameThing.h"

struct GClimate : public GameThing {
    // === Overrides ===
    char*    GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;

    // === Fields ===
    uint8_t field_0x14[0x74];  // 0x14
};
static_assert(sizeof(GClimate) == 0x88, "GClimate size mismatch");
