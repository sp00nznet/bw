#pragma once
// SetupHLineGraph — horizontal line graph widget (extends SetupButton)
// Also contains HLineData helper type
// Size: 0x258 bytes

#include "SetupButton.h"
#include "types.h"

struct HLineData {
    LH3DColor color;        // 0x0
    int       point_count;  // 0x4
    float*    points;       // 0x8
};
static_assert(sizeof(HLineData) == 0xC, "HLineData size mismatch");

struct LHLinkedList_HLineData {
    HLineData* first;
    HLineData* last;
};

struct SetupHLineGraph : public SetupButton {
    LHLinkedList_HLineData line_data_list;  // 0x244
    float                  max_point;       // 0x24C
    float                  min_point;       // 0x250
    bool                   percent_mode;    // 0x254
};
static_assert(sizeof(SetupHLineGraph) == 0x258, "SetupHLineGraph size mismatch");
