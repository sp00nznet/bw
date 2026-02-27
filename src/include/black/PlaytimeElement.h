#pragma once
#include "GameThing.h"

struct PlaytimeElement : public GameThing {
    void ToBeDeleted(int param) override;
    Town* GetTown() override;
    bool  IsFunctional() override;
};
static_assert(sizeof(PlaytimeElement) == 0x14, "PlaytimeElement size mismatch");
