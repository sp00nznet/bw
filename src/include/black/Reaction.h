#pragma once
#include "GameThing.h"

enum REACTION : uint32_t;
struct GameThingWithPos;
struct GPlayer;

struct Reaction : public GameThing {
    // === Overrides ===
    char*    GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;

    // === Fields ===
    GameThingWithPos* target;    // 0x14
    uint32_t field_0x18;         // 0x18
    uint32_t field_0x1c;         // 0x1C
    uint32_t field_0x20;         // 0x20
    REACTION  type;              // 0x24
    uint32_t field_0x28;         // 0x28
    uint32_t field_0x2c;         // 0x2C
    uint32_t field_0x30;         // 0x30
    uint32_t field_0x34;         // 0x34
    GPlayer* player;             // 0x38
    float    field_0x3c;         // 0x3C
    Reaction* next;              // 0x40
};
static_assert(sizeof(Reaction) == 0x44, "Reaction size mismatch");
