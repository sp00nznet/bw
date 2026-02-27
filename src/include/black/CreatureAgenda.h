#pragma once
// CreatureAgenda — creature action scheduling subsystem
// Struct layout from bw1-decomp (CreatureAgenda.h)
//
// Size: 0x1AF8 bytes (inherits 0x8 from Base)
// Contains embedded CreaturePlanState, plans, and sub-action state.
// Some embedded types use opaque byte arrays until their headers are created.

#include "Base.h"
#include "CreaturePlan.h"

struct Creature;
struct CreatureBelief;
struct CreatureInfo;

// CreatureSubActionAgenda (0xC50) — opaque until separate header created
// CreatureCommandState (0x2C) — opaque until separate header created
// CreatureMimicState (0x3C) — opaque until separate header created

struct CreatureAgenda : public Base {
    CreaturePlanState plan_state;           // 0x08
    CreaturePlan      plans[2];            // 0x838
    uint8_t           sub_action_agenda[0xC50]; // 0x898 — CreatureSubActionAgenda
    uint8_t           command_state[0x2C]; // 0x14E8 — CreatureCommandState
    Creature*         creature;            // 0x1514
    uint32_t          field_0x1518;        // 0x1518
    uint32_t          field_0x151c;        // 0x151C
    uint8_t           mimic_state[0x3C];   // 0x1520 — CreatureMimicState
    uint32_t          field_0x155c;        // 0x155C
    CreatureBelief*   belief;              // 0x1560
    uint32_t          field_0x1564;        // 0x1564
    uint32_t          field_0x1568;        // 0x1568
    uint32_t          field_0x156c;        // 0x156C
    uint32_t          field_0x1570;        // 0x1570
    uint32_t          field_0x1574;        // 0x1574
    uint32_t          field_0x1578;        // 0x1578
    uint32_t          field_0x157c;        // 0x157C
    uint32_t          field_0x1580;        // 0x1580
    uint32_t          field_0x1584;        // 0x1584
    uint32_t          field_0x1588;        // 0x1588
    uint8_t           field_0x158c[0x520]; // 0x158C
    uint32_t          field_0x1aac;        // 0x1AAC
    uint32_t          field_0x1ab0;        // 0x1AB0
    uint8_t           field_0x1ab4[0xC];   // 0x1AB4
    uint32_t          field_0x1ac0;        // 0x1AC0
    uint32_t          field_0x1ac4;        // 0x1AC4
    uint32_t          field_0x1ac8;        // 0x1AC8
    int32_t           field_0x1acc;        // 0x1ACC
    uint32_t          field_0x1ad0;        // 0x1AD0
    uint32_t          field_0x1ad4;        // 0x1AD4
    uint32_t          field_0x1ad8;        // 0x1AD8
    uint32_t          field_0x1adc;        // 0x1ADC
    uint32_t          field_0x1ae0;        // 0x1AE0
    uint32_t          field_0x1ae4;        // 0x1AE4
    uint32_t          field_0x1ae8;        // 0x1AE8
    uint32_t          field_0x1aec;        // 0x1AEC
    uint32_t          field_0x1af0;        // 0x1AF0
    uint32_t          field_0x1af4;        // 0x1AF4
};
static_assert(sizeof(CreatureAgenda) == 0x1AF8, "CreatureAgenda size mismatch");
