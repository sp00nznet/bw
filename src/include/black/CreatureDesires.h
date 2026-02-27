#pragma once
// CreatureDesires — creature desire subsystem
// Struct layout from bw1-decomp (CreatureMentalDesire.h)
//
// Size: 0x708 bytes (inherits 0x8 from Base)
// Contains per-desire arrays and linked lists of CreatureDesireSource.

#include "Base.h"
#include "CreatureDesireSource.h"

struct Creature;
struct CreatureInfo;

struct CreatureDesires : public Base {
    uint32_t  field_0x8[0x28];                                // 0x08
    float     field_0xa8[0x28];                               // 0xA8
    uint32_t  field_0x148[0x28];                              // 0x148
    uint32_t  field_0x1e8[0x28];                              // 0x1E8
    uint32_t  field_0x288[0x28];                              // 0x288
    LHLinkedList_CreatureDesireSource source_lists[0x28];      // 0x328
    uint32_t  field_0x468[0x28];                              // 0x468
    uint32_t  field_0x508[0x28];                              // 0x508
    uint32_t  field_0x5a8[0x28];                              // 0x5A8
    Creature*     creature;                                    // 0x648
    CreatureInfo* creature_info;                               // 0x64C
    uint32_t  field_0x650;                                    // 0x650
    uint32_t  field_0x654;                                    // 0x654
    uint32_t  field_0x658[0x28];                              // 0x658
    uint32_t  field_0x6f8;                                    // 0x6F8
    uint32_t  field_0x6fc;                                    // 0x6FC
    uint32_t  field_0x700;                                    // 0x700
    uint32_t  field_0x704;                                    // 0x704
};
static_assert(sizeof(CreatureDesires) == 0x708, "CreatureDesires size mismatch");
