#pragma once
// BWGameSpy — GameSpy network communication layer
// Struct layout from bw1-decomp (BWGameSpy.h)
//
// Size: 0x4 bytes (inherits LayerCommunication, no new fields)

#include "LayerCommunication.h"

struct BWGameSpy : public LayerCommunication {
    uint32_t Connect() override;
};
static_assert(sizeof(BWGameSpy) == 0x4, "BWGameSpy size mismatch");
