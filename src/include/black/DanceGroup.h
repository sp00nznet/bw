#pragma once
#include "GameThing.h"

enum DANCE_GROUP_ACTION_TYPE : uint32_t {
    DANCE_GROUP_ACTION_TYPE_0 = 0x0,
    _DANCE_GROUP_ACTION_TYPE_COUNT = 0x1
};

struct GroupBehaviour;

struct DanceGroup : public GameThing {
    // === Overrides ===
    char*    GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;

    // === Fields ===
    uint8_t         field_0x14[0x4];    // 0x14
    GroupBehaviour* behaviour;           // 0x18
    uint8_t         field_0x1c[0x40];   // 0x1C
    uint32_t        field_0x5c;         // 0x5C
    uint8_t         field_0x60[0x11C];  // 0x60
};
static_assert(sizeof(DanceGroup) == 0x17C, "DanceGroup size mismatch");
