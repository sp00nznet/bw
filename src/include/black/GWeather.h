#pragma once
// GWeather — game weather system
// Struct layout from bw1-decomp (Weather.h)
//
// Size: 0x4 bytes (LH3DStorm-derived, empty body)
// Overrides: Update, DrawClouds, DebugDraw, CalcAtmos

#include "LH3DStorm.h"

struct GWeather : LH3DStorm {
    void Update(float param_1) override;
    void DrawClouds() override;
    void DebugDraw() override;
    void CalcAtmos(LHPoint* point, WeatherInfo* info) override;
};
static_assert(sizeof(GWeather) == 0x4, "GWeather size mismatch");
