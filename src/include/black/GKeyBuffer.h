#pragma once
#include "Base.h"

struct GKeyBuffer : public Base {
    uintptr_t field_0x8;      // 0x08
    uint8_t   field_0xc;      // 0x0C
    uint8_t   field_0xd;      // 0x0D
    uint16_t  buffered_keys;  // 0x0E
};
static_assert(sizeof(GKeyBuffer) == 0x10, "GKeyBuffer size mismatch");

struct GKeyInput : public Base {};
static_assert(sizeof(GKeyInput) == 0x8, "GKeyInput size mismatch");
