#pragma once
// LHInetWeather — internet weather data
// Struct layout from bw1-decomp
// Size: 0x4 bytes

#include <stdint.h>

struct LHInetWeather {
    uint32_t field_0x0;  // 0x00
};
static_assert(sizeof(LHInetWeather) == 0x4, "LHInetWeather size mismatch");
