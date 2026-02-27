#pragma once
#include <cstdint>

struct EarthQuake {
    uint8_t field_0x0;
};
static_assert(sizeof(EarthQuake) == 0x1, "EarthQuake size mismatch");
