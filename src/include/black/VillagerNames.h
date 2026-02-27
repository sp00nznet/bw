#pragma once
#include "DrawingObject.h"
#include "types.h"

struct VillagerName;

struct VillagerNameBlock {
    uint8_t field_0x0[0x14]; // 0x00
};
static_assert(sizeof(VillagerNameBlock) == 0x14, "VillagerNameBlock size mismatch");

struct VillagerName : public DrawingObject {
    // === Overrides ===
    void AddDrawing() override;

    // === Fields ===
    float       left;            // 0x04
    float       top;             // 0x08
    float       right;           // 0x0C
    float       bottom;          // 0x10
    float       arrow_x;         // 0x14
    float       arrow_y;         // 0x18
    float       depth;           // 0x1C
    float       text_size;       // 0x20
    float       field_0x24;      // 0x24
    int         num_lines;       // 0x28
    float       text_padding;    // 0x2C
    char16_t    field_0x30[0x100];  // 0x30
    uint8_t     field_0x230[0x200]; // 0x230
    char16_t*   lines[0x8];      // 0x430
    LH3DColor   color;           // 0x450
    LHPoint     point;           // 0x454
    VillagerName* next;          // 0x460
};
static_assert(sizeof(VillagerName) == 0x464, "VillagerName size mismatch");
