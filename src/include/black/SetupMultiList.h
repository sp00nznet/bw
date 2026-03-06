#pragma once
// SetupMultiList — multi-select list box (extends SetupList)
// Size: 0x2BC bytes

#include "SetupList.h"

struct SetupMultiList : public SetupList {
    bool* list;          // 0x2B0
    int   field_0x2b4;   // 0x2B4
    int   size;          // 0x2B8
};
static_assert(sizeof(SetupMultiList) == 0x2BC, "SetupMultiList size mismatch");
