#pragma once
// ValueSpinner — floating text value display
// Struct layout from bw1-decomp (ValueSpinner.h)
//
// Size: 0xA0 bytes (extends DrawingObject)
// Has own vtable: UpdatePosition + destructor

#include "DrawingObject.h"
#include "types.h"

struct ValueSpinner : public DrawingObject {
    virtual void UpdatePosition(float param_1);
    virtual ~ValueSpinner();

    // Note: AddDrawing() inherited from DrawingObject is overridden implicitly

    // === Fields ===
    ValueSpinner* next;       // 0x04
    LHPoint       point;      // 0x08
    uint32_t      field_0x14; // 0x14
    float         field_0x18; // 0x18
    uint32_t      color;      // 0x1C  (LH3DColor)
    char16_t      text[0x40]; // 0x20
};
static_assert(sizeof(ValueSpinner) == 0xA0, "ValueSpinner size mismatch");
