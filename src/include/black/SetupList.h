#pragma once
// SetupList — scrollable list box (extends SetupControl with extra vtable entry)
// Size: 0x2B0 bytes

#include "SetupControl.h"
#include "LHCoord.h"
#include "types.h"

struct SetupList;

struct SetupList_ListBoxDraw_t {
    uint32_t (__stdcall* function)(SetupList* widget, int value, int x_min, int y_min, int x_max, int y_max, int param_7, int style);
};
static_assert(sizeof(SetupList_ListBoxDraw_t) == 0x4, "SetupList_ListBoxDraw_t size mismatch");

struct SetupListVftable {
    SetupControlVftable super;
    bool (__fastcall* IsSelected)(SetupList* self, const void* edx, int index);
};
static_assert(sizeof(SetupListVftable) == 0x38, "SetupListVftable size mismatch");

struct SetupList : public SetupControl {
    bool                     field_0x23c;           // 0x23C
    int                      scrollback_width;      // 0x240
    bool                     field_0x244;           // 0x244
    int                      selected_index;        // 0x248
    int                      field_0x24c;           // 0x24C
    int                      num_items;             // 0x250
    int                      field_0x254;           // 0x254
    char16_t               (*item_labels)[0x100];   // 0x258
    int*                     item_heights;          // 0x25C
    uint32_t*                field_0x260;           // 0x260
    uint32_t*                field_0x264;           // 0x264
    LH3DColor*               color;                // 0x268
    SetupList_ListBoxDraw_t* ListBoxDraw;           // 0x26C
    int                      scroll_distance;       // 0x270
    bool                     show_scrollbar;        // 0x274
    int                      field_0x278;           // 0x278
    int                      scroll_position;       // 0x27C
    int                      field_0x280;           // 0x280
    bool                     field_0x284;           // 0x284
    bool                     field_0x285;           // 0x285
    LHCoord                  drag_start;            // 0x288
    bool                     use_color_background;  // 0x290
    bool                     draw_highlight_box;    // 0x291
    uint8_t                  field_0x292;           // 0x292
    uint8_t                  field_0x293;           // 0x293
    LH3DColor                box_outline_color;     // 0x294
    LH3DColor                selection_color;       // 0x298
    uint8_t                  field_0x29c;           // 0x29C
    uint8_t                  field_0x2a0[0x10];     // 0x2A0
};
static_assert(sizeof(SetupList) == 0x2B0, "SetupList size mismatch");
