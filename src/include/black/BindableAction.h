#pragma once
// BindableAction — keyboard/mouse binding system
// Struct layout from bw1-decomp (BindableAction.h)
//
// Types: BINDABLE_ACTIONS enum, CMouse (0x4), ControlKey (0x108),
//        ControlMouse (0x104), BindableAction (0x30C)

#include <cstdint>

// Forward declaration for key type
enum LH_KEY : uint32_t;

enum BINDABLE_ACTIONS : uint32_t {
    BINDABLE_ACTION_0x00 = 0x0,
    BINDABLE_ACTION_0x01 = 0x1,
    BINDABLE_ACTION_0x02 = 0x2,
    BINDABLE_ACTION_0x03 = 0x3,
    BINDABLE_ACTION_0x04 = 0x4,
    BINDABLE_ACTION_0x05 = 0x5,
    BINDABLE_ACTION_0x06 = 0x6,
    BINDABLE_ACTION_0x07 = 0x7,
    BINDABLE_ACTION_0x08 = 0x8,
    BINDABLE_ACTION_0x09 = 0x9,
    BINDABLE_ACTION_0x0a = 0xa,
    BINDABLE_ACTION_0x0b = 0xb,
    BINDABLE_ACTION_0x0c = 0xc,
    BINDABLE_ACTION_0x0d = 0xd,
    BINDABLE_ACTION_0x0e = 0xe,
    BINDABLE_ACTION_0x0f = 0xf,
    BINDABLE_ACTION_0x10 = 0x10,
    BINDABLE_ACTION_0x11 = 0x11,
    BINDABLE_ACTION_0x12 = 0x12,
    BINDABLE_ACTION_0x13 = 0x13,
    BINDABLE_ACTION_0x14 = 0x14,
    BINDABLE_ACTION_0x15 = 0x15,
    BINDABLE_ACTION_0x16 = 0x16,
    BINDABLE_ACTION_0x17 = 0x17,
    BINDABLE_ACTION_0x18 = 0x18,
    BINDABLE_ACTION_0x19 = 0x19,
    BINDABLE_ACTION_0x1a = 0x1a,
    BINDABLE_ACTION_0x1b = 0x1b,
    BINDABLE_ACTION_0x1c = 0x1c,
    BINDABLE_ACTION_0x1d = 0x1d,
    BINDABLE_ACTION_0x1e = 0x1e,
    BINDABLE_ACTION_0x1f = 0x1f,
    BINDABLE_ACTION_0x20 = 0x20,
    _BINDABLE_ACTION_SIZE = 0x21,
};

struct CMouse {
    uint32_t field_0x0;  // 0x0
};
static_assert(sizeof(CMouse) == 0x4, "CMouse size mismatch");

struct ControlKey {
    LH_KEY    key;                     // 0x00
    char16_t  key_display_text[0x40];  // 0x04
    LH_KEY    keymod;                  // 0x84
    char16_t  keymod_display_text[0x40]; // 0x88
};
static_assert(sizeof(ControlKey) == 0x108, "ControlKey size mismatch");

struct ControlMouse {
    uint32_t  code;                  // 0x00
    char16_t  display_text[0x80];    // 0x04
};
static_assert(sizeof(ControlMouse) == 0x104, "ControlMouse size mismatch");

struct BindableAction {
    char16_t      name[0x80];   // 0x000
    ControlKey    key;          // 0x100
    ControlMouse  mouse;        // 0x208
};
static_assert(sizeof(BindableAction) == 0x30C, "BindableAction size mismatch");
