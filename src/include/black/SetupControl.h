#pragma once
// SetupControl — base UI widget class with 13-entry vtable
// Struct layout from bw1-decomp
// Size: 0x23C bytes

#include <stdint.h>
#include "SetupRect.h"

enum LHKey : uint32_t;
enum LHKeyMod : uint32_t;

struct SetupBox;
struct SetupControl;

struct SetupControlVftable {
    void  (__fastcall* SetToolTipUl)(SetupControl* self, const void* edx, uint32_t tooltip_id);
    void  (__fastcall* SetToolTipPw)(SetupControl* self, const void* edx, const char16_t* tooltip);
    void  (__fastcall* Hide)(SetupControl* self, const void* edx, bool hidden);
    void  (__fastcall* SetFocus)(SetupControl* self, const void* edx, bool focus);
    bool  (__fastcall* HitTest)(SetupControl* self, const void* edx, int x, int y);
    void  (__fastcall* Draw)(SetupControl* self, const void* edx, bool hovered, bool selected);
    void  (__fastcall* Drag)(SetupControl* self, const void* edx, int x, int y);
    void  (__fastcall* MouseDown)(SetupControl* self, const void* edx, int x, int y, bool param);
    void  (__fastcall* MouseUp)(SetupControl* self, const void* edx, int x, int y, bool param);
    void  (__fastcall* Click)(SetupControl* self, const void* edx, int x, int y);
    void  (__fastcall* KeyDown)(SetupControl* self, const void* edx, LHKey key, LHKeyMod mod);
    void  (__fastcall* Char)(SetupControl* self, const void* edx, int character);
    void  (__fastcall* __dt)(SetupControl* self, const void* edx, bool param);
};
static_assert(sizeof(SetupControlVftable) == 0x34, "SetupControlVftable size mismatch");

struct SetupControl {
    const SetupControlVftable* vftable;   // 0x00
    uint32_t   field_0x4;                 // 0x04
    SetupRect  rect;                      // 0x08
    int        id;                        // 0x18
    int        field_0x1c;                // 0x1C
    int        text_size;                 // 0x20
    char16_t   label[0x100];              // 0x24
    const char16_t* tooltip;              // 0x224
    bool       focus;                     // 0x228
    bool       hidden;                    // 0x229
    bool       field_0x22a;               // 0x22A
    bool       field_0x22b;               // 0x22B
    uint32_t   field_0x22c;               // 0x22C
    SetupControl* next;                   // 0x230
    SetupBox*  setup_box;                 // 0x234
    void*      continue_button_callback;  // 0x238
};
static_assert(sizeof(SetupControl) == 0x23C, "SetupControl size mismatch");
