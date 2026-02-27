#pragma once
#include "GameThing.h"

struct ScriptedCamera;

struct DataPath : public GameThing {
    // === Overrides ===
    char*    GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;

    // === Fields ===
    ScriptedCamera* scripted_camera; // 0x14
    int32_t  track_no;               // 0x18
    float    field_0x1c;             // 0x1C
    uint32_t field_0x20;             // 0x20
    float    field_0x24;             // 0x24
    float    field_0x28;             // 0x28
    float    field_0x2c;             // 0x2C
};
static_assert(sizeof(DataPath) == 0x30, "DataPath size mismatch");
