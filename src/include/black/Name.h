#pragma once
#include <cstdint>

struct Name {
    char string[0x20]; // 0x00
};
static_assert(sizeof(Name) == 0x20, "Name size mismatch");
