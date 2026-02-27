#pragma once
#include "GameThing.h"

struct LH_AudioBank;

struct GAudio : public GameThing {
    // === Overrides ===
    void     ToBeDeleted(int param) override;
    char*    GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;

    // === Fields ===
    uint8_t        field_0x14[0x394];     // 0x14
    LH_AudioBank*  audio_banks[0x2];      // 0x3A8
    uint8_t        field_0x3b0[0x24];     // 0x3B0
};
static_assert(sizeof(GAudio) == 0x3D4, "GAudio size mismatch");
