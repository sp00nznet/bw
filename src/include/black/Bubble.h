#pragma once
#include <cstdint>

struct Bubble {
    uint8_t  field_0x0[0x1C];
    uint32_t field_0x1c;
    float    field_0x20[0xC];
    uint8_t  field_0x50[0x2C];
    uint32_t field_0x7c;
    uint32_t field_0x80;
    uint8_t  field_0x84[0x10];
    uint8_t  field_0x94;
    uint8_t  field_0x95;
    uint32_t field_0x98;
    uint32_t field_0x9c;
    uint32_t field_0xa0;
    uint32_t field_0xa4;
    uint32_t field_0xa8;
    uint32_t field_0xac;
};
static_assert(sizeof(Bubble) == 0xB0, "Bubble size mismatch");
