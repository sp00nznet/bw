#pragma once
// GroupBehaviour — dance/group behaviour system
// Struct layout from bw1-decomp (GroupBehaviour.h)
//
// Size: 0xE8 bytes (extends GameThingWithPos)
// 6 new virtual methods at end of vtable: Process, UpdateGroupBasedOnAction,
//   AddAction_0, AddAction_1, LoadDance, GetAngle
//
// Also defines: DanceEditState (0xE8), DanceKeyAction (0x14)

#include "GameThingWithPos.h"
#include "DancePathInfo.h"

// Forward declarations
struct DanceGroup;
struct DanceGroupActionArgument;
enum DANCE_GROUP_ACTION_TYPE : uint32_t;

struct GroupBehaviour : public GameThingWithPos {
    // New virtuals (NOT in base GameThingWithPos vtable)
    virtual void  Process();
    virtual void  UpdateGroupBasedOnAction(DanceGroup* group, DANCE_GROUP_ACTION_TYPE type, DanceGroupActionArgument* arg, uint32_t param_4);
    virtual void  AddAction_0(float param_1, void* stack, DANCE_GROUP_ACTION_TYPE type, DanceGroupActionArgument* arg);
    virtual void  AddAction_1(float param_1, uint32_t param_2, DANCE_GROUP_ACTION_TYPE type, DanceGroupActionArgument* arg);
    virtual void  LoadDance(const char* name);
    virtual float GetAngle();

    uint32_t      field_0x28;          // 0x28
    uint32_t      field_0x2c;          // 0x2C
    uint32_t      field_0x30;          // 0x30
    uint32_t      field_0x34;          // 0x34
    uint32_t      field_0x38;          // 0x38
    uint32_t      field_0x3c;          // 0x3C
    uint32_t      field_0x40;          // 0x40
    uint32_t      field_0x44;          // 0x44
    uint8_t       field_0x48[0x4];     // 0x48
    uint32_t      field_0x4c[0xA];     // 0x4C
    uint32_t      field_0x74;          // 0x74
    uint32_t      field_0x78;          // 0x78
    uint32_t      field_0x7c;          // 0x7C
    uint32_t      field_0x80;          // 0x80
    uint32_t      field_0x84;          // 0x84
    uint32_t      field_0x88;          // 0x88
    uint32_t      field_0x8c;          // 0x8C
    uint32_t      field_0x90;          // 0x90
    uint32_t      field_0x94;          // 0x94
    uint32_t      field_0x98;          // 0x98
    uint32_t      field_0x9c;          // 0x9C
    uint32_t      field_0xa0;          // 0xA0
    uint32_t      field_0xa4;          // 0xA4
    float         field_0xa8;          // 0xA8
    float         group_angle;         // 0xAC
    uint32_t      field_0xb0;          // 0xB0
    uint32_t      field_0xb4;          // 0xB4
    uint32_t      field_0xb8;          // 0xB8
    uint32_t      field_0xbc;          // 0xBC
    uint32_t      field_0xc0;          // 0xC0
    uint32_t      field_0xc4;          // 0xC4
    DancePathInfo dance_path_info;     // 0xC8
};
static_assert(sizeof(GroupBehaviour) == 0xE8, "GroupBehaviour size mismatch");

struct DanceEditState : public GroupBehaviour {
};
static_assert(sizeof(DanceEditState) == 0xE8, "DanceEditState size mismatch");

struct DanceKeyAction : public GameThing {
};
static_assert(sizeof(DanceKeyAction) == 0x14, "DanceKeyAction size mismatch");
