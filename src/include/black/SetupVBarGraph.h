#pragma once
// SetupVBarGraph — vertical bar graph widget (extends SetupButton)
// Also contains VBarData helper type
// Size: 0x284 bytes

#include "SetupButton.h"
#include "Zoomer.h"
#include "types.h"

struct VBarData {
    LH3DColor color;  // 0x0
    float     value;  // 0x4
};
static_assert(sizeof(VBarData) == 0x8, "VBarData size mismatch");

struct LHLinkedList_VBarData {
    VBarData* first;
    VBarData* last;
};

struct SetupVBarGraph : public SetupButton {
    Zoomer                zoomer;         // 0x244
    LHLinkedList_VBarData bar_data_list;  // 0x274
    float                 max_point;      // 0x27C
    float                 min_point;      // 0x280
};
static_assert(sizeof(SetupVBarGraph) == 0x284, "SetupVBarGraph size mismatch");
