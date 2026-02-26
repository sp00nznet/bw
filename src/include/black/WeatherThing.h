#pragma once
// WeatherThing — weather effect entity
// Struct layout from bw1-decomp
//
// Size: 0x88 bytes (inherits 0x28 from GameThingWithPos)

#include "GameThingWithPos.h"

struct WeatherThing : public GameThingWithPos {
    // === Overrides of Base virtuals ===
    void ToBeDeleted(int param) override;

    // === Overrides of GameThing virtuals ===
    char* GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;

    // === Overrides of GameThingWithPos virtuals ===
    void SetPos(const MapCoords& coords) override;
    void SetSpeedInMetres(float speed, int scale) override;
    bool32_t IsWeather() const override;
    const char* GetText() override;
    uint32_t GetScriptObjectType() override;
    void SetAffectedByWind(int param1) override;

    // === Fields ===
    uint8_t field_0x28[0x60];  // 0x28
};
static_assert(sizeof(WeatherThing) == 0x88, "WeatherThing size mismatch");
