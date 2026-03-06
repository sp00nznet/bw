#pragma once
// SetupBox — base dialog box / UI container
// Struct layout from bw1-decomp
// Size: 0xCC bytes

#include <stdint.h>
#include "Zoomer.h"

struct SetupBox;
struct SetupControl;

struct SetupBoxVftable {
    void (__fastcall* field_0x0)(SetupBox* self, const void* edx, int param_1, int param_2);
};
static_assert(sizeof(SetupBoxVftable) == 0x4, "SetupBoxVftable size mismatch");

struct SetupBox {
    SetupBoxVftable* vftable;              // 0x00
    Zoomer         zoomer_0x4;             // 0x04
    Zoomer         zoomer_0x34;            // 0x34
    uint32_t       field_0x64;             // 0x64
    SetupControl*  widgets_0x68;           // 0x68
    SetupControl*  widget_list;            // 0x6C
    SetupControl*  focused_widget;         // 0x70
    SetupControl*  widget_0x74;            // 0x74
    uint8_t        field_0x78;             // 0x78
    uint32_t       field_0x7c;             // 0x7C
    uint32_t       field_0x80;             // 0x80
    float          field_0x84;             // 0x84
    uint32_t       field_0x88;             // 0x88
    uint32_t       field_0x8c;             // 0x8C
    uint32_t       field_0x90;             // 0x90
    uint32_t       field_0x94;             // 0x94
    uint32_t       field_0x98;             // 0x98
    uint32_t       field_0x9c;             // 0x9C
    uint32_t       field_0xa0;             // 0xA0
    uint32_t       field_0xa4;             // 0xA4
    uint32_t       field_0xa8;             // 0xA8
    uint32_t       default_text_size;      // 0xAC
    void (__stdcall* field_0xb0)(int, SetupBox*, SetupControl*, int, int);  // 0xB0
    uint32_t       field_0xb4;             // 0xB4
    uint32_t       field_0xb8;             // 0xB8
    SetupControl*  field_0xbc;             // 0xBC
    int            field_0xc0;             // 0xC0
    float          field_0xc4;             // 0xC4
    uint32_t       field_0xc8;             // 0xC8
};
static_assert(sizeof(SetupBox) == 0xCC, "SetupBox size mismatch");
