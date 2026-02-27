#pragma once
#include "GameThing.h"

struct GameStats : public GameThing {
    // === Overrides ===
    char*    GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;

    // === Fields ===
    uint8_t  field_0x14[0x94];    // 0x14
    uint32_t wood_used;           // 0xA8
    uint8_t  graph_0[0x1F4];     // 0xAC
    uint8_t  field_0x2a0[0x5E8]; // 0x2A0
    uint8_t  graph_1[0x1F4];     // 0x888
    uint8_t  field_0xa7c[0x6AC]; // 0xA7C
};
static_assert(sizeof(GameStats) == 0x1128, "GameStats size mismatch");
