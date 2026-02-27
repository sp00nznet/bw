#pragma once
#include "Base.h"

struct GGameInfo : public Base {
    uint8_t  field_0x8;           // 0x08
    uint8_t  field_0x9;           // 0x09
    uint8_t  field_0xa;           // 0x0A
    uint8_t  field_0xb;           // 0x0B
    int      time_scale;          // 0x0C
    float    elapsed_days;        // 0x10
    float    elapsed_years;       // 0x14
    float    seconds_per_day;     // 0x18
    uint32_t current_year;        // 0x1C
    double   elapsed_seconds_since_start; // 0x20
    int32_t  start_year;          // 0x28
    int32_t  start_month;         // 0x2C
    int32_t  start_day;           // 0x30
    int32_t  start_hour;          // 0x34
    int32_t  start_minute;        // 0x38
    int32_t  start_second;        // 0x3C
    uint32_t field_0x40;          // 0x40
    float    visual_time_scale;   // 0x44
    float    field_0x48;          // 0x48
    float    field_0x4c;          // 0x4C
    float    field_0x50;          // 0x50
    uint32_t field_0x54;          // 0x54
};
static_assert(sizeof(GGameInfo) == 0x58, "GGameInfo size mismatch");
