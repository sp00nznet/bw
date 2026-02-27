#pragma once
// HandState — hand interaction state machine
// Struct layout from bw1-decomp (HandState.h and HandState*.h)
//
// Size: 0x8 bytes (own vtable hierarchy, NOT Base-derived)
// Vtable: 5 entries (Enter, DrawTheHeldObject, Exit, Update, AllowCameraTricons)
//
// Also defines all 11 HandState subclasses:
//   HandStateInvisible (0x8), HandStateNormal (0x10), HandStateCamera (0xD8),
//   HandStateTug (0x14C), HandStateHolding (0x144), HandStateTotem (0xAC),
//   HandStateMultiPickUp (0x8), HandStateCreature (0x120), HandStateGrain (0x228),
//   HandStatePlayAnim (0x20), HandStateCitadel (0xD0)

#include <cstdint>

struct CHand;
struct LHMatrix;

// Hand state enumeration
enum HAND_STATES : uint32_t {
    HAND_STATE_INVISIBLE      = 0x0,
    HAND_STATE_NORMAL         = 0x1,
    HAND_STATE_CAMERA         = 0x2,
    HAND_STATE_TUG            = 0x3,
    HAND_STATE_HOLDING        = 0x4,
    HAND_STATE_TOTEM          = 0x5,
    HAND_STATE_MULTI_PICK_UP  = 0x6,
    HAND_STATE_CREATURE       = 0x7,
    HAND_STATE_GRAIN          = 0x8,
    HAND_STATE_PLAY_ANIM      = 0x9,
    HAND_STATE_CITADEL        = 0xA,
    _HAND_STATES_COUNT        = 0xB
};

struct HandState {
    virtual void Enter();                                  // vtable[0]
    virtual void DrawTheHeldObject();                      // vtable[1]
    virtual void Exit();                                   // vtable[2]
    virtual void Update(float param_1, LHMatrix* param_2); // vtable[3]
    virtual bool AllowCameraTricons();                     // vtable[4]

    CHand* hand;   // 0x04
};
static_assert(sizeof(HandState) == 0x8, "HandState size mismatch");

// --- Subclasses ---

struct HandStateInvisible : public HandState {
    void Enter() override;
    void Exit() override;
    void Update(float param_1, LHMatrix* param_2) override;
};
static_assert(sizeof(HandStateInvisible) == 0x8, "HandStateInvisible size mismatch");

struct HandStateNormal : public HandState {
    void Enter() override;
    void Update(float param_1, LHMatrix* param_2) override;

    uint32_t field_0x8;   // 0x08
    uint32_t field_0xc;   // 0x0C
};
static_assert(sizeof(HandStateNormal) == 0x10, "HandStateNormal size mismatch");

struct HandStateCamera : public HandState {
    void Enter() override;

    uint32_t field_0x8;          // 0x08
    uint8_t  field_0xc[0xCC];   // 0x0C
};
static_assert(sizeof(HandStateCamera) == 0xD8, "HandStateCamera size mismatch");

struct HandStateTug : public HandState {
    void Enter() override;
    void DrawTheHeldObject() override;
    void Update(float param_1, LHMatrix* param_2) override;

    uint32_t field_0x8;          // 0x08
    uint8_t  field_0xc[0x140];  // 0x0C
};
static_assert(sizeof(HandStateTug) == 0x14C, "HandStateTug size mismatch");

struct HandStateHolding : public HandState {
    uint32_t field_0x8;          // 0x08
    uint32_t field_0xc;          // 0x0C
    uint8_t  field_0x10[0x134]; // 0x10
};
static_assert(sizeof(HandStateHolding) == 0x144, "HandStateHolding size mismatch");

struct HandStateTotem : public HandState {
    void Enter() override;
    void Exit() override;
    void Update(float param_1, LHMatrix* param_2) override;

    uint8_t field_0x8[0xA4];   // 0x08
};
static_assert(sizeof(HandStateTotem) == 0xAC, "HandStateTotem size mismatch");

struct HandStateMultiPickUp : public HandState {
};
static_assert(sizeof(HandStateMultiPickUp) == 0x8, "HandStateMultiPickUp size mismatch");

struct HandStateCreature : public HandState {
    void Enter() override;

    uint8_t field_0x8[0x118];  // 0x08
};
static_assert(sizeof(HandStateCreature) == 0x120, "HandStateCreature size mismatch");

struct HandStateGrain : public HandStateHolding {
    uint8_t field_0x144[0xE4]; // 0x144
};
static_assert(sizeof(HandStateGrain) == 0x228, "HandStateGrain size mismatch");

struct HandStatePlayAnim : public HandState {
    void Enter() override;
    void Update(float param_1, LHMatrix* param_2) override;

    uint8_t  field_0x8[0x10];  // 0x08
    uint32_t field_0x18;       // 0x18
    uint32_t field_0x1c;       // 0x1C
};
static_assert(sizeof(HandStatePlayAnim) == 0x20, "HandStatePlayAnim size mismatch");

struct HandStateCitadel : public HandState {
    void Enter() override;
    void Update(float param_1, LHMatrix* param_2) override;

    uint32_t field_0x8;         // 0x08
    uint8_t  field_0xc[0xC4];  // 0x0C
};
static_assert(sizeof(HandStateCitadel) == 0xD0, "HandStateCitadel size mismatch");
