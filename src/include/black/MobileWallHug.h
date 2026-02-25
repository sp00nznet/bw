#pragma once
// MobileWallHug — mobile object with wall-hugging pathfinding
// Struct layout from bw1-decomp
//
// Size: 0x8C bytes (inherits 0x58 from Mobile)
// Vtable: 0x874 bytes (extends Mobile's 0x85C with 6 new methods)

#include "Mobile.h"

// Movement state machine states
enum MOVE_TO_STATES : uint8_t {
    MOVE_TO_STATES_ARRIVED             = 0x0,
    MOVE_TO_STATES_FINAL_STEP          = 0x1,
    MOVE_TO_STATES_LINEAR              = 0x2,
    MOVE_TO_STATES_WALL_FOLLOW_LEFT    = 0x3,
    MOVE_TO_STATES_WALL_FOLLOW_RIGHT   = 0x4,
    MOVE_TO_STATES_EXIT_CIRCLE         = 0x5,
    MOVE_TO_STATES_COMPLETE_CIRCLE     = 0x6,
    MOVE_TO_STATES_USE_FOOTPATH        = 0x7,
    MOVE_TO_STATES_STATE_8             = 0x8,
    MOVE_TO_STATES_STATE_9             = 0x9,
    MOVE_TO_STATES_WAIT_SPACE          = 0xA,
    MOVE_TO_STATES_STUCK               = 0xB,
    MOVE_TO_STATES_STATE_C             = 0xC,
    MOVE_TO_STATES_STATE_D             = 0xD,
    MOVE_TO_STATES_STATE_E             = 0xE,
    MOVE_TO_STATES_STATE_F             = 0xF,
    MOVE_TO_STATES_STATE_10            = 0x10,
    MOVE_TO_STATES_STATE_11            = 0x11,
    MOVE_TO_STATES_STATE_12            = 0x12,
    MOVE_TO_STATES_STATE_13            = 0x13,
};

// Step vector for movement
struct GMoveBy {
    float x;
    float altitude;
    float z;
};
static_assert(sizeof(GMoveBy) == 0xC, "GMoveBy size mismatch");

// Circle hug pathfinding state
struct CircleHugInfo {
    float field_0x0;
    float field_0x4;
};
static_assert(sizeof(CircleHugInfo) == 0x8, "CircleHugInfo size mismatch");

struct MobileWallHug : public Mobile {
    // === New virtual methods (vtable 0x85C-0x870) ===
    virtual bool AreWeThere(const MapCoords& target, float tolerance);
    virtual MapCoords* GetDestPos();
    virtual void SetSpeed(int speed);
    virtual void SetTowardsAngle(uint16_t angle);
    virtual void MoveTo3D();
    virtual void SetNewWander(const MapCoords& target, int param2, int param3);

    // === Fields ===
    int16_t  turns_until_next_state_change; // 0x58
    uint16_t speed;                         // 0x5A
    uint16_t game_angle;                    // 0x5C
    uint8_t  move_state;                    // 0x5E — MOVE_TO_STATES enum
    uint8_t  pad_0x5f;                      // 0x5F
    Object*  target;                        // 0x60 — movement target object
    GMoveBy  step;                          // 0x64 — current step vector
    CircleHugInfo circle_hug_info;          // 0x70
    int8_t   field_0x78;                    // 0x78
    uint8_t  pad_0x79[3];                   // 0x79-0x7B — padding
    GFootpath* footpath;                    // 0x7C
    MapCoords goal;                         // 0x80 — destination position
};
static_assert(sizeof(MobileWallHug) == 0x8C, "MobileWallHug size mismatch");
