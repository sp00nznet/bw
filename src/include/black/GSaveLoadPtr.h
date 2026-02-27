#pragma once
#include <cstdint>

struct GSaveLoadPtr {
    uintptr_t ptr;  // 0x00
};
static_assert(sizeof(GSaveLoadPtr) == 0x4, "GSaveLoadPtr size mismatch");
