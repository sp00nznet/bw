#pragma once
// WeatherInfo — weather configuration data
// Struct layout from bw1-decomp (WeatherInfo.h)
//
// Size: 0x64 bytes (extends GBaseInfo)
// Also defines GWeatherInfo (0x10)

#include "GBaseInfo.h"

struct WeatherInfo {
    GBaseInfo super;           // 0x00
    uint8_t   field_0x10[0x54]; // 0x10
};
static_assert(sizeof(WeatherInfo) == 0x64, "WeatherInfo size mismatch");

struct GWeatherInfo {
    GBaseInfo super;  // 0x0
};
static_assert(sizeof(GWeatherInfo) == 0x10, "GWeatherInfo size mismatch");
