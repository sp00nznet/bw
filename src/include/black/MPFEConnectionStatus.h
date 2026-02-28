#pragma once
// MPFEConnectionStatus — multiplayer connection state
// Struct layout from bw1-decomp (MPFEConnectionStatus.h)
//
// Size: 0x4 bytes (plain data, no vtable)

#include <cstdint>

enum LOBBY_TYPE : uint32_t;

struct MPFEConnectionStatus {
    LOBBY_TYPE type;  // 0x00
};
static_assert(sizeof(MPFEConnectionStatus) == 0x4, "MPFEConnectionStatus size mismatch");
