#pragma once
// HelpSystem — in-game help/tutorial management
// Struct layout from bw1-decomp (HelpSystem.h)
//
// Size: 0x4614 bytes (inherits Base)
// Manages help spirits, bubbles, text display, and scripted tutorials

#include "Base.h"

struct Bubble;
struct HelpSpirit;
struct HelpDudeControl;
struct GameThingWithPos;

enum HELP_SET_CATEGORY : uint32_t {
    HELP_SET_CATEGORY_0 = 0x0,
    _HELP_SET_CATEGORY_COUNT = 0x1
};

enum HELP_SYSTEM_MESSAGE_SET : uint32_t {
    HELP_SYSTEM_MESSAGE_SET_0 = 0x0,
    _HELP_SYSTEM_MESSAGE_SET_COUNT = 0x1
};

enum HELP_EVENT_TYPE : uint32_t {
    HELP_EVENT_TYPE_0 = 0x0,
    _HELP_EVENT_TYPE_COUNT = 0x1
};

struct HelpSystem : public Base {
    // No new virtual methods — only overrides Base dtor

    // === Fields ===
    HelpSpirit*      spirit_type_2;     // 0x08
    HelpSpirit*      spirit_type_1;     // 0x0C
    HelpDudeControl* help_dude_control; // 0x10
    uint32_t         help_text;         // 0x14
    Bubble*          bubble;            // 0x18
    uint32_t         field_0x1c;        // 0x1C
    uint32_t         field_0x20;        // 0x20
    uint32_t         icon0;             // 0x24
    uint32_t         icon1;             // 0x28
    uint32_t         icon2;             // 0x2C
    uint8_t          field_0x30[0x48];  // 0x30
    uint32_t         field_0x78[0x98];  // 0x78
    uint32_t         field_0x2d8[0x9];  // 0x2D8
    uint32_t         field_0x2fc[0x98]; // 0x2FC
    uint32_t         field_0x55c;       // 0x55C
    uint32_t         field_0x560;       // 0x560
    uint8_t          field_0x564;       // 0x564
    uint8_t          field_0x565;       // 0x565
    uint8_t          field_0x566;       // 0x566
    uint8_t          field_0x567;       // 0x567
    uint32_t         field_0x568;       // 0x568
    uint16_t         field_0x56c;       // 0x56C
    uint8_t          field_0x56e;       // 0x56E
    uint8_t          field_0x56f;       // 0x56F
    uint32_t         field_0x570;       // 0x570
    uint32_t         field_0x574;       // 0x574
    uint32_t         field_0x578;       // 0x578
    uint32_t         field_0x57c;       // 0x57C
    uint32_t         field_0x580;       // 0x580
    uint32_t         field_0x584[0x6];  // 0x584
    uint8_t          field_0x59c[0x4028]; // 0x59C
    uint32_t         field_0x45c4;      // 0x45C4
    uint32_t         field_0x45c8;      // 0x45C8
    uint32_t         field_0x45cc;      // 0x45CC
    uint32_t         field_0x45d0;      // 0x45D0
    uint8_t          field_0x45d4;      // 0x45D4
    uint8_t          field_0x45d5;      // 0x45D5
    uint8_t          field_0x45d6;      // 0x45D6
    uint8_t          field_0x45d7;      // 0x45D7
    uint32_t         field_0x45d8;      // 0x45D8
    uint32_t         field_0x45dc;      // 0x45DC
    uint32_t         field_0x45e0;      // 0x45E0
    uint32_t         field_0x45e4;      // 0x45E4
    int              field_0x45e8;      // 0x45E8
    int              field_0x45ec;      // 0x45EC
    float            field_0x45f0;      // 0x45F0
    int              field_0x45f4;      // 0x45F4
    int              field_0x45f8;      // 0x45F8
    uint32_t         field_0x45fc;      // 0x45FC
    uint8_t          field_0x4600;      // 0x4600
    uint8_t          field_0x4601;      // 0x4601
    uint8_t          field_0x4602;      // 0x4602
    uint8_t          field_0x4603;      // 0x4603
    uint8_t          field_0x4604;      // 0x4604
    uint8_t          field_0x4605;      // 0x4605
    uint8_t          field_0x4606;      // 0x4606
    uint8_t          field_0x4607;      // 0x4607
    uint32_t         field_0x4608;      // 0x4608
    uint32_t         field_0x460c;      // 0x460C
    uint8_t          field_0x4610;      // 0x4610
    uint8_t          field_0x4611;      // 0x4611
    uint8_t          field_0x4612;      // 0x4612
    uint8_t          field_0x4613;      // 0x4613
};
static_assert(sizeof(HelpSystem) == 0x4614, "HelpSystem size mismatch");
