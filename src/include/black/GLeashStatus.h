#pragma once
#include "GameThing.h"

struct GInterfaceStatus;
struct GPlayer;

struct GLeashStatus : public GameThing {
    // === Overrides ===
    GPlayer* GetPlayer() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;

    // === Fields ===
    uint32_t field_0x14;                   // 0x14
    uint32_t field_0x18;                   // 0x18
    uint32_t field_0x1c;                   // 0x1C
    uint32_t field_0x20;                   // 0x20
    uint32_t field_0x24;                   // 0x24
    uint32_t field_0x28;                   // 0x28
    uint32_t field_0x2c;                   // 0x2C
    uint8_t  player_number;                // 0x30
    uint32_t field_0x34;                   // 0x34
    GInterfaceStatus* interface_status;    // 0x38
};
static_assert(sizeof(GLeashStatus) == 0x3C, "GLeashStatus size mismatch");
