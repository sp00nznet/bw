#pragma once
#include <cstdint>

struct Q27LH3DWay7Running;

struct ScriptedCamera {
    uint8_t*             data;      // 0x00
    Q27LH3DWay7Running*  field_0x4; // 0x04
    Q27LH3DWay7Running*  field_0x8; // 0x08
};
static_assert(sizeof(ScriptedCamera) == 0xC, "ScriptedCamera size mismatch");
