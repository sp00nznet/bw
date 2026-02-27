#pragma once
#include "GameThing.h"

struct Object;

struct GMagicHand : public GameThing {
    // === Overrides ===
    char*    GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;

    // === Fields ===
    bool    has_object_in_hand;  // 0x14
    Object* object_in_hand;      // 0x18
};
static_assert(sizeof(GMagicHand) == 0x1C, "GMagicHand size mismatch");
