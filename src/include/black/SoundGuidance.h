#pragma once
// GGuidance — sound guidance system
// Struct layout from bw1-decomp (SoundGuidance.h)
//
// Size: 0xEC bytes
// Inheritance: Base (0x8) → GGuidance (0xEC)
// Also defines Q29GGuidance10LastThings helper struct

#include "Base.h"

struct GameThingWithPos;
struct GInterfaceStatus;
struct LH_SamplePlayOptions;

// GGuidance::LastThings — cached reference to recently looked-at things
struct GGuidanceLastThings {
    GameThingWithPos* thing;  // 0x00
    uint32_t          turn;   // 0x04
};
static_assert(sizeof(GGuidanceLastThings) == 0x8, "GGuidanceLastThings size mismatch");

struct LHLinkedList_GGuidanceLastThings {
    GGuidanceLastThings* first;
    GGuidanceLastThings* last;
};
static_assert(sizeof(LHLinkedList_GGuidanceLastThings) == 0x8, "LHLinkedList_GGuidanceLastThings size mismatch");

struct GGuidance : Base {
    LH_SamplePlayOptions*          play_options;     // 0x08
    int                            field_0xc[0x21];  // 0x0C
    LHLinkedList_GGuidanceLastThings lastThings;     // 0x90
    uint32_t                       field_0x98;       // 0x98
    uint32_t                       field_0x9c;       // 0x9C
    uint32_t                       field_0xa0;       // 0xA0
    uint32_t                       field_0xa4;       // 0xA4
    float                          field_0xa8;       // 0xA8
    uint32_t                       field_0xac;       // 0xAC
    uint32_t                       field_0xb0;       // 0xB0
    uint32_t                       field_0xb4;       // 0xB4
    uint32_t                       field_0xb8;       // 0xB8
    uint32_t                       field_0xbc;       // 0xBC
    uint32_t                       field_0xc0;       // 0xC0
    uint32_t                       field_0xc4;       // 0xC4
    uint32_t                       field_0xc8;       // 0xC8
    GInterfaceStatus*              interface_status;  // 0xCC
    uint32_t                       field_0xd0[0x7];  // 0xD0
};
static_assert(sizeof(GGuidance) == 0xEC, "GGuidance size mismatch");
