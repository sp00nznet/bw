#pragma once
// GestureSystem — gesture recognition system
// Struct layout from bw1-decomp (GestureSystem.h)
//
// GestureSystem: 0xCA0 bytes (Base-derived, opaque body)
// GestureSystemPacketData: 0x1 byte (plain data)

#include "Base.h"

struct GestureSystem : Base {
    uint8_t field_0x8[0xC98];  // 0x08
};
static_assert(sizeof(GestureSystem) == 0xCA0, "GestureSystem size mismatch");

struct GestureSystemPacketData {
    uint8_t field_0x0;  // 0x0
};
static_assert(sizeof(GestureSystemPacketData) == 0x1, "GestureSystemPacketData size mismatch");
