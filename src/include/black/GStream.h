#pragma once
#include "GameThing.h"

struct GStream : public GameThing {
    // === Overrides ===
    char*    GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;

    // === Fields ===
    uint8_t field_0x14[0x14];  // 0x14
};
static_assert(sizeof(GStream) == 0x28, "GStream size mismatch");
