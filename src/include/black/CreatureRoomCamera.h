#pragma once
// CreatureRoomCamera — camera controller for the creature room
// Struct layout from bw1-decomp (CreatureRoomCamera.h)
//
// Size: 0x4C4 bytes (extends InnerCamera)

#include "InnerCamera.h"

struct CreatureRoomCamera : public InnerCamera {
    void Init(char* param_1) override;
    void Close() override;
    void Update(InnerRoom* room, float param_2, int param_3, int param_4, const LHCoord* coord, bool param_6) override;
    void UpdateMain(InnerRoom* room, float param_2, int param_3, int param_4, const LHCoord* coord, bool param_6) override;
    void UpdateState(InnerRoom* room, float param_2, int param_3, int param_4, const LHCoord* coord, bool param_6) override;

    // === Fields ===
    uint8_t field_0x46c[0x58];  // 0x46C
};
static_assert(sizeof(CreatureRoomCamera) == 0x4C4, "CreatureRoomCamera size mismatch");
