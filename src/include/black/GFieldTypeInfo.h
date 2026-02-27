#pragma once
// GFieldTypeInfo — info for field crop types
// Struct layout from bw1-decomp (FieldTypeInfo.h)
//
// Size: 0x154 bytes (extends GMultiMapFixedInfo)

#include "GMultiMapFixedInfo.h"

struct GFieldTypeInfo : public GMultiMapFixedInfo {
    uint8_t field_0x120[0x34]; // 0x120
};
static_assert(sizeof(GFieldTypeInfo) == 0x154, "GFieldTypeInfo size mismatch");
