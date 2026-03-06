#pragma once
// SetupThing — global UI rendering utility (all static methods)
// Struct layout from bw1-decomp
// Size: 0xB8 bytes (singleton)

#include <stdint.h>
#include "types.h"
#include "SetupRect.h"
#include "GatheringText.h"

struct GatheringText;
struct LH3DMaterial;

enum BBSTYLE : uint32_t {
    BBSTYLE_CHECK_BOX_OFF = 0x0,
    BBSTYLE_CHECK_BOX_ON = 0x1,
    BBSTYLE_LEFT_ARROW = 0x2,
    BBSTYLE_RIGHT_ARROW = 0x3,
    BBSTYLE_ROTATION = 0x4,
    BBSTYLE_SPEECH = 0x5,
    BBSTYLE_NO_SPEECH = 0x6,
    BBSTYLE_SPEECH_ARROW = 0x7,
    BBSTYLE_EXCLAIM_ARROW = 0x8,
    BBSTYLE_ENVELOPE_ARROW = 0x9,
    BBSTYLE_ENVELOPE = 0xA,
    BBSTYLE_WEATHER_SUNNY = 0xB,
    BBSTYLE_WEATHER_PARTIALLY_CLOUDY = 0xC,
    BBSTYLE_WEATHER_CLOUDY = 0xD,
    BBSTYLE_WEATHER_SCATTERED_SHOWERS = 0xE,
    BBSTYLE_WEATHER_SHOWERS = 0xF,
    BBSTYLE_WEATHER_SCATTERED_FLURRIES = 0x10,
    BBSTYLE_WEATHER_FLURRIES = 0x11,
    BBSTYLE_WEATHER_HEAVY_FLURRIES = 0x12,
    BBSTYLE_WEATHER_THUNDER_STORMS = 0x13,
    BBSTYLE_0x14 = 0x14,
};

struct SetupThing {
    LH3DMaterial*  ui_shadow_material;  // 0x00
    uint8_t        field_0x4[0x34];     // 0x04
    SetupRect      rect;                // 0x38
    uint8_t        field_0x48[0x10];    // 0x48
    LH3DColor      colors[5];          // 0x58
    uint8_t        field_0x6c[0xC];     // 0x6C
    LH3DColor      color_0x78;         // 0x78
    uint8_t        field_0x7c[0x4];     // 0x7C
    uint32_t       active;              // 0x80
    uint8_t        field_0x84[0x18];    // 0x84
    uint8_t        setup_box;           // 0x9C
    uint8_t        field_0xa0[0xC];     // 0xA0
    GatheringText* gathering_text;      // 0xAC
    char16_t       wchar[4];            // 0xB0
};
static_assert(sizeof(SetupThing) == 0xB8, "SetupThing size mismatch");
