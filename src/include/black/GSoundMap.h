#pragma once
#include "Base.h"
#include "LHPoint.h"
#include "MapCoords.h"

struct GSoundMap : public Base {
    uint8_t   field_0x8[0xC * 0xE];   // 0x08  (168 bytes)
    uint16_t  field_0xb0;              // 0xB0
    uint32_t  field_0xb4[0xE];        // 0xB4
    LHPoint   field_0xec;             // 0xEC
    MapCoords field_0xf8;             // 0xF8
    uint8_t   field_0xfc[0x14];       // 0xFC  (aligned to 0x110)
};
static_assert(sizeof(GSoundMap) == 0x110, "GSoundMap size mismatch");
