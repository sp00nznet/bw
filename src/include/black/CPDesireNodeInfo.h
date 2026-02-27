#pragma once
#include <cstdint>

enum PLAYER_TYPE : uint32_t {
    PLAYER_TYPE_0      = 0x0,
    _PLAYER_TYPE_COUNT = 0x1
};

// CPDesireNodeInfo — minimal own vtable (NOT Base-derived)
struct CPDesireNodeInfo {
    virtual int GetNumChildren();
};
static_assert(sizeof(CPDesireNodeInfo) == 0x4, "CPDesireNodeInfo size mismatch");
